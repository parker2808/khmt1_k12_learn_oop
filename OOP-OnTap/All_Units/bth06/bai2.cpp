#include <iostream>
using namespace std;

class phanSo{
    float tu, mau;
public:
    phanSo(){
        tu = 0;
        mau = 1;
    }
    phanSo(float a, float b){
        tu = a;
        if(b != 0)  mau = b;
        else    mau = 1;
    }
    void nhap(){
        cout << "tu = ";    cin >> tu;
        cout << "mau = ";   cin >> mau;
        while(mau < 0){
            cout << "yeu cau nhap mau > 0, moi nhap lai!" << endl;
            cout << "mau = ";   cin >> mau;
        }
    }
    void xuat(){
        cout << tu << "/" << mau;
    }
    phanSo operator+(phanSo b){
        phanSo tg;
        tg.tu = tu*tg.mau + tg.tu*mau;
        tg.mau = mau*tg.mau;
        return tg;
    }
    phanSo operator-(phanSo b){
        phanSo tg;
        tg.tu = tu*tg.mau - mau*tg.tu;
        tg.mau = mau*tg.mau;
        return tg;
    }
    phanSo operator*(phanSo b){
        phanSo tg;
        tg.tu = tu*tg.tu;
        tg.mau = mau*tg.mau;
        return tg;
    }
    phanSo operator/(phanSo b){
        phanSo tg;
        tg.tu = tu*tg.mau;
        tg.mau = mau*tg.tu;
        return tg;
    }
    //rut gon phan so
    float ucln(float a, float b){
        if(a==0 || b==0)    return a+b;
        while(a!=b){
            if(a>b) a-=b;
            else    b-=a;
        }
        return a;
    }
    phanSo operator!(){
        phanSo tg;
        float uoc = ucln(tu, mau);
        tg.tu = tu/uoc;
        tg.mau = mau/uoc;
        return tg;
    }
    
    float operator++(){
        return (float)tu/mau;
    }
    friend istream &operator>>(istream &a, phanSo &b);
    friend ostream &operator<<(ostream &a, phanSo b);
};

istream &operator>>(istream &a, phanSo &b){
    cout << "tu = ";    a >> b.tu;
    cout << "mau = ";   a >> b.mau;
    while(b.mau < 0){
        cout << "Yeu cau mau > 0, moi nhap lai: mau = ";
        a >> b.mau;
    }
    return a;
}

ostream &operator<<(ostream &a, phanSo b){
    a << b.tu << "/" << b.mau;
    return a;
}

int main(){
    phanSo a(5, 0); cout << "Phuong thuc khoi tao phan so a: "; a.xuat();   cout << endl;
    phanSo b, c;
    //phuong thuc nhap
    cout << "-- Nhap phan so b --" << endl; b.nhap();
    //ham toan tu nhap
    cout << "-- Nhap phan so c --" << endl; cin >> c;
    cout << "- Tong hai phan so b va c la: " << b << " + " << c << " = " << b+c << endl;
    cout << "- Hieu hai phan so b va c la: " << b << " - " << c << " = " << b-c << endl;
    cout << "- Tich hai phan so b va c la: " << b << " x " << c << " = " << b*c << endl;
    cout << "- Thuong hai phan so b va c la: " << b << " : " << c << " = " << b/c << endl;
    cout << "- Gia tri phan so b la: " << b << " = " << ++b << endl;
    cout << "- Gia tri phan so c la: " << c << " = " << ++c << endl;
    cout << "- Phan so b sau khi toi gian: " << !b << endl;
    cout << "- Phan so c sau khi toi gian: " << !c << endl;
    return 0;
}