#include "header.h"

Desk::Desk() : desk(SOD, vector<Dot>(SOD)) {
	
	for (int i = 0; i < SOD; i++) {
		for (int j = 0; j < SOD; j++) {
			desk[i][j].set_pos(i-20, j-20);
		}
	}
}

void Desk::draw_desk(RenderWindow& window) {
	for (int i = 0; i < SOD; i++) {
		for (int j = 0; j < SOD; j++) {
			window.draw(desk[i][j].get_body());
		}
	}
}

void Desk::calculating() {
	Desk ans;
	for (int i = 1; i < SOD - 1; i++) {
		for (int j = 1; j < SOD - 1; j++) {
			if (desk[i][j].get_alive()) {
				int countAlive = -1;
				for (int a = -1; a < 2; a++) {
					for (int b = -1; b < 2; b++) {
						if (desk[i + a][j + b].get_alive()) countAlive++;
					}
				}
				if (!(countAlive == 2 || countAlive == 3)) ans.desk[i][j].set_alive(false);
				else ans.desk[i][j].set_alive(true);
			}
			else {
				int countAlive = 0;
				for (int a = -1; a < 2; a++) {
					for (int b = -1; b < 2; b++) {
						if (desk[i + a][j + b].get_alive()) countAlive++;
					}
				}
				if (countAlive == 3) ans.desk[i][j].set_alive(true);
				//else ans.desk[i][j].set_alive(false);
			}
		}
	}
	(*this).desk = ans.desk;
}

//void Desk::operator=(Desk& right) {
//	this->desk = right.desk;
//}

void Desk::rand_oper() {
	for (int i = 0; i < SOD; i++) {
		for (int j = 0; j < SOD; j++) {
			if (rand() % 4 == 1) desk[i][j].set_alive(true);
			else desk[i][j].set_alive(false);
		}
	}
}

vector<vector<Dot>>* Desk::get_desk() {
	return &desk;
}