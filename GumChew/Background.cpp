#include "Background.h"


Background::Background(const sf::Vector2f position, const sf::Image image) {
	this->position = position;
	this->texture.loadFromImage(image);
}

void Background::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	target.draw(*this, states);
}
