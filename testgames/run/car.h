#ifndef CAR_H
#define CAR_H

//#include <arch/arch.h>
#include "/usr/include/arch/arch.h"

class Car {
private:
 Object c;
 bool in;
 float rotate;
 float scale;
 float stutter;
 float vel;
 vector<Object> burn;
 int id;
 bool l,r,u,d;
 int wbounds, hbounds;
public:
 Car();
 void drive();
 void getIn();
 void getOut();
 void genBurn();
 vector<Object> getBurns() const {return burn;}
 void move(bool l, bool r, bool u, bool d);
 void update();
 Object setCar(string img, int fx, int fy, int fw, int fh, SDL_Renderer* ren, float sp, float sc);
 void setCar(Object obj) {c=obj;}
 Object getCar() const {return c;}
 void setIn(bool i) {in=i;}
 bool isIn() const {return in;}
 void setSpeed(float s) {c.setSpeed(s);}
 float getSpeed() {return c.getSpeed();}
 void setRotate(float rot) {rotate=rot;}
 float getRotate() const {return rotate;}
 void setScale(float s) {scale=s;}
 float getScale() const {return scale;}
 void setStutter(float s) {stutter=s;}
 float getStutter() const {return stutter;}
 void setVel(float v) {vel=v;}
 float getVel() const {return vel;}
 double get_degrees(double input);
 void setBounds(int w, int h) {wbounds=w; hbounds=h;}
};

#endif //CAR_H
