#include "lab2_t.h"

void triangle::put()
{
	cin >> *this;
}

double triangle::get_per()const
{
	return Len(coor[0], coor[1]) + Len(coor[0], coor[2]) + Len(coor[1], coor[2]);
}
double triangle::Len(const  BIG_COORD& cor1, const  BIG_COORD& cor2)const
{
	return sqrt(pow(cor2.get_x() - cor1.get_x(), 2.0) + pow(cor2.get_y() - cor1.get_y(), 2.0));
}
void BIG_COORD::protection(istream& c)const
{
	cin.clear();
	cin.ignore(20, '\n');
	cout << " incorrect type, try again\n";
}

double triangle::get_area()const
{
	double hp = get_per() / 2;
	return sqrt(hp * (hp - Len(coor[0], coor[1])) *
		(hp - Len(coor[1], coor[2])) * (hp - Len(coor[0], coor[2])));
}

const  BIG_COORD* triangle::get_coord()const { return coor; }

ostream& operator<<(ostream& c, const triangle& t)
{
	 c << "    COORDINATE: \n"<<"        X:        Y:"<<endl;
	 for (int i = 0; i < t.VERTICES; i++)
	 {
		 c << t.get_coord()[i]; 
	 }
	 
	 c << setw(10) << "PERIMETR" << setw(10) <<   "AREA" << endl;
	 c << setw(10) << t.get_per() << setw(10) << t.get_area() << endl;
	 c << "--------------------" << endl;
	 return c;
}

istream& operator>>(istream& c,  triangle& t)
 {
	for (int i = 0; i < t.VERTICES; i++)
	{
		while (true)
		{
			cout << "the "<<i+1<<" peak's coordinates are: ";
			cin >> t.coor[i];
			break;
		}
	}
	 return c;
 }

ostream& operator<<(ostream& c, const BIG_COORD& b)
{
	c << setw(10)<<b.x << setw(10) << b.y << endl;
	return c;
}

istream& operator>>(istream& c, BIG_COORD& b)
{

	while (true)
	{
		cin >> b.x;
		if (!cin.good()) { b.protection(cin); continue; }
		cin >> b.y;
		if (!cin.good()) { b.protection(cin); continue; }
		break;
	}
	return c;
}

