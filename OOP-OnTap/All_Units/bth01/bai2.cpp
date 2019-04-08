#include <iostream>
#include "math.h"
using namespace std;

class tamGiac{
    double a, b, c;
    double d = 0, s = 0;
public:
    void nhap(){
        cout << "a = "; cin >> a;
        cout << "b = "; cin >> b;
        cout << "c = "; cin >> c;
    }
    bool laTamGiac(){
        if(a+b>c && b+c>a && c+a>b) return true;
        else return false;
    }
    double chuVi(){
        return d = a + b + c;
    }
    double dienTich(){
        double p = chuVi()/2;
        return s = sqrt(p*(p-a)*(p-b)*(p-c));
    }
    void xuat(){
        cout << "Chu vi tam giac la: " << d << endl;
        cout << "Dien tich tam giac la: " << s << endl;
    }
};

int main(){
    tamGiac a;
    cout << "Nhap 3 canh tam giac:" << endl;    a.nhap();
    if(a.laTamGiac()==true) cout << "3 canh vua nhap tao thanh 1 tam giac." << endl;
    else    cout << "3 canh vua nhap khong tao thanh tam giac." << endl;
    a.chuVi();  a.dienTich();
    a.xuat();
    return 0;
}