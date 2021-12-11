#include <vector>
#include <raylib.h>

#define _GAMEOBJECT_H

class GameObject{

public:

  GameObject(){};
  GameObject(std::vector<GameObject*> * objects){
	objects->push_back(this);
  };

  virtual void Start(){};
  virtual void Update(){};

  struct Vector2 centerPoint;

  bool hasColliderPoints = false;

};



