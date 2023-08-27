#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

using namespace std;
using namespace sf;

class Showable{

	protected:

	shared_ptr <RenderWindow> window;

	public:

		Showable(shared_ptr <RenderWindow> window1) : window(window1){}

	virtual void update() = 0;
};

