#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

using namespace std;
using namespace sf;

class Screen{

	shared_ptr <RenderWindow> window;
	shared_ptr <Event> event;

	RectangleShape screen;

	Font resultFont;

	Text resultText;

public:

	Screen(shared_ptr <RenderWindow> window, Vector2f screenPosition, 
		Vector2f screenSize, Color screenColor, string resultFont1);

	void setTextToScreen(string resultText);

	void update();
};

