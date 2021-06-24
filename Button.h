#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <map>
#include <string>

using namespace sf;
using namespace std;

class Button {

protected:

    enum buttonState { withoutActivity = 0, buttonPressed, buttonHovered };

    RectangleShape rect;

    Font font;

    Text text;

    int actualState;

    shared_ptr <RenderWindow> window;

public:

    Button(shared_ptr <RenderWindow> window1, Vector2f positions, Vector2f sizes, Color buttonColor, 
        string fontSource, string message);

    template <class T>
    void drawShape(T graphic);

    void pushFont(string fontSource, string message);

    bool isButtonPressed();
    bool isButtonHovered();
    void resetButton();

    FloatRect getGlobalBounds();
    Vector2f getPosition();
    Vector2f getSize();

    string getText();

    void update();

    void events(Event event);
};

