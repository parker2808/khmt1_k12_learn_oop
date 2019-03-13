#include <iostream>
#include "fstream"
using namespace std;

class PHANSO{
    float tu, mau;
public:
    PHANSO operator*(PHANSO y){
        PHANSO tg;
        tg.tu = tu * y.tu;
        tg.mau = mau * y.mau;
        return tg;
    }
    PHANSO operator/(PHANSO y){
        PHANSO tg;
        tg.tu = tu * y.mau;
        tg.mau = mau * y.tu;
        return tg;
    }
    PHANSO operator+(PHANSO y){
        PHANSO tg;
        tg.tu = tu * y.mau + y.tu * mau;
        tg.mau = mau * y.mau;
        return tg;
    }
    PHANSO operator-(PHANSO y){
        PHANSO tg;
        tg.tu = tu * y.mau - y.tu * mau;
        tg.mau = mau * y.mau;
        return tg;
    }
    double operator!(){
        return (float)tu / mau;
    }
    friend istream &operator>>(istream &x, PHANSO &y);
    friend ostream &operator<<(ostream &x, PHANSO y);
};

istream &operator>>(istream &x, PHANSO &y){
    cout << "TU SO : "; x >> y.tu;
    cout << "MAU SO: "; x >> y.mau;
    return x;
}

ostream &operator<<(ostream &x, PHANSO y){
    x << "(" << y.tu << "/" << y.mau << ")";
    return x;
}

int main(){
    PHANSO a, b;
    cout << "NHAP PHAN SO THU NHAT:" << endl;    cin >> a;
    cout << "NHAP PHAN SO THU HAI:" << endl;    cin >> b;
    PHANSO tich = a * b;
    PHANSO thuong = a / b;
    PHANSO tong = a + b;
    PHANSO hieu = a - b;
    cout << "TICH 2 PHAN SO:" << a << " * " << b << " = " << tich << " = " << !tich << endl;
    cout << "THUONG 2 PHAN SO: " << a << " / " << b << " = " << thuong << " = " << !thuong << endl;
    cout << "TONG 2 PHAN SO: " << a << " + " << b << " = " << tong << " = " << !tong << endl;
    cout << "HIEU 2 PHAN SO: " << a << " - " << b << " = " << hieu << " = " << !hieu << endl;
    cout << endl;

    ofstream f("bai1.txt", ios::out);
    f << "TICH 2 PHAN SO:" << a << " * " << b << " = " << tich << " = " << !tich << endl;
    f << "THUONG 2 PHAN SO: " << a << " / " << b << " = " << thuong << " = " << !thuong << endl;
    f << "TONG 2 PHAN SO: " << a << " + " << b << " = " << tong << " = " << !tong << endl;
    f << "HIEU 2 PHAN SO: " << a << " - " << b << " = " << hieu << " = " << !hieu << endl;
    f.close();
    cout << "NHAP TEP THANH CONG, KIEM TRA FILE bai1.txt" << endl << endl;

    cout << "XUAT FILE LEN MAN HINH" << endl << endl;
    ifstream f1("bai1.txt", ios::in);
    char S[200];
    while(!f1.eof()){
        f1.getline(S, 200);
        cout << S << endl;
    }
    return 0;
}