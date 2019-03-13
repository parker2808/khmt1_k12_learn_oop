#include <iostream>
using namespace std;

class tamthucbachai{
    float a, b, c;
public:
    tamthucbachai(){
        a = b = c = 0;
    }
    tamthucbachai(float x, float y, float z){
        a = x;  b = y;  c = z;
    }
    tamthucbachai operator!(){
        tamthucbachai tg;
        tg.a = -a;
        tg.b = -b;
        tg.c = -c;
        return tg;
    }
    tamthucbachai operator+(tamthucbachai y){
        tamthucbachai tg;
        tg.a = a + y.a;
        tg.b = b + y.b;
        tg.c = c + y.c;
        return tg;
    }
    tamthucbachai operator-(tamthucbachai y){
        tamthucbachai tg;
        tg.a = a - y.a;
        tg.b = b - y.b;
        tg.c = c - y.c;
        return tg;
    }
    friend ostream &operator<<(ostream &x, tamthucbachai y);
};

ostream &operator<<(ostream &x, tamthucbachai y){
    x << "(" << y.a << ")x" << (char)253 << " + (" << y.b << ")x + (" << y.c << ")" << endl;
}

int main(){
    tamthucbachai A(2, 3, 4), B(5, 7, 9);
    cout << "Tam thuc bac hai A sau khi doi dau: " << !A;
    cout << "Tam thuc bac hai B sau khi doi dau: " << !B;
    cout << "Tong hai tam thuc: A + B = " << !A + !B;
    cout << "Hieu hai tam thuc: A - B = " << !A - !B;
    return 0;
}