#include <iostream>

#include "Screen.h"

Screen::Screen(shared_ptr <RenderWindow> window1, Vector2f screenPosition, Vector2f screenSize, Color screenColor, string resultFontSource):
	window(window1){

	screen.setPosition(screenPosition);
	screen.setSize(screenSize);
	screen.setFillColor(screenColor);

	resultFont.loadFromFile(resultFontSource);
	resultText.setFont(resultFont);
	resultText.setFillColor(Color::Black);
	resultText.setStyle(Text::Bold);
	resultText.setCharacterSize(36);

	setTextToScreen("0");
}

void Screen::setTextToScreen(string text) {

	resultText.setString(text);

	resultText.setPosition(screen.getPosition().x + screen.getSize().x - resultText.getGlobalBounds().width - 10,
		screen.getPosition().y + screen.getSize().y / 2 - resultText.getGlobalBounds().height/2 - 10); 
}

void Screen::update() {

	window->draw(screen);
	window->draw(resultText);
}
