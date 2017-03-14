#include "physics-tmp.h"

Physics::Physics() {}
Physics::~Physics() {}


//Sample function, read more about it in the header file
Object Physics::moveTowards(Object cur, Object des) {
  int speed = 3; //eventually you will be able to retrieve the speed from the object like: object.getSpeed(), until then it is hardcoded
  //Note: I am not the best at math so this will be very rudimentary
  if(cur.getDestX() > des.getDestX()) { //is the destination to the left
    if(cur.getDestY() > des.getDestY()) { //is the destination below
      cur.setDestX(cur.getDestX()-speed); //move to the left
      cur.setDestY(cur.getDestY()-speed); //move down
    } else if(cur.getDestY() == des.getDestY()) { //is the destination at the same y
      cur.setDestX(cur.getDestX()-speed); //move to the left
    } else { //or is the destination above
      cur.setDestX(cur.getDestX()-speed); //move to the left
      cur.setDestY(cur.getDestY()+speed); //move up
    }
  } else if(cur.getDestX() == des.getDestX()) { //is the destination at the same x value
    if(cur.getDestY() > des.getDestY()) { //is the destination below
      cur.setDestY(cur.getDestY()-speed); //move down
    } else if(cur.getDestY() == des.getDestY()) { //is the destination at the same y
      //the destination is where the object is...
    } else { //or is the destination above
      cur.setDestY(cur.getDestY()+speed); //move up
    }
  } else { //or is the destination to the right
    if(cur.getDestY() > des.getDestY()) { //is the destination below
      cur.setDestX(cur.getDestX()+speed); //move to the left
      cur.setDestY(cur.getDestY()-speed); //move down
    } else if(cur.getDestY() == des.getDestY()) { //is the destination at the same y
      cur.setDestX(cur.getDestX()+speed); //move to the left
    } else { //or is the destination above
      cur.setDestX(cur.getDestX()+speed); //move to the left
      cur.setDestY(cur.getDestY()+speed); //move up
    }
  }
  return cur; //in game code for how this function will be called: ship.setDest(this, blackhole);
  //there is also a chance this code is wrong :), I haven't tested it out, but it builds
}
