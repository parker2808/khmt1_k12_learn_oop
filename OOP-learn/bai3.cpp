#include <iostream>
#include "string.h"

using namespace std;

class ptb2{
    float a, b,c;
public:
    void nhap();
    void xuat();
    ptb2();
    ptb2(float x, float y, float z);
};

void ptb2::nhap(){
    cout << "a = ";     cin >> a;
    cout << "b = ";     cin >> b;
    cout << "c = ";     cin >> c;
}

void ptb2::xuat(){
    cout << a << "x" << (char)253 << " + " << b << "x + " << c << " = 0" << endl;
}

ptb2::ptb2(){
    a = b = c = 1;
}

ptb2::ptb2(float x, float y, float z){
    a = x;  b = y
}