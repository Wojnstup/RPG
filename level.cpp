#include "level.h"

Level::Level(std::vector<GameObject*> * _objects, const char* _background_path)
{
  objects = _objects;
  background = LoadTexture("./Sprites/background.png"); //_background_path.c_str());
  isActive = true;
}

void Level::Init()
{
  for(int i=0; i<objects->size(); i++)
	  (*objects)[i]->Start();
}

void Level::Loop()
{
  while(isActive && !WindowShouldClose())
	{
	  BeginDrawing();

	     ClearBackground(Color{41,135,1});
		 DrawTextureTiled(
						  background,
						  Rectangle{
							0,0,540,360
						  },
						  Rectangle{
							0,0,1080,720
						  },
						  Vector2{0,0},
						  0.0f,
						  2.0f,
						  WHITE
						  );
	  for(int i=0; i<objects->size(); i++)
		(*objects)[i]->Update();	  

	  EndDrawing();
	}
}
