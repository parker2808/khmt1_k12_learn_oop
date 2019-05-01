#include <iostream>
#include "iomanip"
#include "string.h"
using namespace std;

class phieu;

class hangHoa{
    char tenHang[30];
    double donGia;
    int soLuong;
    double thanhTien;
public:
    void nhap(){
        cout << "Ten hang: ";   cin.getline(tenHang, 30);
        cout << "Don gia: ";    cin >> donGia;
        cout << "So luong: ";   cin >> soLuong;
        cin.ignore(1);
        thanhTien = donGia * soLuong;
    }
    void xuat(){
        cout << setw(15) << tenHang << setw(15) << donGia << setw(15) << soLuong << setw(15) << thanhTien << endl;
    }
    friend class phieu;
};

class date{
    int ngay, thang, nam;
public:
    void nhap(){
        cout << "Ngay: ";   cin >> ngay;
        cout << "Thang: ";  cin >> thang;
        cout << "Nam: ";    cin >> nam;
        cin.ignore(1);
    }
    void xuat(){
        cout << ngay << "/" << thang << "/" << nam;
    }
};

class phieu{
    char maPhieu[30];
    char khachHang[30];
    date ngayLap;
    double tongTt;
    hangHoa *a;
    int n;
public:
    void nhap(){
        cout << "Ma phieu: ";   cin.getline(maPhieu, 30);
        cout << "Khach hang: "; cin.getline(khachHang, 30);
        cout << "-- Nhap ngay thanh lap --" << endl;    ngayLap.nhap();
        cout << endl << "-- Nhap vao danh sach cac hang hoa --" << endl;
        cout << "Tong so hang hoa can nhap: ";  cin >> n;   cin.ignore(1);
        a = new hangHoa[n];
        for(int i=0; i<n; i++){
            cout << "-- Mat hang thu " << i+1 << " --" << endl;
            a[i].nhap();
            tongTt += a[i].thanhTien;
        }
    }
    void xuat(){
        cout << endl << setw(40) << "PHIEU MUA HANG" << endl;
        cout << setw(20) << "Ma phieu: " << maPhieu << setw(20) << "Khach hang: " << khachHang << endl;
        cout << setw(20) << "Ngay lap: ";   ngayLap.xuat(); cout << setw(21) << "Tong thanh tien: " << tongTt << endl;
        cout << "Danh muc hang hoa" << endl;
        cout << setw(15) << "TenHang" << setw(15) << "DonGia" << setw(15) << "SoLuong" << setw(15) << "ThanhTien" << endl;
        for(int i=0; i<n; i++)  a[i].xuat();
        cout << endl;
    }
};

int main(){
    phieu a;
    a.nhap();
    a.xuat();
    return 0;
}