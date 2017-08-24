#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "object.h"

//! Object that is a background image that covers the screen.
class Background : public Object {
private:
public:
  Background();
  ~Background();
  //! Sets the background with a path to the file name, the width and height of the screen, and the renderer.
  void setBackground(string file, int w, int h, SDL_Renderer* ren);
};

#endif //BACKGROUND_H
#ifndef COLLISION_H
#define COLLISION_H

class Object;

//! Class used for calculating different types of collision between given Objects.
class Collision {
private:
public:
  Collision();
  ~Collision();
  //! Check if two objects are touching.
  bool isTouching(Object a, Object b);
  //! Check if an object contains another object
  bool contains(Object a, Object b);
  //! Check if two object are not touching.
  bool outOfBoundsOf(Object a, Object b);
  //! Check if the first object is above the second object.
  bool isAbove(Object a, Object b);
  //! Check if the first object is below the second object.
  bool isBelow(Object a, Object b);
  //! Check if the first object is to the right of the second object.
  bool isRightOf(Object a, Object b);
  //! Check if the first object is to the left of the second object.
  bool isLeftOf(Object a, Object b);
  bool overlaps(Object a, Object b);
};

#endif //COLLISION_H
#ifndef ENGINE_H
#define ENGINE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
using namespace std;
#include <iostream>
#include <cassert>
#include <string>
#include <unistd.h>
#include <sys/time.h>
#include <vector>
#include <ctime>
#include <time.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include "image.h"
#include "object.h"
#include "background.h"
#include "tile.h"
#include "entity.h"
#include "collision.h"
#include "tileset.h"
#include "input.h"
#include "physics-tmp.h"
#include "stage.h"
#include "level.h"
#include "gamestate.h"

/*
#include "splash.h"
*/

//! Class for declaring an engine, which does basic SDL commands like creating the window and renderer.
class Engine {
private:
  SDL_Renderer* engren; //!< SDL Renderer.
  SDL_Window *engwin; //!< SDL Window.
  int WIDTH, HEIGHT; //!< Width and height of the window.
  int simulationTime, realTime; //!< Timestamps used for fps loop.
  //bool fps; //!< Boolean for loop.
  bool bkg; //!< Boolean for if there is a set background.
  Background background; //!< Background to display.
  Uint8 red, green, blue; //!< Colors for background.
  bool debug;
  bool running;
  time_t lastTime, curTime;
  long capLast, capCur;
  int frameCount;
  //int framesPerSecond, cappedFrame, capTime, capMark, renderMiliGap;
  bool glMode;
  int glView[9];
  int curFPS, setFPS, lastFrame;
  double gravity;
  TTF_Font *font;
  GameState gs;
  int sr,sg,sb;
public:
  Engine();
  //! Decontructs renderer and window and then quits SDL.
  ~Engine();
  void setGravity(double g) {gravity=g;}
  void setFrameRate(int f) {setFPS=f;}
  double getGravity() const {return gravity;}
  //! Create a window with a given name, width, height, and anyother SDL_Window flags.
  SDL_Renderer* init(string s, const int& w, const int& h, int flag);
  //! Create a window with a given name, width, height, SDL_Window flags, and  specified SDL_Init flags.
  SDL_Renderer* init(string s, const int& w, const int& h, int flag, int it);
  //! Create a window with a given name, width, height, SDL_Window flags, and specified x and y coordinate.
  SDL_Renderer* init(string s, const int& w, const int& h, int flag, int x, int y);
  //! Create a window with a given name, width, height, SDL_Window flags, specified x and y coordinate, and SDL_Init flags.
  SDL_Renderer* init(string s, const int& w, const int& h, int flag, int x, int y, int it);
  //! Set window name.
  void setName(string s);
  //! Set window position.
  void setPos(int x, int y);
  //! Set window size.
  void setSize(int w, int y);
  //! Returns screen renderer.
  SDL_Renderer* getRenderer();
  //! Returns screen window.
  SDL_Window* getWindow() const { return engwin; }
  //! Sets SDL color.
  void setColor(Uint8 r, Uint8 g, Uint8 b);
  //! Call this at the beginning of a loop to initilaize the loop.
  void loopStart();
  //! Call this at the end of the game loop to render.
  void render();
  //! Get fps.
  //bool FPS() const { return fps; }
  //! Update loop time.
  void update();
  //! Set background.
  void setBackground(Background b) { background = b; }
  //! Set background with filename.
  void setBackground(string filename);
  //! Get background.
  Background getBackground() const { return background; }
  //! Draw background.
  void drawBackground();
  //! Draw an object on the screen.
  void draw(Object obj);
  //! Draw a vector of Objects
  void draw(vector<Object> objs);
  void draw(vector<vector<Object>> objs);
  //! Draw an object with a pass key before/during splash.
  void draw(Object obj, int key);
  //! Draw the level.
  void draw(Level lvl);
  //! Write to the screen with a char, coordinates, color, ttf file
  void draw(const char *text, int x, int y, int r, int g, int b);
  //! Calls splashscreen at the beginning of the game. This is automatically called unless deactivated.
  void splash();
  //! Deactives the splashscreen, requires key.
  void bypassSplash(int key);
  //! Check if the splashscreen has occured.
  bool hasSplashed();
  //! Active debugger with Boolean
  void debugMode(bool d);
  void loadFont(char *font_path);
  void hideMouse();
  void showMouse();
  bool getRunning() const { return running; }
  void setRunning(bool r) { running = r; }
  void setGLView(int a, int b, int c, int d, int e, int f, int g, int h, int i);
  void setGLMode(bool m) {glMode=m; glViewport(0, 0, WIDTH, HEIGHT); }
  int getFPS() const {return curFPS;}
  void loop();
  int getTicks();
  void delay(int time);
  void enableTransparency() {SDL_SetRenderDrawBlendMode(engren, SDL_BLENDMODE_BLEND);}
  struct color { Uint8 r, g, b; };
  void setGamestate(int s) {if(gs.getGameState()!=0) gs.setGameState(s);}
  int getGameState() {return gs.getGameState();}
  void setSplashColor(int r, int g, int b) {sr=r;sg=g;sb=b;}
};

