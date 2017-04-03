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
