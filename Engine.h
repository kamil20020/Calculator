#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "Screen.h"
#include "CalculatorKeyboard.h"

using namespace sf;
using namespace std;

class Engine{

	enum calculatorStates { normaly = 0, firstNumberPuted, signPuted, secondNumberPuted };

	string firstPut = "0";
	string sign;
	string secondPut = "0";

	bool commaPuted = false;

	int actualState;

	shared_ptr <CalculatorKeyboard> calculatorKeyboard;
	shared_ptr <Screen> screen;

	public:

	Engine(shared_ptr <CalculatorKeyboard> calculatorKeyboard, shared_ptr <Screen> screen);

	void logicForClickButton(string name);
	void logicForSign(string name);
	string returnStringNumber(float result);
	void logicForNumberSize(string result);
	bool checkDoResultHigherThanFloatLimit(float result);
	bool checkDoNumberIsFloat(float result);
	void logic();
	void logicForResult();
};

