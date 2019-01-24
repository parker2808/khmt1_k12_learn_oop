#include <iostream>
#include "math.h"
using namespace std;

class PTB2{
    float a, b, c;
public:
    void nhap(){
        cout << "\ta = "; cin >> a;
        cout << "\tb = "; cin >> b;
        cout << "\tc = "; cin >> c;
    }
    void xuat(){
        cout << a << "\tx" << (char)253 << " + " << b << "x + " << c << " = 0"<< endl;
    }
    void giai(){
        if(a<0) cout << "\tPhuong trinh ban vua nhap khong phai phuong trinh bac hai." << endl;
        else{
            float delta = b*b - 4*a*c;
            if(delta==0)    cout << "\tPhuong trinh co nghiem kep: x1 = x2 = " << -b/(2*a) << endl;
            else{
                if(delta<0) cout << "\tPhuong trinh vo nghiem." << endl;
                else    cout << "\tPhuong trinh co hai nghiem phan biet: x1 = " << (-b-sqrt(delta))/(2*a) << " va x2 = " << (-b+sqrt(delta))/(2*a) << endl;
            }
        }
    }
    PTB2(){
        a = b = c = 0;
    }
    PTB2(float x, float y, float z){
        a = x;  b = y;  c = z;
    }
};

int main(){
    PTB2 P(1, 4, 3);
    cout << "\tPhuong trinh (P): ";  P.xuat();
    cout << "\tGiai phuong trinh (P):" << endl; P.giai();
    cout << endl;

    PTB2 Q;
    cout << "\tNhap he so phuong trinh bac hai (Q): " << endl;  Q.nhap();
    cout << "\tPhuong trinh (Q): ";  Q.xuat();
    cout << "\tGiai phuong trinh (Q):" << endl; Q.giai();
    return 0;
}