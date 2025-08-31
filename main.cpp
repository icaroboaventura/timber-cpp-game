#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main() {
    // Define constants
    const float TREE_HORIZONTAL_POSITION = 810.f;
    const float TREE_VERTICAL_POSITION = 0.f;

    // Create a video mode object
    const sf::VideoMode vm(sf::Vector2u(1920, 1080));

    // Create and open a window for the game
    sf::RenderWindow window(vm, "Timber", sf::Style::Default);

    // Create textures to hold a graphic on the GPU
    const sf::Texture textureBackground("background.png");
    const sf::Texture textureTree("tree.png");
    const sf::Texture textureBee("bee.png");
    const sf::Texture textureCloud("cloud.png");

    // Create a sprites for the textures
    sf::Sprite spriteBackground(textureBackground);
    sf::Sprite spriteTree(textureTree);
    sf::Sprite spriteBee(textureBee);
    sf::Sprite spriteCloud1(textureCloud);
    sf::Sprite spriteCloud2(textureCloud);
    sf::Sprite spriteCloud3(textureCloud);

    // Set the sprites to position
    spriteBackground.setPosition(sf::Vector2f(0.f, 0.f));
    spriteTree.setPosition(sf::Vector2f(TREE_HORIZONTAL_POSITION, TREE_VERTICAL_POSITION));
    spriteBee.setPosition(sf::Vector2f(0.f, 800.f));
    spriteCloud1.setPosition(sf::Vector2f(0.f, 0.f));
    spriteCloud2.setPosition(sf::Vector2f(0.f, 250.f));
    spriteCloud3.setPosition(sf::Vector2f(0.f, 500.f));

    // Game variables
    // Is the bee currently moving?
    bool beeActive = false;
    // How fast can the bee fly
    float beeSpeed = 0.f;

    // Start the game loop
    while (window.isOpen()) {
        // Process events
        while (const std::optional event = window.pollEvent()) {
            // Close window: exit
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // Handle the player quitting
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            window.close();
        }

        // Clear everything from the last run frame”
        window.clear();

        // Draw our game scene here
        window.draw(spriteBackground);
        window.draw(spriteTree);
        window.draw(spriteBee);
        window.draw(spriteCloud1);
        window.draw(spriteCloud2);
        window.draw(spriteCloud3);


        // Show everything we just drew
        window.display();
    }
    // End of the game
    return 0;
}
