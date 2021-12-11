#ifndef _GAMEOBJECT_H
#include "gameObject.h"
#endif

#define _INTERACTABLE_H

class Interactable : public GameObject {
 public:
  Interactable(){
	hasColliderPoints = true;
  };
  Interactable(GameObject& object){
	
  };
  virtual void OnInteract(){};
  std::vector<Vector2> points;
};
