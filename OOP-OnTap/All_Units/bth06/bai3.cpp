#include <iostream>
#include "math.h"
using namespace std;

class tamThucBacHai{
    float a, b, c;
public:
    tamThucBacHai(){
        a = b = c;
    }
    tamThucBacHai(float x, float y, float z){
        a = x;  b = y;  c = z;
    }
    tamThucBacHai operator!(){
        tamThucBacHai tg;
        tg.a = -a;
        tg.b = -b;
        tg.c = -c;
        return tg;
    }
    tamThucBacHai operator+(tamThucBacHai y){
        tamThucBacHai tg;
        tg.a = a + y.a;
        tg.b = b + y.b;
        tg.c = c + y.c;
        return tg;
    }
    tamThucBacHai operator-(tamThucBacHai y){
        tamThucBacHai tg;
        tg.a = a - y.a;
        tg.b = b - y.b;
        tg.c = c - y.c;
        return tg;
    }
    friend istream &operator>>(istream &x, tamThucBacHai &y);
    friend ostream &operator<<(ostream &x, tamThucBacHai y);
};

istream &operator>>(istream &x, tamThucBacHai &y){
    cout << "a = "; x >> y.a;
    cout << "b = "; x >> y.b;
    cout << "c = "; x >> y.c;
    return x;
}

ostream &operator<<(ostream &x, tamThucBacHai y){
    if(y.b >= 0 && y.c >= 0)
        x << y.a << "x" << char(253) << " + " << y.b << "x + " << y.c << " = 0" << endl;
    else{
        if(y.b < 0 && y.c < 0){
            x << y.a << "x" << char(253) << " - " << abs(y.b) << "x - " << abs(y.c) << " = 0" << endl;
        }
        else if(y.b < 0 && y.c > 0)
                x << y.a << "x" << char(253) << " - " << abs(y.b) << "x + " << y.c << " = 0" << endl;
             else
                x << y.a << "x" << char(253) << " + " << y.b << "x - " << abs(y.c) << " = 0" << endl;
    }
    return x;
}

int main(){
    tamThucBacHai t1(2, 7, 4);   cout << "Tam thuc T1: " << t1 << "Sau khi doi dau: " << !t1;
    tamThucBacHai t2;   cout << "Nhap tam thuc T2" << endl; cin >> t2;
    cout << "Tam thuc T2: " << t2 << "Sau khi doi dau: " << !t2;
    cout << "Tong hai tam thuc T1 va T2 sau khi doi dau: " << !t1+!t2;
    cout << "Hieu hai tam thuc T1 va T2 sau khi doi dau: " << !t1-!t2;
    return 0;
}