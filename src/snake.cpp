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

#include "snake.hpp"

#include "maths.hpp"

snake::snake(unsigned scl)
  : x(0), y(0), xspeed(1), yspeed(0), scale(scl), total(0) {}

bool snake::eat(sf::Vector2f pos) {
	float d = dist(x, y, pos.x, pos.y);
	if (d < 1) {
		total++;
		return true;
	}
	return false;
}

void snake::dir(float x_, float y_) {
	xspeed = x_;
	yspeed = y_;
}

void snake::death() {
	for (std::size_t i = 0; i < tail.size(); i++) {
		auto pos = tail[i];
		auto distance = dist(x, y, pos.x, pos.y);
		if (distance < 1.0f) {
			// Dead
			total = 0;
			tail.clear();
		}
	}
}

void snake::update(float width, float height) {
	if (total > 0) {
		if (total == tail.size()) {
			tail.erase(tail.begin());
		}
		tail.push_back(sf::Vector2f(x, y));
	}

	x = x + xspeed * static_cast<float>(scale);
	y = y + yspeed * static_cast<float>(scale);

	x = constrain(x, 0, width - static_cast<float>(scale));
	y = constrain(y, 0, height - static_cast<float>(scale));
}

void snake::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	sf::RectangleShape rect;
	rect.setFillColor(sf::Color::White);
	rect.setSize(
	  sf::Vector2f(static_cast<float>(scale), static_cast<float>(scale)));

	for (const auto &v : tail) {
		rect.setPosition(v.x, v.y);
		target.draw(rect, states);
	}

	rect.setPosition(x, y);
	target.draw(rect, states);
}
