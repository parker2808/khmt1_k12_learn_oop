#include <iostream>
#include "iomanip"
#include "string.h"
using namespace std;

class list;

class congDan{
protected:
    char soThe[30];
    char hoTen[30];
    int namSinh;
    char gioiTinh[10];
public:
    void nhap(){
        cout << "So the can cuoc: ";    cin.getline(soThe, 30);
        cout << "Ho ten: "; cin.getline(hoTen, 30);
        cout << "Nam sinh: ";   cin >> namSinh; cin.ignore(1);
        cout << "Gioi tinh: ";  cin.getline(gioiTinh, 10);
    }
    void xuat(){
        cout << setw(15) << soThe << setw(15) << hoTen << setw(15) << namSinh << setw(15) << gioiTinh;
    }
};

class canBo : public congDan{
    int heSoLuong;
    long tienPhuCap;
    long thuNhap;
public:
    void nhap(){
        congDan::nhap();
        cout << "He so luong: ";    cin >> heSoLuong;
        cout << "Tien phu cap: ";   cin >> tienPhuCap;
        cin.ignore(1);
        thuNhap = heSoLuong * 139000 + tienPhuCap;
    }
    void xuat(){
        congDan::xuat();
        cout << setw(15) << heSoLuong << setw(15) << tienPhuCap << setw(15) << thuNhap << endl;
    }
    friend void xuatDs(list x);
};

class list{
    int n;
    canBo *a;
public:
    void nhap(){
        cout << "Tong so can bo can nhap: ";    cin >> n;   cin.ignore(1);
        a = new canBo[n];
        cout << "- Nhap danh sach cac can bo" << endl;
        for(int i=0; i<n; i++){
            cout << "-- can bo thu " << i+1 << " --" << endl;
            a[i].nhap();
        }
    }
    void xuat(){
        cout << setw(50) << "-- Danh sach can bo --" << endl;
        cout << setw(15) << "SoThe" << setw(15) << "HoTen" << setw(15) << "NamSinh" << setw(15) << "GioiTinh" << setw(15) << "HeSo" << setw(15) << "PhuCap" << setw(15) << "ThuNhap" << endl;
        for(int i=0; i<n; i++)  a[i].xuat();
        cout << endl;
    }
    friend void xuatDs(list x);
};

void xuatDs(list x){
    cout << "- Danh sach can bo nam co thu nhap tu 10 trieu tro len" << endl;
    cout << setw(15) << "SoThe" << setw(15) << "HoTen" << setw(15) << "NamSinh" << setw(15) << "GioiTinh" << setw(15) << "HeSo" << setw(15) << "PhuCap" << setw(15) << "ThuNhap" << endl;
    for(int i=0; i<x.n; i++){
        if(x.a[i].thuNhap >= 10000000 && strcpy(x.a[i].gioiTinh, "Nam")==0) x.a[i].xuat();
        else{
            cout << "==> Danh sach khong co thong tin can tim." << endl;
            return;
        }
    }
}

int main(){
    list a;
    a.nhap();
    a.xuat();
    xuatDs(a);
    return 0;
}