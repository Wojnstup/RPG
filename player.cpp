#include "player.h"
#include "collisions.h"

Player::Player(std::vector<GameObject*> * objects, int x, int y)
{
  objects->push_back(this);
  sprite = LoadTexture("./Sprites/GRID.png");
  position = Vector2{x,y};
  size = Vector2{120,120};
  speedV = Vector2{speed,speed};
  collider = Rectangle{x+20,y+80,80,40};
}

void Player::Update()
{
  //collider.x=position.x+20;
  position.x = collider.x-20;
  //collider.y=position.y+80;
  position.y = collider.y-80;
  Move();
}

void Player::Move()
{
  int newX = collider.x;
  int newY = collider.y;
  bool isMoving = false;
  
  if (IsKeyDown(KEY_A))
  {
	//newX -= speed;
	speedV.x = 0-speed;
	
	prevOrient = LEFT;
	isMoving = true;
  }else if (IsKeyDown(KEY_D))
  {
	//newX += speed;
	speedV.x = speed;
	
	prevOrient = RIGHT;
	isMoving = true;
  }else
	{
	  speedV.x=0;
	}

  if (IsKeyDown(KEY_W))
  {
	//newY -= speed;
	speedV.y = -speed;
	  
	prevOrient = BACK;
	isMoving = true;
  }else  if (IsKeyDown(KEY_S))
  {
	//newY += speed;
	speedV.y = speed;
	
	prevOrient = FRONT;
	isMoving = true;
  }else
	{
	  speedV.y=0;
	}

  //Collisions - doesn't belong here
  CollisionCheck(newX, newY, isMoving);
	  
}

void Player::CollisionCheck(int newX, int newY, bool isMoving)
{
  collider.x += speedV.x;
  collider.y += speedV.y;
  std::vector<std::vector<Vector2>> colliders;
  
  std::vector<Vector2> polygon= {
	Vector2{200,200},
	Vector2{200,300},
	Vector2{300,300},
	Vector2{300,200}
  };

  std::vector<Vector2> treeLine = {
	Vector2{0,240},
	Vector2{1080,240}
  };

  
  colliders.push_back(treeLine);
  colliders.push_back(polygon);
  int edge;

  for ( struct Vector2 point : polygon)
	{
	  DrawCircle(point.x,point.y,10.0f,WHITE);
	}
  CheckCollisionRecColliders(collider, speedV, colliders);
  /* 
  if(!CheckCollisionRecLine(Rectangle{newX, newY, collider.width,collider.height},Vector2{0,240}, Vector2{1080,240} )
	  && !CheckCollisionRecPoly(Rectangle{newX,newY,collider.width,collider.height}, polygon , edge)
	 )
	{
	  collider.x = newX;
	  collider.y = newY;

	}
  else if(!CheckCollisionRecLine(Rectangle{newX, position.y, collider.width, collider.height},Vector2{0,180}, Vector2{1080,180})
 && !CheckCollisionRecPoly(Rectangle{newX,newY, collider.width, collider.height}, polygon , edge))
	{
	  collider.x = newX;
	}
  */
  DrawSprite(position.x, position.y, prevOrient, isMoving);
}

void Player::DrawSprite(int x, int y, int orientation, bool isMoving)
{
  /* This increases frame every 0.2 seconds */
  if (isMoving)
	{
	  timer += GetFrameTime();
	  if (timer >= 0.20f)
		{
		  frame++;
		  timer = 0.0f;
		}
	}

  
  DrawTextureTiled(
				 sprite,
				 Rectangle{
				   (sprite.width/maxFrame)*frame,
				   (sprite.height/4)*orientation,
				   sprite.width/maxFrame,
				   sprite.height/4
				 },
				 Rectangle{
				   x,
				   y,
				   size.x,
				   size.y
				 },
				 Vector2{0,0},
				 0.0f,
				 2.0f,
				 WHITE
				 );
}
