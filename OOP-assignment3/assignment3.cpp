#include <iostream>
#include "fstream"
using namespace std;

class PHANSO{
    float tu, mau;
public:
    PHANSO(){
        tu = mau = 0;
    }
    PHANSO(float x, float y){
        tu = x;
        mau =y;
    }
    PHANSO operator*(PHANSO y){
        PHANSO tg;
        tg.tu = tu * y.tu;
        tg.mau = mau * y.mau;
        return tg;
    }
    double operator!(){
        return (float)tu/mau;
    }
    friend istream &operator>>(istream &x, PHANSO &y);
    friend ostream &operator<<(ostream &x, PHANSO y);
};

istream &operator>>(istream &x, PHANSO &y){
    cout << "Nhap tu so: "; x >> y.tu;
    cout << "Nhap mau so: ";    x >> y.mau;
    return x;
}

ostream &operator<<(ostream &x, PHANSO y){
    x << "(" << y.tu << "/" << y.mau << ")";
    return x;
}

int main(){
    PHANSO a(1, 2), b(3, 4);
    cout << "- Phuong thuc khoi tao " << a << " x " << b << " = " << a*b << endl;
    
    PHANSO c, d;
    cout << "- Nhap phan so c" << endl;   cin >> c;
    cout << "- Nhap phan so d" << endl;   cin >> d;
    cout << "- Phep nhan: " << c << " x " << d << " = " << c*d << endl;
    
    ofstream f("PHANSO.txt", ios::out);
    f << "Phuong thuc khoi tao: " << a << " x " << b << " = " << a*b << endl;
    f << "Phep nhan: " << c << " x " << d << " = " << c*d << endl;
    f.close();
    cout << "- Xuat tep thanh cong, kiem tra tap tin PHANSO.txt" << endl;
    cout << "- Xuat tep PHANSO.txt len man hinh:" << endl;
    ifstream f1("PHANSO.txt", ios::in);
    char S[200];
    while(!f1.eof()){
        f1.getline(S, 200);
        cout << S << endl;
    }
    return 0;
}