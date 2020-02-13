#include <SFML/Graphics.hpp>
//#include <SFML/Window/Keyboard.hpp>

#include <iostream>


const unsigned int FPS = 60;
const unsigned int WIDTH = 800;
const unsigned int HEIGHT = 600;

int main()
{

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Hello");
    window.setFramerateLimit(FPS);

    sf::CircleShape circle(10.0f);
    circle.setOrigin(10.0f, 10.0f);
    circle.setPosition(0.0f, 150.0f);

    sf::Texture texture;
    texture.loadFromFile("ball.png");

    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);
    sprite.setScale(0.1f, 0.1f);

    sf::Event ev;
    while (window.isOpen())
    {
        while (window.pollEvent(ev))
        {
            std::cout << ev.type << std::endl;
            switch (ev.type) {
                case sf::Event::Closed: {
                    window.close();
                    break;
                }
                case sf::Event::MouseButtonPressed : {
                    sprite.setPosition(ev.mouseButton.x, ev.mouseButton.y);
                    break;
                }
                case sf::Event::KeyPressed: {
                    sf::Vector2f moveVec(0.0f, 0.0f);
                    bool move = false;
                    switch (ev.key.code) {
                    case sf::Keyboard::Key::Left:
                        move = true;
                        moveVec.x = -10.f;
                        break;
                    case sf::Keyboard::Key::Right:
                        move = true;
                        moveVec.x = 10.f;
                        break;
                    case sf::Keyboard::Key::Up:
                        move = true;
                        moveVec.y = -10.f;
                        break;
                    case sf::Keyboard::Key::Down:
                        move = true;
                        moveVec.y = 10.f;
                        break;
                    }
                    sprite.move(moveVec);
                    break;
                }
            }
        }
        circle.move(1.0f, 0.0f);

        window.clear();
        window.draw(sprite);
        window.display();
    }
}