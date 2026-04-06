#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include <iostream>
using namespace sf;
using namespace std;;
RenderWindow window(VideoMode(900, 504), "Flappy Bird");
struct GUI {
    Sprite sprite;
    Texture texture;
} bird,background1,base1,base2;
const int y=425;
float baseVelocity=100;
int flappingIndex=0;
void startGame() {
    window.setFramerateLimit(60);
    background1.texture.loadFromFile("assets/backgroundd.png");
    bird.texture.loadFromFile("assets/bird.png");
    base1.texture.loadFromFile("assets/basee.png");
    background1.sprite.setTexture(background1.texture);
    base1.sprite.setTexture(base1.texture);
    base2.sprite.setTexture(base1.texture);
    bird.sprite.setTexture(bird.texture);
    bird.sprite.setPosition(200,200);
    base1.sprite.setPosition(0,y);
      base2.sprite.setPosition(base1.texture.getSize().x,y);
    Vector2i position=Mouse::getPosition(window);
}
void movingGround(Time &dt) {
    base1.sprite.move(-baseVelocity*dt.asSeconds(),0);
    base2.sprite.move(-baseVelocity*dt.asSeconds(),0);
    if (base1.sprite.getPosition().x + base1.sprite.getGlobalBounds().width<0) {
        base1.sprite.setPosition(base2.sprite.getPosition().x + base2.sprite.getGlobalBounds().width,y);
    }
    if (base2.sprite.getPosition().x + base2.sprite.getGlobalBounds().width<0) {
        base2.sprite.setPosition(base1.sprite.getPosition().x + base1.sprite.getGlobalBounds().width,y);
    }
}
void update() {
    bird.sprite.setTextureRect(IntRect(flappingIndex*54, 0, 54, 56));
    flappingIndex=(flappingIndex+1)%2;
}
int main() {
    Clock clock;
    startGame();
    while (window.isOpen()) {
        sf:: Time dt= clock.restart();
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed) {
                if (event.key.code==Keyboard::Key::Escape)
                    window.close();
            }
            if (event.type == Event::Resized) {
                View view(FloatRect(0, 0, 900, 504));
                window.setView(view);
            }
        }
        update();
        movingGround(dt);
        window.clear();
        window.draw(background1.sprite);
        window.draw(bird.sprite);
        window.draw(base1.sprite);
        window.draw(base2.sprite);
        window.display();
    }
    }
