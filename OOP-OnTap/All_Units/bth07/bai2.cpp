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
        cout << day << "/" << month << "/" << year;
    }
};

class sanPham{
protected:
    int maSp;
    char tenSp[60];
    date ngaySx;
    double trLg;
    char mauSac[50];
public:
    void nhap(){
        cout << "Ma san pham: ";    cin >> maSp;    cin.ignore(1);
        cout << "Ten san pham: ";   cin.getline(tenSp, 60);
        cout << "-- Nhap ngay san xuat --" << endl; ngaySx.nhap();
        cout << "Trong luong: ";    cin >> trLg;    cin.ignore(1);
        cout << "Mau sac: ";    cin.getline(mauSac, 50);
    }
    void xuat(){
        cout << setw(15) << maSp << setw(15) << tenSp << setw(15);
        ngaySx.xuat();
        cout << setw(15) << trLg << setw(15) << mauSac;
    }
};

class hangDienTu : public sanPham{
    double congSuat;
    char dongDien[20];
public:
    void nhap(){
        sanPham::nhap();
        cout << "Cong suat: ";  cin >> congSuat;    cin.ignore(1);
        cout << "Dong dien: ";  cin.getline(dongDien, 20);
    }
    void xuat(){
        sanPham::xuat();
        cout << setw(15) << congSuat << setw(15) << dongDien << endl;
    }
    friend class list;
};

class list{
    int n;
    hangDienTu *a;
public:
    void nhap(){
        cout << "Tong so mat hang: ";   cin >> n;   cin.ignore(1);
        a = new hangDienTu[n];
        for(int i=0; i<n; i++){
            cout << endl << "- Mat hang thu " << i+1 << endl;
            a[i].nhap();
        }
    }
    void xuat(){
        cout << setw(60) << "-- Danh sach san pham --" << endl;
        cout << setw(15) << "MaSp" << setw(15) << "TenSp" << setw(22) << "NgaySx" << setw(15) << "TrongLg" << setw(15) << "MauSac" << setw(15) << "CongSuat" << setw(15) << "DongDien" << endl;
        for(int i=0; i<n; i++)  a[i].xuat();
        cout << endl;
    }
    void viewMin(){
        double minView = a[0].trLg;
        for(int i=0; i<n; i++){
            if(a[i].trLg < minView) minView = a[i].trLg;
        }
        cout << setw(50) << "-- View Min --" << endl;
        cout << setw(15) << "MaSp" << setw(15) << "TenSp" << setw(22) << "NgaySx" << setw(15) << "TrongLg" << setw(15) << "MauSac" << setw(15) << "CongSuat" << setw(15) << "DongDien" << endl;
        for(int i=0; i<n; i++){
            if(a[i].trLg == minView)    a[i].xuat();
        }
    }
};

int main(){
    list a;
    a.nhap();
    a.xuat();
    a.viewMin();
    return 0;
}