#include "Calculator.h"

Calculator::Calculator(Vector2f calculatorSize, Color calculatorColor1): calculatorColor(calculatorColor1){

	window = make_shared <RenderWindow>();
	window->create(VideoMode(calculatorSize.x, calculatorSize.y), "Calculator");
	window->setFramerateLimit(30);

	event = make_shared <Event>();

	Vector2f sizes(290, 60);
	Vector2f positions(window->getSize().x / 2 - sizes.x/2, 50);

	screen = make_shared <Screen>(window, positions, sizes, Color::White, "OpenSans-Regular.ttf");

	Vector2f sizes1(290, 310);
	Vector2f positions1(window->getSize().x / 2 - sizes.x / 2, 150);

	calculatorKeyboard = make_shared <CalculatorKeyboard>(window, event, positions1, sizes1, 
		Color::White, "OpenSans-Regular.ttf");

	engine = make_shared <Engine>(calculatorKeyboard, screen);
}

void Calculator::inLoopEvents() {

	if (event->type == Event::Closed) {

		window->close();
	}

	calculatorKeyboard->inLoopEvents();

	engine->logic();
}

void Calculator::outLoopEvents() {

	calculatorKeyboard->outLoopEvents();
}

void Calculator::update() {

	screen->update();
	calculatorKeyboard->update();
}

void Calculator::calculatorLoop() {

	while(window->isOpen()) {

		while (window->pollEvent(*event)) {

			inLoopEvents();
		}

		window->clear(calculatorColor);

		outLoopEvents();

		update();

		window->display();
	}
}
