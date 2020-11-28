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

#include "game.hpp"

#include <cstdlib>

game::game()
  : width(600), height(600), wnd(sf::VideoMode(width, height), "Snake"),
	scale(20), s(scale) {
	wnd.setFramerateLimit(10);
	reset_food();
}

bool game::run() {
	sf::Event event;
	while (wnd.pollEvent(event)) {
		switch (event.type) {
			case sf::Event::Closed: wnd.close(); break;
			case sf::Event::KeyPressed:
				switch (event.key.code) {
					case sf::Keyboard::Up: s.dir(0, -1); break;
					case sf::Keyboard::Down: s.dir(0, 1); break;
					case sf::Keyboard::Right: s.dir(1, 0); break;
					case sf::Keyboard::Left: s.dir(-1, 0); break;
				}
		}
	}
	wnd.clear(sf::Color(51, 51, 51));

	if (s.eat(food)) {
		reset_food();
	}

	s.death();
	s.update(static_cast<float>(width), static_cast<float>(height));
	wnd.draw(s);

	sf::RectangleShape rect;
	rect.setFillColor(sf::Color(255, 0, 100));
	rect.setSize(
	  sf::Vector2f(static_cast<float>(scale), static_cast<float>(scale)));
	rect.setPosition(food);
	wnd.draw(rect);

	wnd.display();
	return wnd.isOpen();
}

int game::end() {
	return 0;
}

void game::reset_food() {
	unsigned cols = width / scale;
	unsigned rows = height / scale;

	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	food = {static_cast<float>(static_cast<unsigned>(rand()) % cols * scale),
			static_cast<float>(static_cast<unsigned>(rand()) % rows * scale)};
}
