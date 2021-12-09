#include "raylib.h"

#ifndef _GAMEOBJECT_H
#include "Engine/gameObject.h"
#endif

enum Orientation {
  FRONT,
  BACK,
  RIGHT,
  LEFT
};


class Player : public GameObject{
 public:
  
  Player(
		 std::vector<GameObject*> * objects,
		 std::vector<std::vector<Vector2>> * _colliders,
		 int x,
		 int y
		 );
  void Update();

  /*Functions*/
  void DrawSprite(int x, int y, int orientation, bool isMoving);
  void Move(); 
  void CollisionCheck();
  void SetInterPoint();
  void Interact();
 
  struct Vector2 size;
  struct Vector2 position;
  struct Rectangle collider;

  // struct Vector2 centerPoint;
  struct Vector2 interPoint;

private:
  Texture2D sprite; 
  int speed=5;
  struct Vector2 speedV; 
  
  /* Animation variables */
  int prevOrient=FRONT;
  int frame=0;
  float timer=0;
  const int maxFrame=4;
  
  //Collider stuff
  std::vector<std::vector<Vector2>> * colliders;
  
};
