#include <iostream>
#include "string.h"
#include "iomanip"
using namespace std;

class DATE{
    int d, m, y;
public:
    void nhap(){
        cout << "Day: ";        cin >> d;
        cout << "Month: ";      cin >> m;
        cout << "Year: ";       cin >> y;
        cin.ignore(1);
    }
    void xuat(){
        cout << "Ngay lap:  " << d << "/ " << m << "/ " << y << endl;
    }
};

class NCC{
    string maNCC, tenNCC, diaChi;
    long sDT;
public:
    void nhap(){
        cout << "Ma nha cung cap: ";    getline(cin, maNCC);
        cout << "Ten nha cung cap: ";   getline(cin, tenNCC);
        cout << "Dia chi: ";            getline(cin, diaChi);
        cout << "So dien thoai: ";      cin >> sDT;
        cin.ignore(1);
    }
    void xuat(){
        cout << "Ma nha cung cap: " << maNCC << setw(20) << "Ten nha cung cap: " << tenNCC << endl;
        cout << "Dia chi: " << diaChi << setw(30) << "SDT" << sDT << endl;
    }
};

class SP{
    string maSP, tenSP;
     
}

class Phieu_VPP{
    string maPhieu;
    DATE a;
    NCC b;
}