#endif //ENGINE_H
#ifndef ENTITY_H
#define ENTITY_H

#include "object.h"
#include "collision.h"
//#include "inventory.h" //not yet created

//! Class for storing health, emotion, team, etc. of an Object.
class Entity : public Object {
private:
  double health; //!< Int for the Entity's health.
  double maxHealth; //!< Int for the Enitity's max health.
  //Inventory inv; //!< Not yet created. Is going to be an instance of an Inventory class that need to be made.
  int emotion; //!< Int for creating a range of emotional states.
  int team; //!< Int for setting the team the Entity is on.
  bool active; //!< Boolean for declaring if an entity is active.
  Collision col;
  SDL_Rect detect;
public:
  Entity();
  ~Entity();
  //! Get Entity's health.
  double getHealth() const { return health; }
  //! Set the Entity's health. If the health is higher then the max health it will set it to the max health.
  void setHealth(double h) { health=h; }
  //! Get max health.
  double getMaxHealth() const { return maxHealth; }
  //! Set max health.
  void setMaxHealth(double mh) { maxHealth=mh; }
  //! Deal damage. Subtracted from health. If health is less then zero it kills the entity.
  void damage(double d);
  //! Give health to the Entity.
  void heal(double h);
  //! Get current emotion state.
  int getEmotion() const { return emotion; }
  //! Set current emotion state.
  void setEmotion(int e) { emotion=e; }
  //! Get Entity's team.
  int getTeam() const { return team; }
  //! Set Entity's team.
  void setTeam(int t) { team=t; }
  //! Check if Entity is active.
  bool isActive() const { return active; }
  //! Sets health to zero and deactives the Entity.
  void kill();
  //! Sets active to false.
  void deactivate();
  //! Sets active to true.
  void activate();
  //! Checks if an the Entity is in the current screen by passing the screen to it.
  void checkDisplayable(Object screen);
  //! Returns the detection radius.
  SDL_Rect getDetect() const { return detect; }
  //! Sets the detection with another SDL_Rect.
  void setDetect(SDL_Rect d) { detect = d; }
  //! Sets the detection radius with a single given distance.
  void setDetectRange(int r);
  //! Sets the detection radius with two given distances in both directions.
  void setDetectRange(int w, int h);
};

