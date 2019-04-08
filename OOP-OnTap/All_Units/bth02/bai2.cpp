#include <iostream>
using namespace std;

class diem{
    int x, y;
public:
    void nhap(){
        cout << "x = "; cin >> x;
        cout << "y = "; cin >> y;
    }
};

class tamGiac{
    diem a, b, c;
public:
    void nhap(){
        cout << "Nhap diem A:" << endl; a.nhap();
        cout << "Nhap diem B:" << endl; b.nhap();
        cout << "Nhap diem C:" << endl; c.nhap();
    }
    bool khongTh(){
        if()
    }
}