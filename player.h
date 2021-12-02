#include "raylib.h"
#include "gameObject.h"
#include <iostream>


//#ifndef _COLLISIONS_H
//#endif

enum Orientation {
  FRONT,
  BACK,
  RIGHT,
  LEFT
};


class Player : public GameObject{
 public:
  
  Player(std::vector<GameObject*> * objects, int x, int y);
  //void Start(/*int x, int y*/);
  void Update();

  /*Functions*/
  void DrawSprite(int x, int y, int orientation, bool isMoving);
  void Move(); 
  void CollisionCheck(int newX, int newY, bool isMoving);
 
  struct Vector2 size;
  struct Vector2 position;
  struct Rectangle collider;

private:
  Texture2D sprite; 
  int speed=5;
  struct Vector2 speedV; // = 5;
  
  /* Animation variables */
  int prevOrient=FRONT;
  int frame=0;
  float timer=0;
  const int maxFrame=4;
  
};
