﻿#include <iostream>
#include <array>
#include <string>
#include <malloc.h>

using namespace std;

const int Seasons = 4;
const int Lim = 8;
const std::array<std::string, Seasons> Snames = {"Spring", "Summer", "Fall", "Winter"};

void show(std::array<double, Seasons> da);
void fill(std::array<double, Seasons> * pa);
double betsy(int lns);
double pam(int lns);
void estimate(int lines, double(*pf)(int));
void Show(int a[]);

template<typename T>
void Swap(T &a, T &b);

template<typename T>
void Swap(T *a, T *b, int n);

int myCompare(const int val, const int *p);

void replaceSpace(char *str, int length);

struct job
{
    char name[40];
    double salary;
    int floor;
};
int main5() {
   // std::array<double, Seasons> expenses;
    //fill(&expenses);
    //show(expenses);
    //using namespace std;
    //int code;
    //cin >> code;
    //estimate(code, betsy);
    //estimate(code, pam);
    return 0;
}



int main6() {
    using namespace std;
    int i = 10, j = 20;
    Swap(i, j);
    int d1[Lim] = { 0, 2, 4, 6, 8, 10, 12, 14 };
    int d2[Lim] = { 1, 3, 5, 7, 9, 11, 13, 15 };
    //Show(d1);
    //Show(d2);
    //Swap(d1, d2, Lim);
    //Show(d1);
    //Show(d2);
    return 0;
}

int main7() {
    using namespace std;
    int d3[Lim] = { 0, 2, 4, 6, 8, 10, 12, 14 };
    cout << myCompare(1, d3) << endl; 
    return 0;
}


/*
* error
void replaceSpace(char *str, int length) {
        int i = 0;
        int j = 0;
        int nSpace = 0;
        char *pStr = NULL;
        pStr = (char*)malloc(sizeof(char)*length * 3);
        for (i = 0, j = 0; i<length; i++, j++) { 
            if (' ' == str[i]) {
                pStr[j] = '\%';
                pStr[++j] = '2';
                pStr[++j] = '0';
            } else {
                pStr[j] = str[i]; 
            } 
        }

        for (int k = 0; k < j; k++) {
            str[k] = pStr[k];
        }

        for (int i = 0; i < j; i++) {
            cout << *(str + i) << endl;
        }
        //free(pStr);
}
*/

void replaceSpace(char *str, int length) {
    if (str == NULL) {
        return;
    }
    string newString;
    for (int i = 0; i < length; i++) {
        if (str[i] == ' ') {
            newString = newString + "%20";
            continue;
        }
        newString += str[i];
    }
    if (newString.empty()) {
        cout << "newString empty" << endl;
    }

    cout << newString << endl;
}
int main8() {
    char* strone = "hello world";
    // cout << *strone << endl;
    int lengthone = strlen(strone);
    replaceSpace(strone, lengthone);
    return 0;
}

int myCompare(const int val, const int *p) {
    return (val > *p) ? val : *p;
}

void fill(std::array<double, Seasons> * pa) {
    using namespace std;
    for (int i = 0; i < Seasons; i++) {
        cout << "Enter " << Snames[i] << " expenses: ";
        cin >> (*pa)[i];
    }
}

void show(std::array<double, Seasons> da)
{
    using namespace std;
    double total = 0.0;
    cout << "\nExpensive\n";
    for (int i = 0; i < Seasons; i++) {
        cout << Snames[i] << ": $" << da[i] << endl;
        total += da[i];
    }
    cout << "Total =" << endl;
}

double betsy(int lns) {
    return 0.5 * lns;
}

double pam(int lns) {
    return 0.03 * lns;
}

void estimate(int lines, double(*pf)(int)) {
    using namespace std;
    cout << (*pf)(lines) << endl;
}


template<typename T>
void Swap(T &a, T &b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template<typename T>
void Swap(T *a, T *b, int n) {
    T temp;
    for (int i = 0; i < n; i++) {
        temp = a[i];
        a[i] = b[i];
        b[i] = a[i];
    }
}


void Show(int a[]) {
    using namespace std;
    for (int i = 4; i < Lim; i++) {
        cout << a[i];
    }
    cout << "\n";
}