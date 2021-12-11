#include "level.h"

Level::Level(
			 std::vector<GameObject*> * _objects,
			 const char* _background_path,
			 Camera2D * _camera
			 )
{
  objects = _objects;
  background = LoadTexture(_background_path); 
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
	  camera->target =  (*objects)[(*objects).size()-1]->centerPoint;
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
