#include "lab2_t.h"
#include<stdio.h>
#include<stdlib.h>
#include <fstream>
#include <math.h>
#include <set>
#include <algorithm>
#include <vector>
#include <list>

int main()
{
    srand(time(NULL));
    
    ifstream f("points.txt");
    if (!f.is_open())
    {
        cout << "The fail can't be open";
        exit(0);
    }
    int n; f >> n;
    if (n < 3)
    {
        cout << "can't build even one triangle"<<endl;
        return 0;
    }
    vector<BIG_COORD> ar(n);
    double x, y; int i = -1;
    while (!f.eof()&&i!=n-1)
    {
        f >> x >> y;
        ar[++i]=(BIG_COORD(x, y));
    }
    triangle* pt;
    vector<triangle*> l;
    for (int i = 0; i < ar.size(); i++)
    {
        for (int j = i+1; j < ar.size(); j++)
        {
            for (int k = j + 1; k < ar.size(); k++)
            {
                pt = new triangle(ar[i], ar[j], ar[k]);
                l.push_back(pt);
            }
        }
    }
    sort(begin(l), end(l), [](auto a, auto b) 
    {
        return ((*a).get_area() > (*b).get_area()) ? true : false; 
    });
    cout << l.size() << endl;
    for (auto it : l)
    {
        cout << *it << endl;
    }
   //double MIN_AREA ;
   //
   //triangle t, tt; int n = 0, not_s = 0;
   //
   //
   //system("pause");
    return 0;
}