
#include <algorithm>
#include <iostream>
#include "lab4.h"
#include <iomanip>
using namespace std;

int main()
{
    srand(time(NULL));
    int n = 15;
    double* x_val = new double[n];
    double* f_val = new double[n];
    funksin f(2,5,10);
    
    for_each(x_val, x_val + n, [](double& a) {a = 50-static_cast<double>(100) * rand() / RAND_MAX; });
    cout <<  setiosflags(ios::left) << setw(12) <<" X "<<setw(40) << f.get_fuction_as_a_string()<<'\n';
    transform(x_val, x_val + n, f_val, [&f](double a) {return f(a); });
    for (int i = 0; i < n; i++)
        cout <<' '<< setw(12) << x_val[i] << setw(40) << f_val[i] << '\n';
    delete[] x_val; delete[] f_val; x_val = NULL; f_val = NULL;
    cout << "\n====================================================================================\n";
    cout <<"The initial one: "<< f.get_fuction_as_a_string()<<'\n';
    f.integ();
    cout <<"integ: "<< f.get_fuction_as_a_string() << "\n";
    f = f * 3.14;
    cout << f.get_fuction_as_a_string() << "\n";
    f.integ();
    cout <<"integ: " << f.get_fuction_as_a_string() << "\n";
    f.dif();
    cout <<"dif: " << f.get_fuction_as_a_string() << "\n";
    f.dif(); 
    cout << "integ: " << f.get_fuction_as_a_string() << "\n";
    funksin temp = f / 3.14;
    cout << f.get_fuction_as_a_string() << '\n';
    f *= 8;
    cout  << f.get_fuction_as_a_string() << "\n";
    return 0;
}
