// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "coordin.h"
#include <iostream>

using namespace std;

const int arSize = 8;
int sum_arr(int arr[], int n);
int sum_arr2(int* arr2, int n);
int fill_array(double ard[], int limit);
void show_array(const double ar[], int n);
void revalue(double r, double ar[], int n);
int sum_arr_p(const int * begin, const int *end);

int main1()
{
    rect rplace;
    polar pplace;
    cout << "Enter the x and y values:";
    while (cin >> rplace.x >> rplace.y) {
        pplace = rect_to_polar(rplace);
        show_polar(pplace);
        cout << "Next two numbers (q or quit) ";
    }
    cout << "Bye!\n";
    return 0;
}

int main2() {
    int cookies[arSize] = { 1, 2, 3, 4, 5, 6, 7 };
    int sum = sum_arr(cookies, arSize);
    cout << "sum = " << sum;
    int *p = cookies;
    cout << "\n";
    cout << *p << " " << *(p+1);

    int *p2 = &cookies[0];
    cout << "\n";
    cout << *p2 << " " << *(p2 + 1);
    cout << "\n" << cookies;

    int sum2 = sum_arr2(cookies + 3, 4);
    cout << "sum2 = " << sum2;
    double dd[20];
    fill_array(dd, 2);
    return 0;
}

const int Max = 5;
int main3() {
    using namespace std;
    double properties[Max];
    int size = fill_array(properties, Max);
    show_array(properties, size);
    if (size > 0) {
        cout << "Enter revaluation factor";
        double factor;
        while (!(cin >> factor))
        {
            cin.clear();
            while (cin.get() != '\n')
            {
                continue;
            }
            cout << "bad input\n";
        }
        revalue(factor, properties, size);
        show_array(properties, size);
    }

    const int g_earth = 9;
    const int *pe = &g_earth;
    int j = 2;
    pe = &j;

    float g_moon = 1.63;
    const float * pm = &g_moon;

    return 0;
}

int main4() {
    char ghost[15] = "galloping";
    char *str = "galumphing";
    cout << strlen(ghost) << endl;
    cout << strlen(str) << endl;
    cout << strlen("galumphing") << endl;
    return 0;
}
int sum_arr(int arr[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}

int sum_arr2(int* arr2, int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += *(arr2 + i);
    }
    return total;
}

int fill_array(double ard[], int limit){
    double temp;
    int i;
    for (i = 0; i < limit; i++) {
        cout << "Enter value #" << (i + 1) << ": ";
        cin >> temp;
        if (!cin) {
            cin.clear();
            while (cin.get() != '\n')
            {
                continue;
            }
            cout << "bad input\n";
            break;
        }
        else if(temp < 0) {
            break;
        }
        else
            ard[i] = temp;
    }
    return i;
}

void show_array(const double ar[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Property #" << (i + 1) << ": $";
        cout << ar[i] << endl;
    }
}

void revalue(double r, double ar[], int n) {
    for (int i = 0; i < n; i++)
        ar[i] *= r;
}

int sum_arr_p(const int * begin, const int *end) {
    const int *pt;
    int total = 0;
    for (pt = begin; pt != end; pt++) {
        total += *pt;
    }
    return total;
}