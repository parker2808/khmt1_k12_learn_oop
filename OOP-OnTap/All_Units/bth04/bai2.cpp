#include <iostream>
#include "math.h"
using namespace std;

class phuongTrinhBac2{
    double a, b, c;
public:
    phuongTrinhBac2(){
        a = b = c = 0;
    }
    phuongTrinhBac2(double x, double y, double z){
        a = x;  b = y;  c = z;
    }
    ~phuongTrinhBac2(){
        //
    }
    void nhap(){
        cout << "a = "; cin >> a;
        cout << "b = "; cin >> b;
        cout << "c = "; cin >> c;
    }
    void xuat(){
        cout << a << "x" << char(253) << " + " << b << "x + " << c << " = 0" << endl;
    }
    void giaiPt(){
        if(a<0) cout << "- Phuong trinh vua nhap khong phai phuong trinh bac hai." << endl;
        else{
            double  delta = b*b-4*a*c;
            if(delta < 0)   cout << "- Phuong trinh vo nghiem." << endl;
            else{
                if(delta == 0)  cout << "- Phuong trinh co nghiem kep: x1 = x2 = " << (-b)/(2*a) << endl;
                else    cout << "- Phuong trinh co hai nghiem phan biet: x1 = " << (-b-sqrt(delta))/(2*a) << "va x2 = " << (-b+sqrt(delta))/(2*a) << endl;
            }
        }
    }
};

int main(){
    phuongTrinhBac2 P(1, 2, 1);
    P.xuat();
    P.giaiPt();

    phuongTrinhBac2 Q;
    cout << "Nhap phuong trinh Q:" << endl;
    Q.nhap();   Q.xuat();   Q.giaiPt();
    return 0;
}