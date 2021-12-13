#include "raylib.h"

#ifndef _GAMEOBJECT_H
#include "Engine/gameObject.h"
#endif

#define _TEXTBOX_H

class TextBox : public GameObject {
 public:
  TextBox(std::vector<GameObject*> * objects);
  void UIpdate();
  void Display(const char* text, Color color);
  
  bool isDisplaying = false;
private:
  Color currentColor = WHITE;
  const char* currentText = "asdf";

  double cooldown = 0.1;
  double timeToStopDisplaying;
  
};
