#include <string>
#include <iostream>
#include <math.h>
#include <sstream>

#include "Engine.h"

Engine::Engine(shared_ptr <CalculatorKeyboard> calculatorKeyboard1, shared_ptr <Screen> screen1): 
	calculatorKeyboard(calculatorKeyboard1),  screen(screen1){

	actualState = firstNumberPuted;

	firstPut = "0";
}

void Engine::logicForSign(string name) {

	if (actualState == firstNumberPuted || actualState == signPuted) {

		if (name == "^2" || name == "^1/2") {

			actualState = secondNumberPuted;
		}
		else {

			actualState = signPuted;
		}

		screen->setTextToScreen(name);

		sign = name;
	}
}

void Engine::logicForResult() {

	float covertedFirstPut = stof(firstPut);
	float covertedSecondPut = stof(secondPut);

	float result = 0;

	if (sign == "+") {

		result = covertedFirstPut + covertedSecondPut;
	}
	else if (sign == "-") {

		result = covertedFirstPut - covertedSecondPut;
	}
	else if (sign == "x") {

		result = covertedFirstPut * covertedSecondPut;
	}
	else if (sign == "/") {

		result = covertedFirstPut / covertedSecondPut;
	}
	else if (sign == "^2") {

		result = covertedFirstPut * covertedFirstPut;
	}
	else if (sign == "^1/2") {

		result = sqrt(covertedFirstPut);
	}

	string convertedResult = returnStringNumber(result);

	logicForNumberSize(convertedResult);

	actualState = firstNumberPuted;

	firstPut = convertedResult;
	secondPut = "0";
}

bool Engine::checkDoResultHigherThanFloatLimit(float result) {

	if (result <= -99999999 || result >= 99999999) {

		return true;
	}

	return false;
}

string Engine::returnStringNumber(float result) {

	std::ostringstream oss;

	oss << result;

	string bufor = oss.str();

	return bufor;
}

void Engine::logicForNumberSize(string result) {

	if (!checkDoResultHigherThanFloatLimit(stof(result))) {

		if (result.length() > 12) {

			string bufor = result;

			while (bufor.length() > 12)
				bufor.pop_back();

			screen->setTextToScreen(bufor);
		}
		else {

			screen->setTextToScreen(result);
		}
	}
	else {

		actualState = normaly;

		firstPut = "0";
		secondPut = "0";

		screen->setTextToScreen("Number too big");
	}
}

bool Engine::checkDoNumberIsFloat(float result) {

	if (result == int(result)) {

		return false;
	}

	return true;
}

void Engine::logicForClickButton(string name) {

	if (name == "C") {

		screen->setTextToScreen("0");

		actualState = normaly;

		firstPut = "0";

		secondPut = "0";

	}
	else if (name >= "0" && name <= "9") {

		string result = "0";

		if (actualState == secondNumberPuted) {

			string bufor;

			if (commaPuted) {

				bufor = secondPut + "." + name;

				commaPuted = false;
			}
			else{

				if (secondPut != "0") {

					bufor = secondPut + name;
				}
				else {

					bufor = name;
				}
			}

			secondPut = bufor;

			result = secondPut;
		}
		else if(actualState == signPuted){

			actualState = secondNumberPuted;

			secondPut = name;

			result = secondPut;
		}
		else if (actualState == firstNumberPuted) {

			string bufor;

			if (commaPuted) {

				bufor = firstPut + "." + name;

				commaPuted = false;
			}
			else{

				if (firstPut != "0") {

					bufor = firstPut + name;
				}
				else {

					bufor = name;
				}
			}

			firstPut = bufor;

			result = firstPut;

		}
		else if(actualState == normaly){

			actualState = firstNumberPuted;

			firstPut = name;

			result = firstPut;
		}

		logicForNumberSize(result);
	}
	else if (name == "/" || name == "x" || name == "-" || name == "+" || name == "^2" || name == "^1/2") {

		logicForSign(name);
	}
	else if (name == "=") {

		if (actualState == secondNumberPuted) {

			logicForResult();
		}
	}
	else if (name == ",") {

		float result = 0;

		bool doPutComma = false;

		if (actualState == firstNumberPuted) {

			float convertedFirstPut = stof(firstPut);
			if (!checkDoNumberIsFloat(convertedFirstPut)) {

				result = convertedFirstPut;

				doPutComma = true;
			}
		}
		else if (actualState == secondNumberPuted) {

			float covertedSecondPut = stof(secondPut);

			if (!checkDoNumberIsFloat(covertedSecondPut)) {

				result = covertedSecondPut;

				doPutComma = true;
			}
		}

		if (doPutComma) {

			screen->setTextToScreen(returnStringNumber(result) + ".");

			commaPuted = true;
		}
	}
	else if (name == "+/-") {

		if (actualState == firstNumberPuted) {

			if (firstPut != "0") {

				if (firstPut[0] != '-') {

					firstPut = "-" + firstPut;
				}
				else {

					firstPut.erase(firstPut.begin());
				}

				screen->setTextToScreen(firstPut);
			}
		}
		else if(actualState == secondNumberPuted){

			if (secondPut != "0") {

				if (secondPut[0] != '-') {

					secondPut = "-" + secondPut;
				}
				else {

					secondPut.erase(secondPut.begin());
				}

				screen->setTextToScreen(secondPut);
			}
		}
	}

	calculatorKeyboard->resetClickedButton();
}

void Engine::logic() {

	if (calculatorKeyboard->returnClickedButton() != nullptr) {

		logicForClickButton(calculatorKeyboard->returnClickedButton()->getText());
	}
}
