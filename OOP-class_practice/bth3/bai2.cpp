#include <iostream>
#include "string.h"
#include "iomanip"
using namespace std;

class NSX{
    string maNSX, tenNSX, diaChi;
public:
    void nhap(){
        cout << "Ma nha san xuat: ";        getline(cin, maNSX);
        cout << "Ten nha san xuat: ";       getline(cin, tenNSX);
        cout << "Dia chi nha san xuat: ";   getline(cin, diaChi);
    }
    void xuat(){
        cout << setw(15) << maNSX << setw(20) << tenNSX << setw(20) << diaChi << endl;
    }
};

class HANG{
    string maH, tenH;
    NSX x;
public:
    void nhap(){
        cout << "Ma hang: ";    getline(cin, maH);
        cout << "Ten hang: ";   getline(cin, tenH);
        x.nhap();
    }
    void xuat(){
        cout << "Ma hang: " << maH << endl;
        cout << "Ten hang: " << tenH << endl;
        cout << setw(15) << "MaNSX" << setw(20) << "TenNSX" << setw(20) << "DiaChi" << endl;
        x.xuat();
    }
};

int main(){
    HANG a;
    cout << "NHAP THONG TIN MAT HANG" << endl << endl;
    a.nhap();
    cout << endl << setw(30) << "THONG TIN MAT HANG" << endl;
    a.xuat();
    return 0;
}