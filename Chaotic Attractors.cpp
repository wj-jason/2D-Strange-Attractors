#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <stdio.h>

void FractalDreamAttractor(sf::VertexArray &particles) {

    // x and y both start at 0.1
    // a, b -> [-3, +3]
    // c, d -> [-0.5, 1.5]
    float x = 0.1, y = 0.1,
        a = -0.966918,
        b = 2.879879,
        c = 0.765145,
        d = 0.744728;

    const int initialIterations = 100,
        iterations = 10000000;

    for (int i = 0; i < initialIterations; ++i) {

        float xNew = sin(y * b) + c * sin(x * b);
        float yNew = sin(x * a) + d * sin(y * a);

        x = xNew;
        y = yNew;
    }

    for (int i = 0; i < iterations; ++i) {

        float xNew = sin(y * b) + c * sin(x * b);
        float yNew = sin(x * a) + d * sin(y * a);

        x = xNew;
        y = yNew;

        particles.append(sf::Vertex(sf::Vector2f(x, y)));
    }
}

void CliffordAttractor(sf::VertexArray &particles) {

    // x and y both start at 0.1
    // a, b, c, d -> [-3, 3]
    float x = 0.1, y = 0.1,
        a = -1.7,
        b = 1.3,
        c = -0.1,
        d = -1.21;

    const int initialIterations = 100,
        iterations = 10000000;

    for (int i = 0; i < initialIterations; ++i) {

        float xNew = sin(a * y) + c * cos(a * x);
        float yNew = sin(b * x) + d * cos(b * y);

        x = xNew;
        y = yNew;
    }

    for (int i = 0; i < iterations; ++i) {

        float xNew = sin(a * y) + c * cos(a * x);
        float yNew = sin(b * x) + d * cos(b * y);

        x = xNew;
        y = yNew;

        particles.append(sf::Vertex(sf::Vector2f(x, y)));
    }
}

void BedheadAttractor(sf::VertexArray &particles) {
    // x and y both start at 1
    // a, b, -> [-1, 1]
    float x = 1.0, y = 1.0,
        a = 0.65343,
        b = 0.7345345;

    const int initialIterations = 100,
        iterations = 10000000;

    for (int i = 0; i < initialIterations; ++i) {

        float xNew = sin(x * y / b) * y + cos(a * x - y);
        float yNew = (x + sin(y) / b);

        x = xNew;
        y = yNew;
    }

    for (int i = 0; i < iterations; ++i) {

        float xNew = sin(x * y / b) * y + cos(a * x - y);
        float yNew = x + sin(y) / b;

        x = xNew;
        y = yNew;

        particles.append(sf::Vertex(sf::Vector2f(x, y)));
    }

}

int main()
{
    // window settings and viewport intialization
    sf::RenderWindow window(sf::VideoMode(1600, 1600), "Chaotic Attractors");
    // sf::RenderWindow textWindow(sf::VideoMode(1000, 500), "Information");
    window.setFramerateLimit(60);
    // textWindow.setFramerateLimit(60);

    // text settings
    sf::Font font;
    font.loadFromFile("C:\\Users\\jason\\Desktop\\Merriweather\\Merriweather - Light.ttf");
    sf::Text text;
    text.setFont(font);
    text.setPosition(100, 100);
    text.setFillColor(sf::Color::Green);
    text.setString("Inital x:");


    sf::Vector2f origin(0.0f, 0.0f);

    // set based on attractor
    //-axis.x/2 -> +axis.x/2
    //-axis.y/2 -> +axis.y/2
    sf::Vector2f axis(12, 12); 

    sf::View view(origin, axis);
    window.setView(view);

    // main loop
    bool control = true;
    sf::VertexArray particles(sf::Points);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
        }

        window.clear();
        
        if (control) {
            BedheadAttractor(particles);
            control = false;
        }

        window.draw(particles);
        // textWindow.draw(text);
        window.display();
    }

    return 0;
}