#endif //ENTITY_H
#ifndef GAMESTATE_H
#define GAMESTATE_H

class GameState {
  public:
    GameState();
    ~GameState();
    int SPLASH = 0, MENU = 1, INGAME = 2, GAMEOVER = 3, PAUSE = 4;
    int getGameState();
    void setGameState(int);
  private:
    int currentstate = 0;
};

#endif //GAMESTATE_H
#ifndef IMAGE_H
#define IMAGE_H

#include "sdl_check.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
using namespace std;
#include <iostream>

//! Class for loading in SDL Textures.
class Image {
private:
  SDL_Texture* tex; //!< SDL_Texture for the image.
  string filename; //!< Path file to the image.
public:
  Image();
  ~Image();
  //! Load in either a BMP or PNG file with the path and renderer.
  void loadImage(string file, SDL_Renderer* ren);
  //! Load in a PNG image with the path to the PNG file and the renderer.
  void loadPNG(string file, SDL_Renderer* ren);
  //! Load in a BMP image with the path to the BMP file and the renderer.
  void loadBMP(string file, SDL_Renderer* ren);
  //! Get SDL_Texture.
  SDL_Texture* getTexture();
  //! Set new, preloaded texture, to Image.
  void setImage(SDL_Texture* t) {tex=t;}
  //! Get path file of the image.
  string getFile() const {return filename;}
  //! Set path file to the image.
  void setFile(string f) {filename=f;}
  //! Set texture
  void setTexture(SDL_Texture* t) {tex=t;}
  void setSurface(SDL_Surface* s, SDL_Renderer* ren) {tex=SDL_CreateTextureFromSurface(ren, s); SDL_FreeSurface(s);}
};

#endif //IMAGE_H
#ifndef INPUT_H
#define INPUT_H

#include <SDL2/SDL.h>
using namespace std;
#include <iostream>

//! Class for checking and storing keyboard and mouse input.
class Input {
public:
  Input();
  ~Input();
  //! Log all current keys and buttons being pressed.
  void logPress();
  //! Check if a key has been pressed using a given key from this class. Ex: Input i; i.checkKey(i.up);
  bool checkKey(int k);
  //! Reset all pressed keystrokes and other inputs to false. Automatically down at the beginning of each logPress().
  bool reset();
  int getMouseX() const { return mousex; }
  int getMouseY() const { return mousey; }
  int left; //!< Log ID for left
  int right; //!< Log ID for right
  int up; //!< Log ID for up
  int down; //!< Log ID for down
  int q; //!< Log ID for q
  int w; //!< Log ID for w
  int e; //!< Log ID for e
  int r; //!< Log ID for r
  int t; //!< Log ID for t
  int y; //!< Log ID for y
  int u; //!< Log ID for u
  int i; //!< Log ID for i
  int o; //!< Log ID for o
  int p; //!< Log ID for p
  int a; //!< Log ID for a
  int s; //!< Log ID for s
  int d; //!< Log ID for d
  int f; //!< Log ID for f
  int g; //!< Log ID for g
  int h; //!< Log ID for h
  int j; //!< Log ID for j
  int k; //!< Log ID for k
  int l; //!< Log ID for l
  int z; //!< Log ID for z
  int x; //!< Log ID for x
  int c; //!< Log ID for c
  int v; //!< Log ID for v
  int b; //!< Log ID for b
  int n; //!< Log ID for n
  int m; //!< Log ID for m
  int lshift; //!< Log ID for left shift
  int rshift; //!< Log ID for right shift
  int shift; //!< Shift ID for shift
  int quit; //!< Log ID for quit
  int esc; //!< Log ID for esc
  int mouseleft; //!< Log ID for left mouse click
  int mousemiddle; //!< Log ID for middle mouse click
  int mouseright; //!< Log ID for right mouse click
  int mouseup; //!< Log ID for scroll up on mouse wheel
  int mousedown; //!< Log ID for scroll down on mouse wheel
private:
  //! Array that stores what buttons are down.
  bool keys[51];
  int mousex; //!< Log ID for mouse x coordinate
  int mousey; //!< Log ID for mouse y coordinate
};

