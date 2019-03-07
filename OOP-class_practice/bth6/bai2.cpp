#include <iostream>
#include "fstream"
using namespace std;

class SOPHUC{
    float thuc, ao;
public:
    SOPHUC(){
        thuc = ao = 0;
    }
    SOPHUC(float x, float y){
        thuc = x;
        ao = y;
    }
    SOPHUC operator+(SOPHUC y){
        SOPHUC tg;
        tg.thuc = thuc + y.thuc;
        tg.ao = ao + y.ao;
        return tg;
    }
    SOPHUC operator-(SOPHUC y){
        SOPHUC tg;
        tg.thuc = thuc - y.thuc;
        tg.ao = ao - y.ao;
        return tg;
    }
    friend istream &operator>>(istream &x, SOPHUC &y);
    friend ostream &operator<<(ostream &x, SOPHUC y);
};

istream &operator>>(istream &x, SOPHUC &y){
    cout << "Nhap phan thuc: "; x >> y.thuc;
    cout << "Nhap phan ao: ";   x >> y.ao;
    return x;
}

ostream &operator<<(ostream &x, SOPHUC y){
    x << "(" << y.thuc << " + i*" << y.ao << ")";
    return x;
}

int main(){
    SOPHUC a, b;
    cout << "Nhap so phuc dau tien" << endl;  cin >> a;
    cout << "Nhap so phuc thu hai" << endl;   cin >> b;

    SOPHUC tong = a + b;
    SOPHUC hieu = a - b;
    cout << "Tong hai so phuc: " << a << " + " << b << " = " << tong << endl;
    cout << "Hieu hai so phuc: " << a << " + " << b << " = " << hieu << endl;

    return 0;
}