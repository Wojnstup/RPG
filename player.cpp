#include "player.h"

Player::Player()
{
  sprite = LoadTexture("./Sprites/GRID.png");
  position = Vector2{100,100};
}

void Player::Move()
{
  int newX = position.x;
  int newY = position.y;
  bool isMoving = false;
  
  if (IsKeyDown(KEY_A))
  {
	newX -= speed;
	position.x -= speed;

	prevOrient = LEFT;
	isMoving = true;
  }else if (IsKeyDown(KEY_D))
  {
	newX += speed;
	position.x += speed;
	
	prevOrient = RIGHT;
	isMoving = true;
  }

  if (IsKeyDown(KEY_W))
  {
	newY -= speed;
	position.y -= speed;
	
	prevOrient = BACK;
	isMoving = true;
  }else  if (IsKeyDown(KEY_S))
  {
	newY += speed;
	position.y += speed;
	
	prevOrient = FRONT;
	isMoving = true;
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

  
  DrawTextureRec(
				 sprite,
				 Rectangle{
				   (sprite.width/maxFrame)*frame,
				   (sprite.height/4)*orientation,
				   sprite.width/maxFrame,
				   sprite.height/4
				 },
				 Vector2{x,y},
				 WHITE
				 );
}
