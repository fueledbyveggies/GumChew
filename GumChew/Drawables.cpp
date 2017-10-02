#include "Drawables.h"

Drawables::Drawables() {
}


Drawables::~Drawables() {
}

bool Drawables::Put(Drawable *drawable) {
	this->drawables[drawable->getID()] = drawable;
	return true;
}
