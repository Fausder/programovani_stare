data Company = Company {name :: String, employees :: Int, ownerOf :: [Company]} deriving Show

companytest :: Company
companytest = Company "Ananas" 2500 [Company "Jablko" 2300 []]
