{-
Name: Daniel Han
Description: Generates randomized sentences given a set of nouns, verbs, articles,
conjunctions, prepositions, and adjectives, uses "MyRandom" by Trevor Stalnaker to
get a random number.
-}
module Generator where

import MyRandom(randomInt, pickRandom, probability)

nouns :: [String]
nouns = ["boy", "girl", "dog", "cat", "table", "chair", "cake"]

verbs :: [String]
verbs = ["hit", "threw", "pushed", "jumped", "ate", "spun"]

articles :: [String]
articles = ["a", "the"]

conjunctions :: [String]
conjunctions = ["for", "and", "nor", "but", "or", "yet", "so"]

prepositions :: [String]
prepositions = ["with", "to", "from", "on", "below", "above", "beside"]

adjectives :: [String]
adjectives = ["big", "small", "short", "tall", "red", "blue", "yellow", "green"]

--adjective_phrase → adjective [ adjective_phrase ]
adjective_phrase :: IO String
adjective_phrase = do
    adj <- pickRandom adjectives
    prob <- probability 0.25
    if prob then do
        phrase <- adjective_phrase
        return (adj ++ " " ++ phrase)
    else do
        return adj

--prepositional_phrase → preposition noun_ phrase
prepositional_phrase :: IO String
prepositional_phrase = do
    prep <- pickRandom prepositions
    phrase <- noun_phrase
    return (prep ++ " " ++ phrase)

--verb_phrase → verb noun_phrase prepositional_phrase
verb_phrase :: IO String
verb_phrase = do
    ver <- pickRandom verbs
    nounphrase <- noun_phrase
    prepphrase <- prepositional_phrase
    return (ver ++ " " ++ nounphrase ++ " " ++ prepphrase)

--noun_phrase → article [ adjective_phrase ] noun
noun_phrase :: IO String
noun_phrase = do
    noun <- pickRandom nouns
    art <- pickRandom articles
    prob <- probability 0.25
    if prob then do
        phrase <- adjective_phrase
        return (art ++ " " ++ phrase ++ " " ++ noun)
    else do
        return (art ++ " " ++ noun)

--sentence → noun_phrase verb_phrase [ , conjunction sentence ]
sentence :: IO String
sentence = do
    prob <- probability 0.25
    nounphrase <- noun_phrase
    verbphrase <- verb_phrase
    if prob then do
        conjunc <- pickRandom conjunctions
        sentencephrase <- sentence
        return (nounphrase ++ " " ++ verbphrase ++ ", " ++ conjunc ++ " " ++ sentencephrase)
    else do
        return (nounphrase ++ " " ++ verbphrase)
