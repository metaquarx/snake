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

#include "maths.hpp"

float dist(float x1, float y1, float x2, float y2) {
	auto dx = x1 - x2;
	auto dy = y1 - y2;
	return std::sqrt(dx * dx + dy * dy);
}

float constrain(float val, float min, float max) {
	if (val > max) {
		return max;
	}

	if (val < min) {
		return min;
	}

	return val;
}
