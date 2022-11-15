#pragma once
#ifndef TRIANGLE
#define TRIANGLE
#endif // !TRIANGLE

#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

class BIG_COORD
{
private:
	double x;

	double y;

	void protection(istream& c)const;

public:
	BIG_COORD(double x ,double y):x(x),y(y){}

	BIG_COORD():x(0),y(0) {}

	double get_x()const { return x; }

	double get_y()const { return y; }

	void set(double tx, double ty) { x = tx; y = ty; }

	friend istream& operator>>(istream& c, BIG_COORD& b);

	friend ostream& operator<<(ostream& c, const BIG_COORD& t);
};

class triangle
{
protected:
	static const  unsigned int VERTICES= 3;

	BIG_COORD coor[VERTICES];

	double Len(const  BIG_COORD& cor1, const  BIG_COORD& cor2)const;
	
public:
	triangle(BIG_COORD a, BIG_COORD b, BIG_COORD c) { coor[0] = a; 
		coor[1] = b; coor[2] = c; }
	triangle() :triangle(BIG_COORD(), BIG_COORD(), BIG_COORD()) {}

	void put();

	const  BIG_COORD* get_coord()const;

	double get_per()const;

	double get_area()const;

	friend ostream & operator<<(ostream & c, const triangle& t);

	friend istream & operator>>(istream & c,  triangle& t);
};


	