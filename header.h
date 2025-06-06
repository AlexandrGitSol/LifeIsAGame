#ifndef HEADER_H
#define HEADER_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <vector>
#include <random>
#include <ctime>
#include <thread>
using namespace sf;
using namespace std;

#define SOD (int((sosx/rb/2)+40))

extern float rb;
extern int sosx, sosy;

class Dot;

class Desk {
	vector<vector<Dot>> desk;
public:
	Desk();
	void draw_desk(RenderWindow& window);
	void calculating();
	//void operator=(Desk& right);
	void rand_oper();
	vector<vector<Dot>>* get_desk();
	void calc_thread(int block);
};

class Dot {
	int x, y;
	bool amalive = false;
	CircleShape body;
public:
	Dot();
	void set_pos(int x, int y);
	CircleShape get_body();
	bool get_alive();
	void set_alive(bool l);
};


#endif // HEADER_H
