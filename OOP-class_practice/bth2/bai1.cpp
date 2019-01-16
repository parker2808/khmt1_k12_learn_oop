#include <iostream>
#include "math.h"
using namespace std;

class PTB2{
    float a, b, c;
public:
    void nhap(){
        cout << "a = "; cin >> a;
        cout << "b = "; cin >> b;
        cout << "c = "; cin >> c;
    }
    void giaipt(){
        if(a<0) cout << "Phuong trinh khong phai phuong trinh bac hai." << endl;
        else{
            float delta = b*b - 4*a*c;
            if(delta==0) cout << "Phuong trinh co nghiem kep: x1 = x2 = " << -b/(2*a) << endl;
            else{
                if(delta<0) cout << "Phuong trinh vo nghiem." << endl;
                else{
                    cout << "Phuong trinh co hai nghiem phan biet la: x1 = " << (-b-sqrt(delta))/2*a << " va x2 = " << (-b+sqrt(delta))/2*a << endl;
                }
            }
        } 
    }
};

int main(){
    PTB2 a;
    cout << "Nhap vao cac he so: " << endl;
    a.nhap();
    a.giaipt();
    return 0;
}