{-
Editor: Trevor Stalnaker
File: MyRandom.hs
Assignment: Project 4


Purpose: For random integers using a monad.
Addapted from Thompson's book on Haskell, third edition, page 464.
-}

module MyRandom where

import Data.Time.Clock
import Data.Time.Format

-- Monadic function returns a random number between 0 and n - 1, inclusive.
randomInt :: Int -> IO Int
randomInt n = do
    time <- getCurrentTime
    return ((`rem` n) $ read $ take 6 $ 
                      formatTime defaultTimeLocale "%q" time)
              
-- Returns a random item from a list.
pickRandom :: [a] -> IO a
pickRandom list = do
    index <- randomInt (length list)
    return (list !! index)

-- Returns a boolean value given a percentage
probability :: Float -> IO Bool
probability probFactor = do
    let probRange = round (100 * probFactor)
    randomValue <- randomInt 100
    return (randomValue > 100 - probRange)

-- Prints random integers between 0 and n - 1, for
-- a given number of iterations.
testRandomInt :: Int -> Int -> IO ()
testRandomInt n iterations = do
    if iterations == 0 then
        return ()
    else do
        r <- randomInt n
        putStrLn (show r)
        testRandomInt n (iterations -1)

