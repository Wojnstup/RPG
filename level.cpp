#include "level.h"
#include <iostream>

Level::Level(std::vector<GameObject*> * _objects, const char* _background_path, Camera2D * _camera)
{
  objects = _objects;
  background = LoadTexture("./Sprites/background.png"); 
  isActive = true;
  camera = _camera;
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
	  std::cout << (*objects)[0]->centerPoint.x << " " << (*objects)[0]->centerPoint.y << std::endl; 
	  camera->target =  (*objects)[0]->centerPoint;
	  //	  std::cout << (*objects)[0]->position.x << " " << (*objects)[0]->position.y << "\n"; //camera->target.x << " " << camera->target.y << std::endl;
	  BeginDrawing();
	  BeginMode2D(*camera);

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


	  EndMode2D();
	  EndDrawing();
	}
}