#endif //INPUT_H
#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include "stage.h"
#include "entity.h"
#include "collision.h"

//! This class stores a Stage and Objects and can move them and display them.
class Level {
private:
  Stage stage;
  vector< vector<Tile> > tiles;
  vector<Object> objects;
  vector<Entity> entities;
  double x, y;
  int tilewidth, tileheight;
  Object screen;
  Collision col;
  bool precise;
  int mainEntityID;
  bool mainEntitySet;
  Object camera, lens;
  bool activeCam, activeLens;
public:
  Level();
  ~Level();
  //! Create the Level based on the given stage.
  void create();
  //! Give a Stage to the Level.
  void setStage(Stage s) { stage = s; }
  //! Create a Stage for the Level by giving a Map and a Tileset.
  void setStage(Map m, Tileset t) { stage.setMap(m); stage.setTileset(t); }
  //! Scale the Level by giving it the width and height to scale by.
  void setScale(int w, int h);
  //! Scale the Level by giving it a single integer to scale by.
  void setScale(int s) { setScale(s, s); }
  //! Calculate the position of the level based on coordinates.
  void calcPos();
  //! Return the Tiles that are currently on the screen.
  vector<Tile> getTilesToRender();
  //! Return the Objects that are currently on the screen.
  vector<Object> getObjectsToRender();
  //! Return the Entities that are currently on the screen.
  vector<Entity> getEntitiesToRender();
  //! Move the screen by passing in how much to move on the x and y coordinates.
  void move(int mx, int my);
  void moveEntity(int id, int mx, int my);
  //! Set the coordinate for the screen with a given x and y.
  void setCoord(double x, double y) { setX(x); setY(y); screen.setPosCoord(getX(), getY()); }
  //! Set the x coordinate.
  void setX(double x) { this->x = x; }
  //! Set the y coordinate.
  void setY(double y) { this->y = y; }
  //! Get the x coordinate.
  double getX() const { return x; }
  //! Get the y coordinate.
  double getY() const { return y; }
  Object getScreen() const { return screen; }
  //! Set the size of the screen by passing in the width and height.
  void setScreenSize(int w, int h) { screen.setPosSize(w, h); }
  //! Active precise if you want the coordinates in a map file to go to that exact pixel, or leave it off if you want it to go to that Tile.
  void setPrecise(bool p) { precise = p; }
  //! Add Object to Level
  void addObject(Object o);
  //! Add vector of Objects to Level
  void addObject(vector<Object> o);
  //! Add Entity to Level
  int addEntity(Entity e);
  //! Add vector of Entity's to Level
  void addEntity(vector<Entity> e);
  //! Set main Entity.
  int setMainEntity(Entity e);
  //! Tell Level which one Entity is the main one.
  int setMainEntity(int m);
  void setCameraMargin(int wm, int hm);
  void centerCamera(int percentage);
  void setLensMargin(int wn, int hm);
  void centerLens(int percentage);
  Object getCamera();
  Object getLens();
};

#endif //LEVEL_H
#ifndef MAP_H
#define MAP_H

#include <vector>
#include <iostream>
using namespace std;
#include <fstream>

//! This class takes in a file and loads it in for the map
class Map {
private:
  vector< vector<int> > map;
  int startX, startY;
public:
  Map();
  ~Map();
  //! Read in map file with given path to the file.
  void loadMap(string filename);
  //! Get the start x coordinate found in the file.
  int getX() const { return startX; }
  //! Get the start y coordinate found in the file.
  int getY() const { return startY; }
  //! Get the vector of integers found in the file.
  vector< vector<int> > getMap() const { return map; }
};

#endif //MAP_H
#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include <iostream>
#include <cstring> 
#include <glm/glm.hpp>
using namespace std;
using namespace glm;

