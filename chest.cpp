#include "chest.h"

Chest::Chest(std::vector<GameObject*> * objects, int x, int y)
{
  objects->push_back(this);
  //hasColliderPoints = true;
  sprite = LoadTexture("Sprites/chest.png");
  destination = Rectangle{x,y,120,120};

  //collider = Rectangle{x,y,120,120};
  collider = Rectangle{x+20,y+40,80,80};
  points = {
	Vector2{collider.x,collider.y},
	Vector2{collider.x, collider.y + collider.height},
	Vector2{collider.x + collider.width, collider.y + collider.height},
	Vector2{collider.x + collider.width, collider.y}
  };
}

void Chest::Update()
{
  DrawTextureTiled(
					sprite,
					Rectangle{
					  isOpen * 60,
					  0,
					  60,
					  60
					},
					destination,
					Vector2{0,0},
					0.0f,
					2.0f,
					WHITE
  );

  /*
  for (int i=0; i< 4 ; i++)
	DrawCircle(points[i].x, points[i].y,10.0f,WHITE);
  */
}

void Chest::OnInteract()
{
  if(isOpen)
	isOpen=false;
  else
	isOpen = true; 
}

