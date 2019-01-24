#include <iostream>
#include "iomanip"
#include "string.h"
using namespace std;

class NSX{
    string maNSX, tenNSX, dcNSX;
public:
    friend class HANG;
};

class HANG{
    string maHang, tenHang;
    int donGia;
    float trongLuong;
    NSX x;
public:
    void nhap(){
        cout << "Ma hang     : ";  getline(cin, maHang);
        cout << "Ten hang    : ";  getline(cin, tenHang);
        cout << "Don gia     : ";  cin >> donGia;
        cout << "Trong luong : ";  cin >> trongLuong;
        cin.ignore(1);
        cout << "Ma NSX      : ";  getline(cin, x.maNSX);
        cout << "Ten NSX     : ";  getline(cin, x.tenNSX);
        cout << "Dia chi     : ";  getline(cin, x.dcNSX);
    }
    void xuat(){
        cout << setw(15) << maHang << setw(15) << tenHang << setw(15) << donGia << setw(15) << trongLuong << setw(15)
        << x.maNSX << setw(15) << x.tenNSX << setw(20) << x.dcNSX << endl;
    }
};

int main(){
    HANG a;
    a.nhap();
    cout << "Mat hang ban vua nhap la: " << endl;
    cout << setw(15) << "MaHang" << setw(15) << "TenHang" << setw(15) << "DonGia" << setw(15) << "TrongLuong" << setw(15)
    << "MaNSX" << setw(15) << "TenNSX" << setw(20) << "DiaChi" << endl;
    a.xuat();
    return 0;
}