class Model {
private:
public:
 Model();
 ~Model();
 void load();
};

#endif //MODEL_H
#ifndef OBJECT_H
#define OBJECT_H
#define PI 3.14159265358979323846

#include "image.h"
#include "input.h"
#include <SDL2/SDL.h>

class Collision;

//! This class stores information for an Object in the game.
class Object {
private:
  Image img;
  Input i;
  SDL_Rect frame, dest, pos, buff, movedBuff;
  double angle;
  string name;
  double x, y, velX, velY, speed;
  bool displayable;
  bool gravity;
  bool objsImage;
  struct color { Uint8 r, g, b, a; };
  color objsColor;
public:
  Object();
  ~Object();
  SDL_Rect getBuff() const {return buff;}
  SDL_Rect getMovedBuff() const {return movedBuff;}
  void actGravity(bool g) {gravity=g;}
  //! This sets if you want the Object to visible on the screen by passing in a boolean.
  void setDisplayable(bool d) { displayable = d; }
  //! Check if the Object is displayable by seeing if it is in a given screen.
  bool isDisplayable(Object screen) { checkDisplayable(screen); return displayable; }
  //! Checks if the Object is in the given screen.
  virtual void checkDisplayable(Object screen);
  //! Set the coordinate of the Object with a given x and y.
  void setCoord(double x, double y) { setX(x); setY(y); }
  //! Set the x coordinate with a given x.
  void setX(double sx) { x = sx; }
  //! Set the y coordinate with a given y.
  void setY(double sy) { y = sy; }
  //! Move along the x and y coordinate with a given x and y amount.
  void move(double x, double y) { moveX(x); moveY(y); }
  //! Move along the x coordinate with a given x amount.
  void moveX(double mx) { x += mx; }
  //! Move along the y coordinate with a given y amount.
  void moveY(double my) { y += my; }
  //! Get the current x coordinate.
  double getX() const { return x; }
  //! Get the current y coordinate.
  double getY() const { return y; }
  //! Get the Object's Image.
  Image getImage() const { return img; }
  //! Set the Object's Image with a given Image.
  void setImage(Image i) { img = i; objsImage=true; }
  //! Give the path and renderer to create the Object's Image.
  void setImage(string file, SDL_Renderer* ren) { img.loadImage(file, ren); objsImage=true; }
  //! Get the Object's angle.
  double getAngle() const { return angle; }
  //! Set the angle.
  void setAngle(double a) { angle = a; }
  //! Center the Object based on a width and height.
  void center(int w, int h);
  //! Get the frame that the Object parses from the Image.
  SDL_Rect getFrame() const { return frame; }
  //! Get the destination for the Object to be displayed on screen.
  SDL_Rect getDest() const { return dest; }
  //! Get the position of the Object in the world.
  SDL_Rect getPos() const { return pos; }
  //! Set the frame with a given SDL_Rect.
  void setFrame(SDL_Rect i) { frame = i; }
  //! Set the destination with a given SDL_Rect.
  void setDest(SDL_Rect i) { buff=dest; if(movedBuff.x!=buff.x && movedBuff.y!=buff.y) {movedBuff=buff;} dest = i; }
  //! Set the position with a given SDL_Rect.
  void setPos(SDL_Rect i) { pos = i; }
  //! Set the frame with a given x and y coordinate and width and height.
  void setFrame(int x, int y, int w, int h) { setFrameCoord(x, y); setFrameSize(w, h); }
  //! Set the x and y coordinate of the frame.
  void setFrameCoord(int x, int y) { setFrameX(x); setFrameY(y); }
  //! Set the size of the frame with a width and height.
  void setFrameSize(int w, int h) { setFrameW(w); setFrameH(h); }
  //! Set the x coordinate of the frame.
  void setFrameX(int x) { frame.x = x; }
  //! Set the object's velocity toward another object
  void setVelTo(Object o);
  //!Set the object's angle towards another object.
  void lookAt(Object o);
  //! Set the y coordinate of the frame.
  void setFrameY(int y) { frame.y = y; }
  void setFrameW(int w) { frame.w = w; }
  void setFrameH(int h) { frame.h = h; }
  int getFrameX() const { return frame.x; }
  int getFrameY() const { return frame.y; }
  int getFrameW() const { return frame.w; }
  int getFrameH() const { return frame.h; }
  void setDest(int x, int y, int w, int h) { buff=dest; if(movedBuff.x!=buff.x || movedBuff.y!=buff.y) {movedBuff=buff;} setDestCoord(x, y); setDestSize(w, h); }
  void setDestCoord(int x, int y) { setDestX(x); setDestY(y); }
  void setDestSize(int w, int h) { setDestW(w); setDestH(h); }
  void setDestX(int x) { buff=dest; if(movedBuff.x!=buff.x || movedBuff.y!=buff.y) {movedBuff=buff;} dest.x = x; }
  void setDestY(int y) { buff=dest; if(movedBuff.x!=buff.x || movedBuff.y!=buff.y) {movedBuff=buff;} dest.y = y; }
  void setDestW(int w) { buff=dest; if(movedBuff.x!=buff.x || movedBuff.y!=buff.y) {movedBuff=buff;} dest.w = w; }
  void setDestH(int h) { buff=dest; if(movedBuff.x!=buff.x || movedBuff.y!=buff.y) {movedBuff=buff;} dest.h = h; }
  int getDestX() const { return dest.x; }
  int getDestY() const { return dest.y; }
  int getDestW() const { return dest.w; }
  int getDestH() const { return dest.h; }
  void setPos(int x, int y, int w, int h) { setPosCoord(x, y); setPosSize(w, h); }
  void setPosCoord(int x, int y) { setPosX(x); setPosY(y); }
  void setPosSize(int w, int h) { setPosW(w); setPosH(h); }
  void setPosX(int x) { pos.x = x; }
  void setPosY(int y) { pos.y = y; }
  void setPosW(int w) { pos.w = w; }
  void setPosH(int h) { pos.h = h; }
  int getPosX() const { return pos.x; }
  int getPosY() const { return pos.y; }
  int getPosW() const { return pos.w; }
  int getPosH() const { return pos.h; }
  void moveFrame(int x, int y) { moveFrameX(x); moveFrameY(y); }
  void moveFrameX(int x) { frame.x += x; }
  void moveFrameY(int y) { frame.y += y; }
  void moveDest(int x, int y) { moveDestX(x); moveDestY(y); }
  void moveDestX(int x) { buff=dest; if(movedBuff.x!=buff.x || movedBuff.y!=buff.y) {movedBuff=buff;} dest.x += x; }
  void moveDestY(int y) { buff=dest; if(movedBuff.x!=buff.x || movedBuff.y!=buff.y) {movedBuff=buff;} dest.y += y; }
  void movePos(int x, int y) { movePosX(x); movePosY(y); }
  void movePosX(int x) { pos.x += x; }
  void movePosY(int y) { pos.y += y; }
  double getVelX() { return velX; }
  double getVelY() { return velY; }
  void setVelX(double vx) { velX = vx; }
  void setVelY(double vy) { velY = vy; }
  void setVelTo(int x, int y);
  double getSpeed() {  return speed; }
  void setSpeed(double s) { speed = s; }
  void setName(string s);
  string getName();
  void centerOn(Input i);
  void centerOn(int cx, int cy);
  void centerOn(Object obj);
  void lookAt(Input i);
  color red = {0xff,0,0,0xff};
  color green = {0,0xff,0,0xff};
  color blue = {0,0,0xff,0xff};
  void setColor(color c) {objsColor = c;}
  void setColor(Uint8 r, Uint8 g, Uint8 b) {objsColor.r=r;objsColor.g=g;objsColor.b=b;}
  void setTransparency(Uint8 a) {objsColor.a = a;}
  bool imageSet() const {return objsImage;}
  color getColor() const {return objsColor;}
  void rotateAngle(int rot);
  void moveToVel();
};

