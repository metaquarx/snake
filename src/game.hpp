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

#ifndef snake_game_hpp
#define snake_game_hpp

#include <SFML/Graphics.hpp>

#include "snake.hpp"

class game {
public:
	game();

	bool run();

	int end();

private:
	unsigned width;
	unsigned height;

	sf::RenderWindow wnd;

	unsigned scale;
	snake s;

	sf::Vector2f food;

	void reset_food();
};

#endif	// snake_game_hpp
