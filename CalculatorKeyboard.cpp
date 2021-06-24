#include <iostream>
#include <math.h>

#include "CalculatorKeyboard.h"

CalculatorKeyboard::CalculatorKeyboard(shared_ptr <RenderWindow> window1, shared_ptr <Event> event1, 
	Vector2f keyboardPosition, Vector2f keyboardSize, Color keyboardColor, string buttonsFontSource): 
	Showable(window1), event(event1){

	background.setPosition(keyboardPosition);
	background.setSize(keyboardSize);
	background.setFillColor(keyboardColor);

	createButtons(buttonsFontSource);

	clickedButton = nullptr;
}

void CalculatorKeyboard::createButtons(string buttonsFontSource) {

	Vector2f sizes(60, 50);

	Vector2f positions(background.getPosition().x + 10, background.getPosition().y + 10);

	buttons["C"] = make_shared <Button>(window, positions, sizes, Color(220, 220, 220), buttonsFontSource, "C");


	Vector2f positions10(positions.x + sizes.x + 10, background.getPosition().y + 10);

	buttons["^2"] = make_shared <Button>(window, positions10, sizes, Color(220, 220, 220), buttonsFontSource, "^2");


	Vector2f positions11(positions10.x + sizes.x + 10, background.getPosition().y + 10);

	buttons["^1/2"] = make_shared <Button>(window, positions11, sizes, Color(220, 220, 220), buttonsFontSource, "^1/2");


	Vector2f positions9(background.getPosition().x + background.getSize().x - 10 - sizes.x, background.getPosition().y + 10);

	buttons["/"] = make_shared <Button>(window, positions9, sizes, Color(220, 220, 220), buttonsFontSource, "/");


	Vector2f positions1(background.getPosition().x + 10, background.getPosition().y + 10 + sizes.x);

	int range = 9;

	for (int j = 1; j < 4; j++) {

		for (int i = 9 - 3*j + 1; i <= range; i++) {

			buttons[to_string(i)] = make_shared <Button>(window, positions1, sizes, Color(220, 220, 220), buttonsFontSource, to_string(i));

			positions1.x = positions1.x + 10 + sizes.x;
		};

		positions1.x = background.getPosition().x + 10;

		positions1.y = positions1.y + 10 + sizes.y;

		range = range - 3;
	}

	Vector2f positions2(buttons["9"]->getPosition().x + 10 + sizes.x, buttons["9"]->getPosition().y);

	buttons["x"] = make_shared <Button>(window, positions2, sizes, Color(220, 220, 220), buttonsFontSource, "x");


	Vector2f positions3(buttons["x"]->getPosition().x, buttons["x"]->getPosition().y + sizes.y + 10);

	buttons["-"] = make_shared <Button>(window, positions3, sizes, Color(220, 220, 220), buttonsFontSource, "-");


	Vector2f positions4(buttons["x"]->getPosition().x, buttons["-"]->getPosition().y + sizes.y + 10);

	buttons["+"] = make_shared <Button>(window, positions4, sizes, Color(220, 220, 220), buttonsFontSource, "+");


	Vector2f positions5(buttons["x"]->getPosition().x, buttons["+"]->getPosition().y + sizes.y + 10);

	buttons["="] = make_shared <Button>(window, positions5, sizes, Color(220, 220, 220), buttonsFontSource, "=");


	Vector2f positions6(buttons["x"]->getPosition().x - sizes.x - 10, buttons["="]->getPosition().y);

	buttons[","] = make_shared <Button>(window, positions6, sizes, Color(220, 220, 220), buttonsFontSource, ",");


	Vector2f positions7(buttons[","]->getPosition().x - sizes.x - 10, buttons["="]->getPosition().y);

	buttons["0"] = make_shared <Button>(window, positions7, sizes, Color(220, 220, 220), buttonsFontSource, "0");


	Vector2f positions8(buttons["0"]->getPosition().x - sizes.x - 10, buttons["="]->getPosition().y);

	buttons["+/-"] = make_shared <Button>(window, positions8, sizes, Color(220, 220, 220), buttonsFontSource, "+/-");
}

shared_ptr <Button> CalculatorKeyboard::returnClickedButton() {

	return clickedButton;
}

void CalculatorKeyboard::inLoopEvents() {

	map <string, shared_ptr <Button>>::iterator it;

	for (it = buttons.begin(); it != buttons.end(); it++) {

		it->second->events(*event);

		if (it->second->isButtonPressed()) {

			clickedButton = it->second;

			break;
		}
	}
}

void CalculatorKeyboard::resetClickedButton() {

	clickedButton->resetButton();

	clickedButton = nullptr;
}

void CalculatorKeyboard::outLoopEvents() {


}

void CalculatorKeyboard::update() {

	window->draw(background);

	map <string, shared_ptr <Button>>::iterator it;

	for (it = buttons.begin(); it != buttons.end(); it++) {

		it->second->update();
	}
}