#endif //OBJECT_H

//Found here: http://stackoverflow.com/questions/4753055/perlin-noise-generation-for-terrain

#pragma once

class PerlinNoise
{
public:

  // Constructor
    PerlinNoise();
    PerlinNoise(double _persistence, double _frequency, double _amplitude, int _octaves, int _randomseed);

  // Get Height
    double GetHeight(double x, double y) const;

  // Get
  double Persistence() const { return persistence; }
  double Frequency()   const { return frequency;   }
  double Amplitude()   const { return amplitude;   }
  int    Octaves()     const { return octaves;     }
  int    RandomSeed()  const { return randomseed;  }

  // Set
  void Set(double _persistence, double _frequency, double _amplitude, int _octaves, int _randomseed);

  void SetPersistence(double _persistence) { persistence = _persistence; }
  void SetFrequency(  double _frequency)   { frequency = _frequency;     }
  void SetAmplitude(  double _amplitude)   { amplitude = _amplitude;     }
  void SetOctaves(    int    _octaves)     { octaves = _octaves;         }
  void SetRandomSeed( int    _randomseed)  { randomseed = _randomseed;   }

private:

    double Total(double i, double j) const;
    double GetValue(double x, double y) const;
    double Interpolate(double x, double y, double a) const;
    double Noise(int x, int y) const;

