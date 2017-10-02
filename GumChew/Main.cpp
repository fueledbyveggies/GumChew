#include <SFML/Graphics.hpp>

enum WindowAction
{
	None,
	Closed,
	Resized
};

bool keyDown(sf::Keyboard::Key key) {
	return sf::Keyboard::isKeyPressed(key);
}

bool handleInput() {
	if (keyDown(sf::Keyboard::A)) {
		return true;
	}
	return false;
}

bool handleWindowEvents(sf::RenderWindow *app, sf::Event lastEvent) {
	switch (lastEvent.type)
	{
	case sf::Event::Closed:
		app->close();
		return true;
	}
	return false;
}

int main() {
	sf::RenderWindow *app = new sf::RenderWindow(sf::VideoMode(1202, 557), "GuM ChEW!!!!");
	app->setVerticalSyncEnabled(true);
	bool running = true;
	sf::Event lastEvent;

	sf::Image mainImage = sf::Image();
	mainImage.loadFromFile("content\\graphics\\THEBESTGAMEEVER.png");

	sf::Texture bgTexture = sf::Texture();
	bgTexture.loadFromImage(mainImage);

	sf::Sprite background = sf::Sprite();
	background.setTexture(bgTexture);

	sf::Texture mouthTexture = sf::Texture();
	mouthTexture.loadFromImage(mainImage, sf::IntRect(600, 280, 100, 40));

	sf::Sprite mouthClosed = sf::Sprite();
	mouthClosed.setTexture(mouthTexture);
	mouthClosed.setPosition(600, 240);

	bool lastInput = false;
	

	while (running) {
		app->clear(sf::Color::Cyan);

		app->pollEvent(lastEvent);

		if (handleWindowEvents(app, lastEvent)) {
			running = false;
		}

		if (keyDown(sf::Keyboard::Escape)) {
			running = false;
		}

		app->draw(background);

		if (handleInput()) {
			app->draw(mouthClosed);
		}
		app->display();
	}

	return 0;
}
