#ArchGE - A 2D Game Engine written in C++ and using SDL2

#ArchGE is being drastically reconfigured right now on my PC. The "tmp" classes are from the last version of ArchGE, so they are being remade. Any functions in them are subject to change.

Also the splashscreen doesn't work anymore so bypass it like how it in this [example](testgames/test/main.cpp).

![alt tag](http://archeantus.net/images/engine-logo.gif)

#Check out our NEW [PDF](docs/latex/refman.pdf) documentation for ArchGE!

#Under Heavy Development

#Manage

##Try out manage:

`chmod u+wx manage`

`./manage -s (or setup)`

`manage -i (or install)`

##Build engine with manage:

`manage engine (or -e)`

##Build game with engine:

`manage game (or -g)` GAMEDIR (the game needs a ./build.sh, just copy it from the snake one and edit it a bit)

##Test engine/game with the newest version

`manage test GAMEDIR`

##Push back to main branch

`manage push (all for everything -or- specifiy file)`

##Find out more:

`manage -h (or help)`

And yes I know it is a little cluttered and keep in mind it has a few errors.

#For Engine Devs:

rebuild engine and game with: `./build.sh`

#For Game Devs:

Tutorials on how to use the engine will be out soon as the engine advances.
