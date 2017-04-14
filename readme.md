# store.h

A single header library file that allows you to buffer variables to the disk.
This might be useful for saving state or preferences between sessions. 
All saved data is raw. There are no guarentees that a loaded pointer will be valid. 
Use it for variables and static arrays, not linked lists, graphs, etc.

Basic macros:
SAVE(x), LOAD(x)

We can also export/import our variables in a batch. Add them to the registry using:
REG(x), 

and save/load using:
saveAll(), loadAll()

Look at main.cpp for a demonstration.


