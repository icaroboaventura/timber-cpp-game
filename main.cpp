#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main() {
    // Create a video mode object VideoMode vm(1920, 1080);
    const sf::VideoMode vm(sf::Vector2u(1920, 1080));
    // Create and open a window for the game
    sf::RenderWindow window(vm, "Timber!!!", sf::Style::Default);
    return 0;
}


