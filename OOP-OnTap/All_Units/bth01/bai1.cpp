#include <iostream>
#include "math.h"
using namespace std;

class bieuThuc{
    int n;
    double x;
    double s = 0;
public:
    void nhap(){
        cout << "x = "; cin >> x;
        cout << "n = "; cin >> n;
    }
    double tong(){
        for(int i=1; i<=n; i++){
            s+=(double)(i*pow(x, i));
        }
        return s;
    }
    void xuat(){
        cout << "Tong cua day so S = " << s << endl;
    }
};

int main(){
    bieuThuc a;
    a.nhap();
    a.tong();
    a.xuat();
    return 0;
}