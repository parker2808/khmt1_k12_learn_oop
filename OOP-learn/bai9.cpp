#include <iostream>
#include "iomanip"
#include "string.h"
#include "fstream"
using namespace std;

class HANG{
    int maHang;
    char tenHang[30];
    float donGia, trongLuong;
public:
    friend istream &operator>>(istream &x, HANG &y);
    friend ostream &operator<<(ostream &x, HANG y);
};

istream &operator>>(istream &x, HANG &y){
    cout << "Ma hang: ";    x >> y.maHang;
    cin.ignore(1);
    cout << "Ten hang: ";   x.getline(y.tenHang, 100);
    cout << "Don gia: ";    x >> y.donGia;
    cout << "Trong luong: ";    x >> y.trongLuong;
    return x;
}

ostream &operator<<(ostream &x, HANG y){
    x << setw(20) << y.maHang << setw(20) << y.tenHang << setw(20) << y.donGia << setw(20) << y.trongLuong << endl;
    return x;
}

int main(){
    HANG a, b;
    cout << "Nhap mat hang A" << endl;  cin >> a;
    cout << "Nhap mat hang B" << endl;  cin >> b;
    cout << "Mat hang vua nhap" << endl;
    cout << setw(20) << "MaHang" << setw(20) << "TenHang" << setw(20) << "DonGia" << setw(20) << "TrongLuong" << endl;
    cout << a << b;

    //xuat tep
    ofstream f("bai9.txt", ios::out);
    f << setw(20) << "MaHang" << setw(20) << "TenHang" << setw(20) << "DonGia" << setw(20) << "TrongLuong" << endl;
    f << a << b;
    cout << "Check file bai9.txt. " << endl;
    return 0;
}