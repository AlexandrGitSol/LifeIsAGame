#include "header.h"

float rb = 10; //sosx кратно rb

Dot::Dot() {
	body.setPointCount(16);
	body.setFillColor(Color(255, 255, 255));
	body.setRadius(rb);
}

void Dot::set_pos(int x, int y) {
	this->x = x;
	this->y = y;
	body.setPosition(x * rb * 2, y * rb * 2);
}

CircleShape Dot::get_body() {
	return body;
}

bool Dot::get_alive() {
	return amalive;
}
void Dot::set_alive(bool l) {
	amalive = l;
	if (amalive) body.setFillColor(Color(0, 0, 0));
	else body.setFillColor(Color(255, 255, 255));
}