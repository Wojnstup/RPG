#include "chest.h"

Chest::Chest(std::vector<GameObject*> * objects, int x, int y, TextBox * _textBox)
{
  
  objects->push_back(this);
  textBox = _textBox;
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
}

void Chest::OnInteract()
{
  if(isOpen)
	{
	  isOpen=false;
	}
  else
	{
	  isOpen = true; 

	  textBox->Display("You've opened a chest! ", WHITE);
	}
}

