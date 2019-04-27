#include <iostream>
#include "string.h"
#include "iomanip"
using namespace std;

class phieuMuaHang;

class date{
    int day, month, year;
public:
    void nhap(){
        cout << "Ngay: ";   cin >> day;
        cout << "Thang: ";  cin >> month;
        cout << "Nam: ";    cin >> year;
        cin.ignore(1);
    }
    void xuat(){
        cout << day << "/ " << month << "/ " << year << endl;
    }
};

class hangHoa{
    char tenHang[65];
    int soLg;
    long donGia;
public:
    void nhap(){
        cout << "Ten hang: ";   cin.getline(tenHang, 65);
        cout << "So luong: ";   cin >> soLg;
        cout << "Don gia: ";    cin >> donGia;
        cin.ignore(1);
    }
    void xuat(){
        cout << setw(20) << tenHang << setw(20) << donGia << setw(20) << soLg;
    }
    long getTt(){
        return soLg*donGia;
    }
};

class phieuMuaHang{
    char maPh[12];
    char tenKh[20];
    char sdt[12];
    date ngayLap;
    int n;
    hangHoa *a;
public:
    void nhap(){
        cout << "Ma phieu: ";   cin.getline(maPh, 12);
        cout << "Ten khach hang: "; cin.getline(tenKh, 20);
        cout << "So dien thoai: ";  cin.getline(sdt, 12);
        cout << "- Ngay lap" << endl;   ngayLap.nhap();
        cout << "Tong mat hang: ";  cin >> n;   cin.ignore(1);
        a = new hangHoa[n];
        for(int i=0; i<n; i++){
            cout << "Mat hang " << i+1 << endl;
            a[i].nhap();
        }
    }
    void xuat(){
        cout << endl << setw(40) << "PHIEU MUA HANG" << endl;
        cout << "Ma phieu: " << maPh;
        cout << setw(26) << "Ngay lap: ";   ngayLap.xuat();
        cout << "Ten khach hang: " << tenKh << setw(21) << "Dien thoai KH: " << sdt << endl;
        cout << setw(20) << "TenHang" << setw(20) << "DonGia" << setw(20) << "SoLuong" << setw(20) << "ThanhTien" << endl;
        for(int i=0; i<n; i++){
            a[i].xuat();
            cout << setw(20) << a[i].getTt() << endl;
        }
    }
    long tongTt(){
        long tong = 0;
        for(int i=0; i<n; i++){
            tong+=a[i].getTt();
        }
        return tong;
    }
};

int main(){
    phieuMuaHang a;
    cout << "Nhap thong tin phieu" << endl; a.nhap();
    cout << endl;   a.xuat();
    cout << setw(50) << "Cong thanh tien: " << a.tongTt() << endl;
    return 0;
}