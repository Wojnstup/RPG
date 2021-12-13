#include "textbox.h"

TextBox::TextBox(std::vector<GameObject*> * objects)
{
  objects->push_back(this);
}

void TextBox::UIpdate()
{
  if (isDisplaying)
	{
	  DrawRectangle(0,500,1080,220,BLACK);
	  DrawText(currentText, 50, 550, 20, currentColor);
	  if(IsKeyPressed(KEY_SPACE) && timeToStopDisplaying < GetTime())
		isDisplaying = false;
	}
 
}

void TextBox::Display(const char* text, Color color)
{
  isDisplaying = true;
  currentColor = color;
  currentText = text;

  timeToStopDisplaying = GetTime() + cooldown;
}
