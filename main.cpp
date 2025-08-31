#include <iostream>
#include <SFML/Graphics.hpp>
#include <random>


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
    bool beeActive = false;
    float beeSpeed = 0.f;

    // Create a clock for timing everything
    sf::Clock clock;

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

        // Clear everything from the last run frame
        window.clear();

        // Measure time
        sf::Time dt = clock.restart();

        // Setup the bee
        if (!beeActive) {
            // How fast is the bee
            srand((int) time(0));
            beeSpeed = (rand() % 200) + 200;
            // How high is the bee
            srand((int) time(0) * 10);
            float height = (rand() % 500) + 500;
            spriteBee.setPosition(sf::Vector2f(2000.f, height));
            beeActive = true;
        } else {
            spriteBee.setPosition(sf::Vector2f(spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()),
                                               spriteBee.getPosition().y));
            // Has the bee reached the left-hand edge of the screen?
            if (spriteBee.getPosition().x < -100) {
                // Set it up ready to be a whole new bee next frame
                beeActive = false;
            }
        }

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
