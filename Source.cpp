#include<stdio.h>


#include<stdlib.h>

#include <math.h>
#include <set>
#include <algorithm>
#include <time.h>
#include <iostream>

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include "../ConsoleApplication2/lab2_t.h"
using namespace std;
////main
#include <iostream>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <utility>

int main()
{

    return 0;
}




namespace lab2san{

class point
{
public:
    double getX() const;
    void setX(double x);
    double getY() const;
    void setY(double y);

    point(double x, double y);
    point(double x);
    point();

    void setter(double x, double y);
    double distance(const point& _point)const;
    bool operator == (const point& _point) const;
    bool operator <  (const point& _point) const;
    point operator-(const point& p)const
    {
        double x = this->getX() - p.getX();
        double y = this->getY() - p.getY();
        return point(x, y);
    }
    point operator+(const point& p)const
    {
        double x = this->getX() + p.getX();
        double y = this->getY() + p.getY();
        return point(x, y);
    }
    point operator*(double z)const
    {
        double xx = this->getX() * z;
        double yy = this->getY() * z;
        return point(xx, yy);
    }

private:
    double _x;
    double _y;
};


double point::getX() const
{
    return _x;
}

void point::setX(double x)
{
    _x = x;
}

double point::getY() const
{
    return _y;
}

void point::setY(double y)
{
    _y = y;
}

point::point(double x, double y) : _x(x), _y(y) {}
point::point(double x) : _x(x), _y(x) {}
point::point() : point(0) {}

void point::setter(double x, double y)
{
    _x = x;
    _y = y;
}

double point::distance(const point& _point)const
{
    return sqrt(pow(getX() - _point.getX(), 2) + pow(getY() - _point.getY(), 2));
}

bool point::operator==(const point& _point) const
{
    return (getX() == _point.getX()) && (getY() == _point.getY());
}

bool point::operator<(const point& _point) const
{
    return (getX() < _point.getX()) ? true : (getY() < _point.getY());
}

class line
{
private:
    point _beg;
    point _end;
public:
    
    const point& getBeg() const; 
    void setBeg(const point& beg);
    const point& getEnd() const;
    void setEnd(const point& end);
    line(const point& beg, const point& end);
    line(const point& beg);
    line(double x1,double y1, double x2, double y2);
    line();
};



const point& line::getBeg() const
{
    return _beg;
}

void line::setBeg(const point& beg)
{
    _beg = beg;
}

const point& line::getEnd() const
{
    return _end;
}

void line::setEnd(const point& end)
{
    _end = end;
}

line::line(const point& beg, const point& end) : _beg(beg), _end(end) {}
line::line(const point& beg) : _beg(beg), _end(beg) {}
line::line() : line(point(0, 0)) {}
line::line (double x1, double y1, double x2, double y2):line(point(x1,y1),point(x2,y2)){}

bool intersection(const line& l1, const line& l2)
{
    point dir1 = l1.getEnd() - l1.getBeg();
    point dir2 = l2.getEnd() - l2.getBeg();
    point start1 = l1.getBeg();
    point start2 = l2.getBeg();
    point end1 = l1.getEnd();
    point end2 = l2.getEnd();
    //считаем уравнения прямых проходящих через отрезки
    double a1 = -dir1.getY();
    double b1 = +dir1.getX();
    double d1 = -(a1 * start1.getX() + b1 * start1.getY());

    double a2 = -dir2.getY();
    double b2 = +dir2.getX();
    double d2 = -(a2 * start2.getX() + b2 * start2.getY());

    //подставляем концы отрезков, для выяснения в каких полуплоскотях они
    double seg1_line2_start = a2 * start1.getX() + b2 * start1.getY() + d2;
    double seg1_line2_end = a2 * end1.getX() + b2 * end1.getY() + d2;

    double seg2_line1_start = a1 * start2.getX() + b1 * start2.getY() + d1;
    double seg2_line1_end = a1 * end2.getX() + b1 * end2.getY() + d1;

    //если концы одного отрезка имеют один знак, значит он в одной полуплоскости и пересечения нет.
    if (seg1_line2_start * seg1_line2_end >= 0 || seg2_line1_start * seg2_line1_end >= 0)
        return false;

    float u = seg1_line2_start / (seg1_line2_start - seg1_line2_end);
    point out_intersection = start1 +  dir1*u;

    return true;
}

using namespace std;
int main()
{
   // system("chcp 65001");
    setlocale(LC_ALL, "ru");
    ifstream fin("C:\\Users\\HP\\source\\repos\\LABS\\imput.txt");
    if (fin.fail())
    {
        cout << "Ошибка открытия файла";
        return 0;
    }
    int n;
    fin >> n;

    line* p = new line[n];
    line AB;
    double x1, y1, x2, y2;
    for (int i = 0; (i < n) && !fin.eof(); i++)
    {
        fin >> x1;
        fin >> y1;
        fin >> x2;
        fin >> y2;
        p[i] =  line( x1,y1,x2,y2);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (intersection(p[i], p[j]))
            {
                cout << "Пересекающаяся пара отрезков "<<endl
                    << "Первый отрезок ["
                    << "Первая точка: "
                    << p[i].getBeg().getX() << ' '
                    << p[i].getBeg().getY() << " Вторая точка: "

                    << p[i].getEnd().getX() << ' '
                    << p[i].getEnd().getY() << "]"<<endl;
                cout << "Второй отрезок ["
                    << "Первая точка: "
                    << p[j].getBeg().getX() << ' '
                    << p[j].getBeg().getY() << " Вторая точка: "

                    << p[j].getEnd().getX() << ' '
                    << p[j].getEnd().getY() << "]" << endl<<"--------------------"<<endl;
            }
        }
    }
    return 0;
}

}

