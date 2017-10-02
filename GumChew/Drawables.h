#pragma once

#include <map>
#include <string>
#include "Drawable.h"

static class Drawables {
public:
	Drawables();
	~Drawables();
	bool Put(Drawable *drawable);

private:
	std::map<std::string, Drawable*> drawables;
};
