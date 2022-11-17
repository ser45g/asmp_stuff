#include "lab4.h"
const string funksin::clear_zeros(string s)
{
    int ind = s.size() - 1;
    for (int i = s.size() - 1; i > -1; i--)
    {
        if (s[i] != '0')
        {
            ind = i;
            cout <<4;

            break;
        }
    }
    if (isdigit(s[ind]))
    {
        s.erase(ind + 1);
    }
    else if ((ind == 1 and s[0] == '0') || (ind == 2 && s[1] == '0' && s[0] == '-'))
        return s;
    else s.erase(ind);


    return s;
}

double funksin::get_value_at_the_point(double x)const
{
    return _a * f == SIN ? sin(_b * x + _c) : cos(_b * x + _c);
}

string funksin::get_fuction_as_a_string()
{
    string result = "f(x) = ";

    if (_a == 0)
        result = result + '0';
    else
    {

        if (_a == -1) { result += '-'; }
        else if (_a != 1) { result += clear_zeros(to_string(_a)) + '*'; }

        result += f == SIN ? "sin(" : "cos(";
        if (_b == 0)
        {
            if (_c < 0) { result += clear_zeros(to_string(_c)); }
            else { result += clear_zeros(to_string(_c)); }
        }
        else
        {
            if (_b == -1) { result += '-'; }
            else if (_b != 1) { result += clear_zeros(to_string(_b)) + '*'; }

            result += "x";

            if (_c < 0) { result += clear_zeros(to_string(_c)); }
            else if (_c != 0) { result += '+' + clear_zeros(to_string(_c)); }
        }
        result += ')';
    }
    return result;
}

void funksin::dif()
{
    //f(x)=a*sin(b*x+c)
    //f'(x)=a*b*cos(b*x+c)
    // 
    //f(x)=a*cos(b*x+c)
    //f'(x)=-a*b*cos(b*x+c)
    switch (f)
    {
    case SIN: f = COS; _a *= _b; break;
    case COS:  f = SIN; _a *= -_b; break;
    }
}

void funksin::integ()
{
    //f(x)=a*sin(b*x+c)
    //F(x)=-a*cos(b*x+c)/b
    // 
    //f(x)=a*cos(b*x+c)
    //F(x)=a*sin(b*x+c)/b

    switch (f)
    {
    case SIN:
        f = COS;
        _b ? _a /= -_b : throw exception("-a*cos(b*x+c)/b, where b==0"); break;
    case COS:
        f = SIN;
        _b ? _a /= _b : throw exception("a*sin(b*x+c)/b, where b==0");  break;
    }
}
