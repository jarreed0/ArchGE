# ArchGE 0.2 - A 2D Game Engine written in C++ and using SDL2 #
Created by Archeantus Games

![alt tag](http://archeantus.net/images/engine-logo.gif)

![alt tag](http://archeantus.net/images/logo.png)

# Check out our NEW [PDF](http://jar.ylimaf.com/archge/docs/latex/refman.pdf) documentation for ArchGE! #
# Check out the NEW [online docs](http://jar.ylimaf.com/archge/docs/html/annotated.html) #

# Under Heavy Development #
## Next Update: (will include) ##
- [] Object coordinate system
- [] Object movement
- [] Adding Objects (and there children) to a Level
- [] Have screen follow a specific Object (the player).
- [] Set up Camera/Lens movement
- [] Fix bugs
- [] New Input class/method

# News #
 - - - -

![alt tag](docs/screenshots/hero.png)

## New Version of ArchGE ##
After several long hours we finally released a new version of Arch Game Engine. The new engine implements the coordinate system, map, tilesets, and levels differently. Because of this the old sample games are no longer supported with **ArchGE 0.2**.

## Update now and never have to remember to update again! ##
The newest version of manage can check for updates! and let you know about them and update without distubring your current manage process.

Update with: `./manage -s`

## Tutorials!!! Finally! ##
Just below this news section we have some tutorials on how to set up a game using **ArchGE 0.2**

## Docs! ##
Along with the tutorials we have tons of docs generated with doxygen from the incode-comments.

It is limited now but you can check it out in the docs refman PDF and even in the HTML code.

## Problems ##
Currently **ArchGE 0.2** has a few minor bugs.

The known bugs include the following:

*The splashscreen no longer works.
 *We are currently working on this right now!
 *Bypass it with the debug() feature: `engine.debug()` after initialization.
*Input! Input! Input!
 *The input class, sadly didn't have any sort of overhaul in the latest update.
 *Because of this there is a few bugs from the previous ArchGE version.
 *Update on the way!

Now of any other bugs? Let us know!

![alt tag](docs/screenshots/genesis.png)

# Tutorials #
 - - - -
Check out test games for more examples.

Currently there is only two (and they don't do much) because the older games aren't supported on this engine version.
More sample games on the way!

## Setting Up The Engine ##
The Engine has a few simple steps to setting it up and creating a window.

Declaring the Engine

`Engine e;`

Setting in debug mode (required as of now because of broken splashscreen)

`e.debugMode(true);`

Currently the debug mode is only used to bypass the splashscreen, eventually is will have more tools for debuggers.

Creating the window
```string NAME = "Window Title";
int WIDTH = 750; //Window width;
int HEIGHt = 530; //Window height;
e.init(NAME, WIDTH, HEIGHT, 0); //0 is for extra SDL_Init flags.
```
This is the simplest way to create a window. Check out ArchGE's new docs for other functions to create more advance windows.

Setting the background color

`e.setColor(0x00, 0xf8, 0x99);`

Just uses simple RGB colors.

Setting the background

`e.setBackground("background.png");`

(ArchGE 0.2 currently supports PNG and BMP images)

## Setting Up A Game Loop ##
Here is a samle game loop:
```
void Game::loop() {
  while(running) {
    e.loopStart();
    bool frame = true;
    while(frame) {
      e.update();
      input(); //user defined
      update(); //user defined
      draw(); //user defined
      if(!e.FPS()) frame=false;
    }
    e.render();
  }
}
```

## Creating A Level ##
Currently Levels stores tilesets and maps.
The will store Objects in the next update.

Declarations
```
int TILE_SIZE = 24;
int TOTAL_TILES = 60;
Level level;
Stage stage;
Map map;
Tileset tileset;
```

Loading them in
```
tileset.create("tiles", "res/tiles.bmp", e.getRenderer(), TILE_SIZE, TILE_SIZE, TOTAL_TILES/12, 12, TOTAL_TILES); //Name of tileset, file for tiles (BMP or PNG), renderer, width of a tile, height of a tile, how many rows there are, how may tiles per row, how many tiles.
map.loadMap("res/1.level");
level.setPrecise(true); //Precision makes it so that the coordinates at the end of a map file are either per pixel instead of per Tile
stage.createStage(map, tileset);
level.setStage(stage);
level.create();
level.setScale(40, 40);
level.setScreenSize(WIDTH, HEIGHT);
```
There are other ways to do this. Check out the docs for them.

Draw the Level

`e.draw(level)`

Move the Level

`level.move(mx, my)`

## Build The Game ##
`g++ *.cpp arch.a -lSDL2 -lSDL2_image -std=c++11`

Makefile generation coming soon.

![alt tag](docs/screenshots/force.png)

# Manage #
 - - - -

## Try out manage: ##

`chmod u+wx manage`

`./manage -s (or setup)`

`manage -i (or install)`

## Update now and neverhave to remember to update again! ##
The newest version of manage can check for updates! and let you know about them and update without distubring your current manage process.

Update with: `./manage -s`

## Build engine with manage: ##

`manage engine (or -e)`

## Build game with engine: ##

`manage game (or -g)` GAMEDIR (the game needs a ./build.sh, just copy it from the snake one and edit it a bit)

## Test engine/game with the newest version ##

`manage test GAMEDIR`

## Push back to main branch ##

`manage push (all for everything -or- specifiy file)`

## Find out more: ##

`manage -h (or help)`

And yes I know it is a little cluttered and keep in mind it has a few errors.

- - - -

Archeantus Games

[Website](http://archeantus.net/)

![alt tag](http://archeantus.net/images/logo.png)
