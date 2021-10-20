bondia :: String
bondia = "Hello World!"

newReverse :: [Int] -> [Int]
newReverse [] = [] 
newReverse (x:xs) = (newReverse xs) ++ [x] 

elemNum :: Int -> [Int] -> Int
elemNum x [] = 0
elemNum x (y:ys)
        | x == y = elemNum x ys + 1
        | otherwise = elemNum x ys