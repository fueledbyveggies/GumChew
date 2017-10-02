#pragma once

#include <SFML/Graphics.hpp>

class Background : public sf::Drawable {
public:
	sf::Vector2f position;
	Background(const sf::Vector2f position, const sf::Image image);
protected:
	sf::Texture texture;
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
private:
};