    double persistence, frequency, amplitude;
    int octaves, randomseed;
};
#ifndef PHYSICS_H
#define PHYSICS_H

#include <SDL2/SDL.h>
using namespace std;
#include <iostream>
#include <math.h> //This library has functions for math, like cos() thought I don't know exactly how to use it all, nonetheless it should be simple

#include "object.h"
//Use this class to create and load in objects
//As of now (for things that can help you) this class stores an objects coordinates and size
//It stores other things, like its image, but those don't help you
//Eventually there will be other things added on or new classes that inherit it that can pass more variables to you
//The class has a function called getDest() which will return a SDL_Rect that stores its coordinates
//It also has setDX(int x) and setDY(int y) for setting its coordinates
//There is also setAng(int ang) and getAng() that you can use to figure out the objects angle/direction
//But like I said, soon it will hold other variables, such as weight, speed, etc. for physics
//I don't have any example functions that need to be created so just have at it and create whatever functions you want
//Below and in the .cpp file I have an example function that moves an object towards another object


//! Class for doing physics functions.
class Physics {
public:
  Physics();
  ~Physics();
  //This function will take two sets of points, and return the next of coordinates based on a set speed that head towards the second coordinate (des)
  //! Returns modified first Object that is moving towards the second object (I THINK).
  Object moveTowards(Object cur, Object des);
  //this function can be remade with different parameters
  //for example say you want an object to just move towards coordinates instead of an object you could do this:
  //SDL_Rect moveTowards(Object cur, int x, int y);
private:
};

#endif //PHYSICS_H
#pragma once
#include <stdexcept>
#include <string>

#define SDL_CHECK(x, msg) if (!(x))                                      \
    throw std::runtime_error(std::string(msg": ") + SDL_GetError())
#ifndef STAGE_H
#define STAGE_H

#include "tileset.h"
#include "map.h"

//! The Stage class stores a Map and Tileset.
class Stage {
private:
  Map map;
  Tileset tileset;
public:
  Stage();
  ~Stage();
  //! Create a stage by passing in a Map and Tileset.
  void createStage(Map m, Tileset t) { setMap(m); setTileset(t); }
  //! Create a stage by passing in the maps file, a name for the tiles, file of the tile image, the renderer, width and height of a tile, what row of the image the tiles are onem and how many tiles there are.
  void createStage(string filename, string name, string img, SDL_Renderer* ren, int width, int height, int r, int count);
  void createStage(string filename, string name, string img, SDL_Renderer* ren, int width, int height, int r, int rcount, int count);
  void createStage(string filename, int startid, string name, string img, SDL_Renderer* ren, int width, int height, int r, int count);
  void createStage(string filename, int startid, string name, string img, SDL_Renderer* ren, int width, int height, int r, int rcount, int count);
  //! Set the Map by passing in a Map.
  void setMap(Map m) { map = m; }
  //! Load in a new map by passing in the map file.
  Map setMap(string filename) { map.loadMap(filename); return map; }
  //! Get the Map.
  Map getMap() const { return map; }
  //! Set the Tileset with a given Tileset.
  void setTileset(Tileset t) { tileset = t; }
  Tileset setTileset(string name, string img, SDL_Renderer* ren, int width, int height, int r, int count);
  Tileset setTileset(string name, string img, SDL_Renderer* ren, int width, int height, int r, int rcount, int count);
  Tileset setTileset(int startid, string name, string img, SDL_Renderer* ren, int width, int height, int r, int count);
  Tileset setTileset(int startid, string name, string img, SDL_Renderer* ren, int width, int height, int r, int rcount, int count);
  //! Get the Tileset.
  Tileset getTileset() const { return tileset; }
};

