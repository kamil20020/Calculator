#include <SFML/Graphics.hpp>

#include "Calculator.h"

using namespace sf;

int main() {

	Vector2f calculatorSize(400, 500);

	Calculator calculator(calculatorSize, Color(220, 220, 220));

	calculator.calculatorLoop();

	return 0;
}