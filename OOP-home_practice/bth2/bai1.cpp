#include <iostream>
#include "math.h"
using namespace std;

class PTB2{
    float a, b, c;
public:
    void nhap(){
        cout << "a = ";     cin >> a;
        cout << "b = ";     cin >> b;
        cout << "c = ";     cin >> c;
    }
    void ptb2(){
        if(a==0)     cout << "Ban vua nhap khong phai phuong trinh bac 2." << endl;
        else{
            float delta = b*b - 4*a*c;
            if(delta==0)    cout << "Phuong trinh co nghiem kep: X1 = X2 = " << (float)-b/(2*a) << endl;
            else{
                if(delta < 0)   cout << "Phuong trinh vo nghiem." << endl;
                else    cout << "Phuong trinh co hai nghiem phan biet: X1 = " << (float)(-b-sqrt(delta))/(2*a) << " va X2 = " << (float)(-b+sqrt(delta)/(2*a)) << endl;
            }
        }
    }
};

int main(){
    PTB2 a;
    cout << "Nhap vao phuong trinh bac hai: " << endl;
    a.nhap();
    a.ptb2();
    return 0;
}
