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

#include "main.hpp"

#include "game.hpp"

int main() {
	game snake_game;

	while (snake_game.run()) {
	}

	return snake_game.end();
}
