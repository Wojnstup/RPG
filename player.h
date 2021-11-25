#include "raylib.h"

enum Orientation {
  FRONT,
  BACK,
  RIGHT,
  LEFT
};

class Player{
 public:
  Player();

  /*Functions*/
  void DrawSprite(int x, int y, int orientation, bool isMoving);
  void Move(); 
  struct Vector2 position;

private:
  Texture2D sprite; 

  unsigned int speed = 5;
  /* Animation variables */
  int prevOrient=FRONT;
  int frame=0;
  float timer=0;
  const int maxFrame=4;
  
};
