# Game-of-Life
yet another implementation of conway's game of life in C.\
This version uses SDL2 to render the field.\
Minimalism was in mind, hence the absence of an on-screen menu.

## Controls
f: iterate faster\
s: iterate slower\
p: pause\
i: iterate once (do a single step while paused)\
d: dump field state (create state_dump.gol)\
r: randomize field\
1: change field population density to LOW\
2: change field population density to MEDIUM\
3: change field population density to HIGH\
ESC: Exit program

(1, 2 and 3 will take effect after hitting r)

## Dependencies
Just SDL2.

## Compiling
make -> compile executable (./game_of_life)\
make clean -> delete obj files\
make fclean -> delete obj files + executable

## Bugs
Sometimes some cells don't render properly.\
they're there, just invisible. I'm not too sure why yet. I'm assuming
it may have something to do with timing issues caused by SDL_Delay().
