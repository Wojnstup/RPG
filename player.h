#ifndef _TEXTBOX_H
#include "textbox.h"
#endif

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
		 std::vector<GameObject*> * _objects,
		 std::vector<std::vector<Vector2>> * _colliders,
		 int x,
		 int y
		 );
  void Update();

  /*Functions*/
  void DrawSprite(int x, int y, int orientation);
  void Move(); 
  void CollisionCheck();
  void SetInterPoint();
  void Interact();
 
  struct Vector2 size;
  struct Vector2 position;
  struct Rectangle collider;
  struct Vector2 interPoint;

private:
  std::vector<GameObject*> * objects;

  TextBox * textBox;
  Texture2D sprite; 
  int speed=5;
  struct Vector2 speedV; 

  bool isMoving = false;
  
  /* Animation variables */
  int prevOrient=FRONT;
  int frame=0;
  float timer=0;
  const int maxFrame=4;
  
  /*Collider stuff*/
  std::vector<std::vector<Vector2>> * colliders;
  
};
