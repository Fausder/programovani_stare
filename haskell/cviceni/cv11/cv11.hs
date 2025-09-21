data Point = Point {column::Int,row::Int}

data Position = Position {leftTopCorner :: Point, width :: Int, height :: Int}

data Component
  = TextBox {name :: String, position :: Position, text :: String}
  | Button {name :: String, position :: Position, text :: String}
  | Container {name :: String, children :: [Component]}

gui :: Component
gui =
  Container "My App"
    [ Container "Menu"
        [ Button "btn_new" (Position (Point 0 0) 100 20) "New",
          Button "btn_open" (Position (Point 100 0) 100 20) "Open",
          Button "btn_close" (Position (Point 200 0) 100 20) "Close"
        ],
      Container "Body" [TextBox "textbox_1" (Position (Point 0 20) 300 500) "Some text goes here"],
      Container "Footer" []
    ]

instance Show Point where
    show :: Point -> String
    show (Point x y) = "("++ show x ++ "," ++ show y ++")"

instance Show Position where
    show Position {leftTopCorner=p, width=w,height=h} = show p ++ "[" ++show w++","++show w++"]"

instance Show Component where
    show :: Component -> String
    show c = show' " " c
      where
        show' indent (TextBox name pos text) = show pos ++ " TextBox[" ++ name ++ "]: " ++ text
        show' indent Button {name = n, position = p, text = t} =
            show p ++ " Button[" ++ n ++ "]: " ++ t
        show' indent (Container name childs) =
            indent ++ "Container - " ++ name ++ concat ["\n" ++ show' (indent ++ "  ") c | c <- childs]

insertInto (Container cname childs) targetName newComponent
  | cname == targetName = Container cname (childs ++ [newComponent])
  | otherwise = Container cname [insertInto c targetName newComponent | c <- childs]

deleteFrom :: Component -> String -> Component
deleteFrom (Container cname children) targetName =
    Container cname (filterOut [deleteFrom c targetName | c <- children])
  where
    filterOut :: [Component] -> [Component]
    filterOut [] = []
    filterOut (c:xs)
        | name c == targetName = filterOut xs
        | otherwise = c : filterOut xs
deleteFrom c _ = c

--deleteFrom (Container x child) target = Container x [deleteFrom c target |c<-child, name c /=target ]
--deleteFrom c _ = c