#include <iostream>
#include "math.h"
using namespace std;

class ptBac2{
    double a, b, c;
public:
    void nhap(){
        cout << "a = "; cin >> a;
        cout << "b = "; cin >> b;
        cout << "c = "; cin >> c;
    }
    void giaiPt(){
        if(a<0) cout << "Phuong trinh vua nhap khong phai phuong trinh bac hai." << endl;
        else{
            double delta = b * b - 4 * a * c;
            if(delta == 0)  cout << "Phuong trinh co nghiem kep: x1 = x2 = " << -b/(2*a) << endl;
            else{
                if(delta < 0)   cout << "Phuong trinh vo nghiem." << endl;
                else    cout << "Phuong trinh co hai nghiem phan biet: x1 = " << (-b-sqrt(delta))/(2*a) << " va x2 = " << (-b+sqrt(delta))/(2*a) << endl;
            }
        }
    }
};

int main(){
    ptBac2 a;
    cout << "Nhap vao phuong trinh bac hai:" << endl;   a.nhap();
    a.giaiPt();
    return 0;
}