#endif //STAGE_H
#ifndef TILE_H
#define TILE_H

#include "object.h"

//! An Object class that stores the a tile value and name.
class Tile : public Object {
private:
  int value; //!< Tiles value. Used for reading from a map file, etc.
  bool solid;
public:
  Tile();
  ~Tile();
  //! Set value of the tile. This is used when reading from a map file, etc.
  void setValue(int v);
  //! Get the value of the Tile.
  int getValue() const { return value; }
  //! Set if the Tile is solid.
  void setSolid() { solid = true; }
  //! Set if the Tile is passable (not solid).
  void setPassable() { solid = false; }
  //! Check if the Tile is solid.
  bool isSolid() const { return solid; }
};

#endif //TILE_H
#ifndef TILESET_H
#define TILESET_H

#include <vector>
#include "tile.h"

//! Class for loading in multiple Tiles.
class Tileset {
private:
  vector<Tile> tiles;
public:
  Tileset();
  ~Tileset();
  vector<Tile> getTileset() const { return tiles; }
  SDL_Rect getFrame(int i) { tiles[i-1].getFrame(); }
  //! Load in a map file with the name for all the tiles, the path to the map file, path to the tileset image, the SDL renderer, width and height of a tile, row to begin from on the image, how many tiles there are in the image.
  vector<Tile> create(string name, string img, SDL_Renderer* ren, int width, int height, int r, int count);
  //! Load a map with a given name for the tiles, the file path to the map, the path to the tileset image, SDL renderer, width and height of a tile, row to begin on in the image, how many tiles on a certain row in the image, total amount of tiles in the image.
  vector<Tile> create(string name, string img, SDL_Renderer* ren, int width, int height, int r, int rcount, int count);
  //! Load in a map file with the name for all the tiles, the path to the map file, path to the tileset image, the SDL renderer, width and height of a tile, row to begin from on the image, how many tiles there are in the image.
  vector<Tile> create(int startid, string name, string img, SDL_Renderer* ren, int width, int height, int r, int count);
  //! Load a map with a given name for the tiles, the file path to the map, the path to the tileset image, SDL renderer, width and height of a tile, row to begin on in the image, how many tiles on a certain row in the image, total amount of tiles in the image.
  vector<Tile> create(int startid, string name, string img, SDL_Renderer* ren, int width, int height, int r, int rcount, int count);
  //! Push Tile in tile with given Tile.
  void addTile(Tile t);
  //! Generate and push Tile with tile name, path tot he tile image, SDL renderer, tile value, row and columg the tile as on in the image, the tiles width and height.
  Tile addTile(string name, string file, SDL_Renderer* ren, int value, int r, int c, int width, int height);
  //! Generate and push Tile with a given name, path to image file, SDL renderer, given value, and tile width and height.
  Tile addTile(string name, string file, SDL_Renderer* ren, int value, int width, int height);
  //! Generate and push Tile with a given name, path to the image, SDL renderer, value, and size (used for width and height).
  Tile addTile(string name, string file, SDL_Renderer* ren, int value, int size);
  //! Set the angle of all the tiles. Calls pushAng().
  void setAngle(int ang);
  void setSolid();
  void setSolid(int t);
  void setSolid(int s, int e);
  void setPassable();
  void setPassable(int t);
  void setPassable(int s, int e);
  void setName(string n, int id);
};

#endif //TILESET_H
