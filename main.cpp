#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main() {
    // Create a video mode object
    const sf::VideoMode vm(sf::Vector2u(1920, 1080));
    // Create and open a window for the game
    sf::RenderWindow window(vm, "Timber", sf::Style::Default);
    // Create a texture to hold a graphic on the GPU
    sf::Texture textureBackground;
    // Load a graphic into the texture
    if (!textureBackground.loadFromFile("background.png")) {
        return -1;
    }
    // Create a sprite
    sf::Sprite spriteBackground(textureBackground);
    // Attach the texture to the sprite
    spriteBackground.setTexture(textureBackground);
    // Set the sprite to the top left corner
    spriteBackground.setPosition(sf::Vector2f(0.f, 0.f));
    // Start the game loop
    while (window.isOpen()) {
        // Create an event object
        while (const std::optional<sf::Event> event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
        // Handle the player quitting
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            window.close();
        }
        // Clear everything from the last run frame”
        window.clear();
        // Draw our game scene here
        window.draw(spriteBackground);
        // Show everything we just drew
        window.display();
    }
    // End of the game
    return 0;
}
