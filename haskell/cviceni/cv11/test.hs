-- TEST CV 1.

-- 1
data Company = Company {name :: String, employees :: Int, ownerOf :: [Company]} deriving (Show)
companytest :: Company
companytest = Company "Nestle" 2500 [Company "Nescafe" 2300 []]

-- 2
data Entity = Point {x :: Double, y :: Double} 
            | Circle {x :: Double, y :: Double, r :: Int} 
            | Container [Entity] deriving (Show)
entitytest :: Entity
entitytest = Container [Point 4.0 3.1, Circle {x = 1.0, y = 2.0, r = 5}]

-- 3
data Typ = Int | Char | String deriving (Show)
data Table = Sloupec {jmenoSloupce :: String, typ_sloupce :: Typ} 
            | Tables [Table] deriving (Show)
tabletest :: Table
tabletest = Tables [Sloupec "StringSloupec" String, Sloupec "CharSloupec" Char, Sloupec "IntSloupec" Int]

-- 4 
data TernaryTree a = Leaf a
                    | Branch (TernaryTree a) (TernaryTree a) (TernaryTree a) deriving (Show)
ternaryTree :: TernaryTree Integer
ternaryTree = Branch (Leaf 3) (Leaf 4) (Branch (Leaf 6) (Leaf 7) (Leaf 8))

--4/2
data Article = Text { text :: String } 
            | Chapter { name' :: String, value' :: [Article] } deriving (Show)
myArticle :: Article
myArticle = Chapter { name' = "Kapitola", value' = [ Text { text = "NejakyText." } ] }

-- 5
data HTML = Attribute {name1 :: String, value :: String} 
          | Tag {name2 :: String, list :: [HTML], list2 :: [HTML]}
          | HTMLDocument [HTML] deriving (Show)
myHTMLDocument :: HTML
myHTMLDocument = HTMLDocument [Tag {name2 = "body", list = [Attribute {name1 = "styl=", value = "zlutytext;"}, Attribute {name1 = "jazyk=", value = "cz"}], list2 = []}]

-- TEST CV 2.

data FileType = Image | Executable | SourceCode | TextFile deriving (Eq, Show)
data Entry = File {nam :: String, size :: Int, ftype :: FileType}
           | Directory {nam :: String, entries :: [Entry]} deriving (Eq, Show)

root :: Entry
root = Directory "root"
    [
    File "logo.jpg" 5000 Image,
    Directory "classes"
        [
        File "notes-fpr.txt" 200 TextFile,
        File "presentation.jpg" 150 Image,
        File "first_test.hs" 20 SourceCode
        ]
    ]

-- 1
countFiles :: Num a => Entry -> a
countFiles (File {}) = 1
countFiles (Directory _ entries) = sum $ map countFiles entries

-- 2
countImages :: Num a => Entry -> a
countImages (File _ _ Image) = 1
countImages (File {}) = 0
countImages (Directory _ entries) = sum $ map countImages entries

-- 3
countDirectories :: Num a => Entry -> a
countDirectories (File {}) = 0
countDirectories (Directory _ entries) = sum (map countDirectories entries) + 1
 

-- 4
countEmptyDirectories :: Num a => Entry -> a
countEmptyDirectories (Directory _ []) = 1
countEmptyDirectories (File {}) = 0
countEmptyDirectories (Directory _ entries) = sum $ map countEmptyDirectories entries

-- 5
countSize :: Entry -> Int
countSize (File _ size _) = size
countSize (Directory _ files) = sum (map countSize files)

-- 6
countLargerFiles :: Num a => Int -> Entry -> a
countLargerFiles x (File _ size _) = if size > x then 1 else 0
countLargerFiles x (Directory _ entries) = sum (map (countLargerFiles x) entries)

-- TEST CV 3.

-- 1
fullNames :: Entry -> [String]
fullNames entry = getNames [entry] ""
  where
    getPath p1 p2 = p1 ++ "/" ++ p2
    getNames [] _ = []
    getNames ((File name _ _) : es) path = getPath path name : getNames es path
    getNames ((Directory name files) : es) path = getNames files (getPath path name) ++ getNames es path

-- 2
filterImage :: Entry -> Entry
filterImage (File nam size ftype)
    | ftype == Image = File "" 0 TextFile 
    | otherwise = File nam size ftype
filterImage (Directory nam entries) =
    Directory nam [filterImage e | e <- entries, not (isImage e)]


isImage :: Entry -> Bool
isImage (File _ _ Image) = True
isImage _ = False

-- 3
getFiles :: Entry -> String -> [String]
getFiles (File nam _ _) ext
    | getExtension nam == ext = [nam]
    | otherwise = []
getFiles (Directory _ entries) ext = concatMap (`getFiles` ext) entries 

getExtension :: String -> String
getExtension name = reverse (takeWhile (/= '.') (reverse name))

-- 4
directorySizes :: Entry -> [(String, Int)]
directorySizes File {} = []
directorySizes (Directory name files) = (name, sum [countSize x | x <- files]) : concat [directorySizes x | x <- files]

-- 5
check :: String -> [Entry] -> [Entry]
check _ [] = []
check str ((Directory name files):xs) = Directory name files : check str xs
check str ((File name size ftype):xs) | name == str = check str xs
                                      | otherwise = File name size ftype : check str xs

removeFile :: String -> Entry -> Entry
removeFile str (File name size ftype) = File name size ftype
removeFile str (Directory name files) = Directory name (check str [removeFile str x | x <- files]);