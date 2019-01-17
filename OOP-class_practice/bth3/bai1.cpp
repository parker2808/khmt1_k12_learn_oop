#include <iostream>
#include "string.h"
using namespace std;

class DATE{
    int d, m, y;
public:
    void nhap(){
        cout << "Ngay: ";    cin >> d;
        cout << "Thang: ";   cin >> m;
        cout << "Nam: ";     cin >> y;
    }
    void xuat(){
        cout << "Date: " << d << "/ " << m << "/ " << y << endl;
    }
};

class NHANSU{
    string maNS, hoTen;
    DATE nhanSu;
public:
    void nhap(){
        cout << "Ma nhan su: ";     getline(cin, maNS);
        cout << "Ho ten: ";         getline(cin, hoTen);
        nhanSu.nhap();
    }
    void xuat(){
        cout << "Ma nhan su: " << maNS << endl;
        cout << "Ho ten: " << hoTen << endl;
        nhanSu.xuat();
    }
};

int main(){
    NHANSU a;
    a.nhap();
    cout << endl << endl << "THONG TIN VUA NHAP" << endl;
    a.xuat();
    return 0;
}