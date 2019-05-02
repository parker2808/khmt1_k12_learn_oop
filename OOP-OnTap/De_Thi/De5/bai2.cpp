#include <iostream>
using namespace std;

class phanSo{
    float tu, mau;
public:
    phanSo(){
        tu = 0;
        mau = 1;
    }
    void nhap(){
        cout << "Tu  = ";   cin >> tu;
        cout << "Mau = ";   cin >> mau;
    }
    void xuat(){
        cout << tu << "/" << mau;
    }
    float ucln(float a, float b){
        if(a==0 || b==0)    return a+b;
        while(a!=b){
            if(a>b) a-=b;
            else    b-=a;
        }
        return a;
    }
    phanSo operator--(){
        phanSo tg;
        float uoc = ucln(tu, mau);
        tg.tu = tu / uoc;
        tg.mau = mau/uoc;
        return tg;
    }
    friend ostream &operator<<(ostream &x, phanSo y);
};

ostream &operator<<(ostream &x, phanSo y){
    x << y.tu << "/" << y.mau;
    return x;
}

int main(){
    phanSo a;
    cout << "-- Nhap phan so a --" << endl; a.nhap();
    cout << "Phan so a sau khi toi gian: " << --a << endl;
    return 0;
}