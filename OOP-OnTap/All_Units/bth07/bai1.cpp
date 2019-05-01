#include <iostream>
#include "iomanip"
#include "string.h"
using namespace std;

class date{
    int day, month, year;
public:
    void nhap(){
        cout << "Ngay: ";   cin >> day;
        cout << "Thang: ";  cin >> month;
        cout << "Nam: ";    cin >> year;
    }
    void xuat(){
        cout << setw(13) << day << "/" << month << "/" << year;
    }
};

class nhanSu{
protected:
    char hoTen[30];
    date ngaySinh;
    char gioiTinh[4];
    char diaChi[50];
public:
    void nhap(){
        cout << "Ho ten: "; cin.getline(hoTen, 30);
        cout << "-- Nhap ngay sinh --" << endl; ngaySinh.nhap();    cin.ignore(1);
        cout << "Gioi tinh: ";  cin.getline(gioiTinh, 4);
        cout << "Dia chi: ";    cin.getline(diaChi, 50);
    }
    void xuat(){
        cout << setw(15) << hoTen;
        ngaySinh.xuat();
        cout << setw(10) << gioiTinh << setw(20) << diaChi;
    }
};

class congNhan : public nhanSu{
    char tenCty[30];
    date ngayLv;
    double heSoLg;
public:
    void nhap(){
        nhanSu::nhap();
        cout << "Ten cong ty: ";    cin.getline(tenCty, 30);
        cout << "-- Nhap ngay lam viec --" << endl; ngayLv.nhap();
        cout << "He so luong: ";    cin >> heSoLg;  cin.ignore(1);
    }
    void xuat(){
        nhanSu::xuat();
        cout << setw(20) << tenCty;
        ngayLv.xuat();
        cout << setw(15) << heSoLg << endl;
        cout << "Luong cua cong nhan nay la: " << heSoLg*3250000 << endl;
    }
};

int main(){
    congNhan a;
    cout << "-- Nhap thong tin cong nhan --" << endl;   a.nhap();
    cout << "-- Thong tin cong nhan vua nhap --" << endl;
    cout << setw(15) << "HoTen" << setw(20) << "NgaySinh" << setw(10) << "GioiTinh" << setw(20) << "DiaChi" << setw(20) << "TenCty" << setw(20) << "NgayLv" << setw(15) << "HeSoLg" << endl;
    a.xuat();
    return 0;
}