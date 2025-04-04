# SAVES PART

## SAVES FORMAT

Directory save name : Name of the part or seed
Map will be chunked by 64*64 tiles blocks, and the game will only load that so it stocks 
    -> a hashmap with everything that are not generated yet
    -> a more precise map of the rest that has been generated (in case of modifications)
Player statistiques