namespace lab2my {

int mainl2()
{
    srand(time(NULL));
    int nn;
    while (true)
    {
        cout << "the amount ";
        cin >> nn;
        cin.ignore(20, '\n');
        if (cin.good())
        {
            break;
        }
        cin.clear();
        cout << " incorrect type, try again\n";
    }
    triangle** ar = new triangle * [nn];
    double MIN_AREA;
    while (true)
    {
        cout << "MIN_AREA ";
        cin >> MIN_AREA;
        cin.ignore(20, '\n');
        if (cin.good())
        {
            break;
        }
        cin.clear();
        cout << " incorrect type, try again\n";
    }
    triangle t, tt; int n = 0, not_s = 0;

    for (int i = 0; i < nn; i++)
    {

        // cin >> t;
        t = triangle({ double(rand() % 100), double(rand() % 100) },
            { double(rand() % 100), double(rand() % 100) },
            { double(rand() % 100), double(rand() % 100) });

        if (t.get_area() > MIN_AREA)
        {
            (ar[n++]) = new triangle(t);
        }
        else
        {
            ar[nn - not_s - 1] = new triangle(t);
            not_s++;
        }

    }
    system("CLS");
    cout << "The amount of apropriate ones " << n << endl;
    unsigned int s;
    cout << "Would you like to see the \
apropriete ones(0)/inapropriete ones(1)/apropriete and " << endl << "inapropriete ones(2)/sort(3) \
or exit(4)? ";
    while (true)
    {
        cin >> s;
        cin.ignore(20, '\n');
        if (cin.good() && s < 4)
        {
            break;
        }
        cin.clear();
        cout << " the incorrect type or number, try again\n";
    }
    switch (s)
    {
    case 0:
        cout << "\nAPROPRIATE\n" << endl << "---------------------" << endl;
        if (n == 0)
        {
            cout << "empty\n";
            return 0;
        }
        for (int i = 0; i < n; i++)
        {
            cout << *(ar[i]) << endl;
        }
        break;
    case 1:
        cout << "\nINAPROPRIATE\n" << endl << "---------------------" << endl;

        if (not_s == 0)
        {
            cout << "empty\n";
            return 0;
        }
        for (int i = nn - not_s; i < nn; i++)
        {
            cout << *(ar[i]) << endl;
        }
        break;
    case 2:
        cout << "\nAPROPRIATE\n" << endl << "---------------------" << endl;
        if (n == 0)
        {
            cout << "empty\n";

        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                cout << *(ar[i]) << endl;
            }
        }
        cout << "\nINAPROPRIATE\n" << "---------------------" << endl;
        if (not_s == 0)
        {
            cout << "empty\n";
            return 0;
        }
        for (int i = nn - not_s; i < nn; i++)
        {
            cout << *(ar[i]) << endl;
        }
        break;
    case 3:
        sort(ar, ar + nn, [](auto& a, auto& b) {return ((*a).get_area() > (*b).get_area()) ? true : false; });
        for (int i = 0; i < nn; i++)
        {
            cout << *(ar[i]) << endl;
        }
    default: break;
    }cout << "blood and guts";
    system("pause");
    return 0;
}
}


