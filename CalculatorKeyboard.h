#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <map>

#include "Showable.h"

#include "Button.h"

using namespace std;
using namespace sf;

class CalculatorKeyboard: public Showable{

	private:

	shared_ptr <Event> event;

	RectangleShape background;

	map <int, string> buttonsRules;

	map <string, shared_ptr <Button>> buttons;
	shared_ptr <Button> clickedButton;

	float firstPut = 0;
	float secondPut = 0;

	float result = 0;

	public:

	CalculatorKeyboard(shared_ptr <RenderWindow> window1, shared_ptr <Event> event1, 
		Vector2f keyboardPosition, Vector2f keyboardSize, 
		Color keyboardColor, string buttonsFontSource);

	void createButtons(string buttonsFontSource);
	shared_ptr <Button> returnClickedButton();
	void resetClickedButton();

	void inLoopEvents();
	void outLoopEvents();

	void update();

};

