#include <iostream>
#include "string.h"
#include "iomanip"
using namespace std;

class date{
    int ngay, thang, nam;
public:
    void nhap(){
        cout << "Ngay: ";   cin >> ngay;
        cout << "Thang: ";  cin >> thang;
        cout << "Nam: ";    cin >> nam;
    }
    void xuat(){
        cout << setw(10) << ngay << setw(10) << thang << setw(10) << nam;
    }
};

class canBo{
    int maCb;
    char hoTen[30];
    date ngaySinh;
    int soNgayLv;
public:
    void nhap(){
        cout << "Ma can bo: ";  cin >> maCb;    cin.ignore(1);
        cout << "Ho ten: "; cin.getline(hoTen, 100);
        ngaySinh.nhap();    cin.ignore(1);
        cout << "So ngay lam viec: ";   cin >> soNgayLv;    cin.ignore(1);
    }
    void xuat(){
        cout << setw(15) << maCb << setw(15) << hoTen;
        ngaySinh.xuat();
        cout << setw(15) << soNgayLv << endl;
    }
    long luong(){
        return soNgayLv*250000;
    }
};

int main(){
    canBo a;
    cout << "Nhap thong tin can bo:" << endl;
    a.nhap();
    cout << endl << setw(40) << "Thong tin can bo" << endl;
    cout << setw(15) << "Ma Can Bo" << setw(15) << "Ho Ten" << setw(10) << "Ngay" << setw(10) << "Thang" << setw(10) << "Nam" << setw(15) << "So Ngay LV" << endl;
    a. xuat();
    cout << endl;
    cout << "Luong cua can bo la: " << a.luong() << endl;
    return 0;
}