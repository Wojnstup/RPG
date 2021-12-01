#include "player.h"
#include "collisions.h"

Player::Player(std::vector<GameObject*> * objects, int x, int y)
{
  objects->push_back(this);
  Start(x,y);
}

void Player::Start(int x, int y)
{
  sprite = LoadTexture("./Sprites/GRID.png");
  position = Vector2{x,y};
  size = Vector2{120,120};
}

void Player::Update()
{
  Move();
}

void Player::Move()
{
  int newX = position.x;
  int newY = position.y;
  bool isMoving = false;
  
  if (IsKeyDown(KEY_A))
  {
	newX -= speed;

	prevOrient = LEFT;
	isMoving = true;
  }else if (IsKeyDown(KEY_D))
  {
	newX += speed;
	
	prevOrient = RIGHT;
	isMoving = true;
  }

  if (IsKeyDown(KEY_W))
  {
	newY -= speed;
	
	prevOrient = BACK;
	isMoving = true;
  }else  if (IsKeyDown(KEY_S))
  {
	newY += speed;
	
	prevOrient = FRONT;
	isMoving = true;
  }
  
  if(!CheckCollisionRecLine(Rectangle{newX, newY, size.x,size.y},Vector2{0,180}, Vector2{1080,180} ))
	{
	  position = Vector2{newX, newY};

	}
  else if(!CheckCollisionRecLine(Rectangle{newX, position.y, size.x,size.y},Vector2{0,180}, Vector2{1080,180} ))
	{
	  position.x = newX;
	}
	  DrawSprite(newX, newY, prevOrient, isMoving);
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
