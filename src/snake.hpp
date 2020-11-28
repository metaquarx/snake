// Copyright 2020 metaquarx, metaquarx@pm.me

//  This file is part of Snake.
//
//  Snake is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  Snake is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with Snake.  If not, see <https://www.gnu.org/licenses/>.

#ifndef snake_snake_hpp
#define snake_snake_hpp

#include <vector>

#include <SFML/Graphics.hpp>

class snake : public sf::Drawable {
public:
	snake(unsigned scl);

	bool eat(sf::Vector2f);
	void dir(float x, float y);
	void death();
	void update(float width, float height);

	virtual void draw(sf::RenderTarget &target,
					  sf::RenderStates states) const override;

private:
	float x;
	float y;
	float xspeed;
	float yspeed;

	unsigned scale;

	unsigned total;

	std::vector<sf::Vector2f> tail;
};

#endif	// snake_snake_hpp
