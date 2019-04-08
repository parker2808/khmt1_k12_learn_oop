#include <iostream>
#include "iomanip"
#include "string.h"
using namespace std;

class NHANVIEN;

class DATE{
    int day, month, year;
public:
    friend class NHANVIEN;
    friend void nhapNhanVien(NHANVIEN *&a, int &n);
};

class PHONGBAN{
    int maPhongBan, soNV;
    char tenPhongBan[50];
    char truongPhong[10];
public:
    friend class NHANVIEN;
    friend void nhapNhanVien(NHANVIEN *&a, int &n);
};

class NHANVIEN{
    int maNV;
    char hoDem[25];
    char ten[10];
    DATE ngaySinh;
    PHONGBAN phong;
public:
    void nhap(){
        cout << "Ma nhan vien: ";   cin >> maNV;    cin.ignore(1);
        cout << "Ho dem: "; cin.getline(hoDem, 100);
        cout << "Ten: ";    cin.getline(ten, 100);
        cout << "Ngay sinh: ";  cin >> ngaySinh.day;   cin.ignore(1);
        cout << "Thang sinh: "; cin >> ngaySinh.month;  cin.ignore(1);
        cout << "Nam sinh: ";   cin >> ngaySinh.year;   cin.ignore(1);
        cout << "Ma phong ban: ";   cin >> phong.maPhongBan;    cin.ignore(1);
        cout << "Ten phong ban: ";  cin.getline(phong.tenPhongBan, 100);
        cout << "Truong phong: ";   cin.getline(phong.truongPhong, 100);
        cout << "So nhan vien: ";   cin >> phong.soNV;  cin.ignore(1);
    }
    void xuat(){
        cout << setw(10) << maNV << setw(15) << hoDem << " " << ten << setw(15) << ngaySinh.day << "/" << ngaySinh.month << "/" << ngaySinh.year << setw(10) 
        << phong.maPhongBan << setw(10) << phong.tenPhongBan << setw(15) << phong.truongPhong << setw(10) << phong.soNV << endl;
    }
    friend void nhapNhanVien(NHANVIEN *&a, int &n);
};

void nhapNhanVien(NHANVIEN *&a, int &n){
    cout << "Nhap tong so nhan vien: "; cin >> n;   cin.ignore(1);
    a = new NHANVIEN [n];
    cout << "Nhap danh sach nhan vien" << endl;
    for(int i=0; i<n; i++){
        cout << "STT" << i+1 << endl;
        a[i].nhap();
    }
}

void xuatNhanVien(NHANVIEN *a, int n){
    cout << setw(10) << "MaNV" << setw(20) << "HoTen" << setw(25) << "Ngay.Thang.Nam" << setw(10) << "MaPhong" << setw(10) << "TenPhong" << setw(15) 
    << "TruongPhong" << setw(10) << "SoNV" << endl;
    for(int i=0; i<n; i++){
        a[i].xuat();
    }
}



int main(){
    int n;
    NHANVIEN *a;
    nhapNhanVien(a, n);
    cout << setw(40) << "DANH SACH NHAN VIEN" << endl;
    xuatNhanVien(a, n);
    return 0;
}