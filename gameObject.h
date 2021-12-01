#include <vector>

class GameObject{

public:

  GameObject(){};
  GameObject(std::vector<GameObject*> * objects){
	objects->push_back(this);
  };

  virtual void Start(){};
  virtual void Update(){};

};



