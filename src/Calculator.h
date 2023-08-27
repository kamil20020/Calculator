#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "Screen.h"
#include "Engine.h"
#include "CalculatorKeyboard.h"

using namespace std;
using namespace sf;

class Calculator{

	shared_ptr <RenderWindow> window;
	shared_ptr <Event> event;

	shared_ptr <Screen> screen;
	shared_ptr <CalculatorKeyboard> calculatorKeyboard;
	shared_ptr <Engine> engine;

	Color calculatorColor;

public:

	Calculator(Vector2f calculatorSize, Color calculatorColor);

	void inLoopEvents();
	void outLoopEvents();

	void calculatorLoop();

	void update();

};

