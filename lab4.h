#pragma once
#include <cmath>
#ifndef FUNK
#define FUNK
#endif // !FUNK
#include <string>
using namespace std;
//f(x)=a*sin(b*x+c)
//b,c//f(x)=sin(b*x+c)
//c//f(x)=sin(c)
//f(x)=sin(x)
class funksin
{
private:
    enum func{SIN,COS};
    func f;
    double _a, _b, _c;
    const string clear_zeros(string s);
    
public:
    funksin(const double a, const  double b, const  double c, func f = SIN) : _a(a), _b(b), _c(c), f(f) {}
    funksin(const double b, const  double c) : funksin(1, b, c, SIN) {}
    funksin(const double c) :funksin(1, 0, c, SIN) {}
    funksin() :funksin(1, 1, 0, SIN) {}

    double get_a()const { return _a; }
    double get_b()const { return _b; }
    double get_c()const { return _c; }

    void set_a(const double a) { _a = a; }
    void set_b(const double b) { _b = b; }
    void set_c(const double c) { _c = c; }
    void set_abc(const double a, const double b, const double c) { set_a(a); set_b(b); set_c(c); }

    double operator()(const double x)const { return get_value_at_the_point(x); }
    funksin operator*=(const double x) { _a *= x; return *this; }
    funksin operator/=(const double x) { _a /= x; return *this;}
    funksin operator*(const double x)const { funksin temp(*this); temp *= x; return temp; }
    funksin operator/(const double x)const { funksin temp(*this); temp /= x; return temp; }


    double get_value_at_the_point(const double x)const;

    string get_fuction_as_a_string();

    void dif();
    void integ();
};