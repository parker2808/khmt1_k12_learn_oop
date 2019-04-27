#include <iostream>
#include "iomanip"
#include "string.h"
using namespace std;

class list;

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
        cout << setw(11) << day << "/ " << month << "/ " << year;
    }
};

class hangHoa{
    int maHang;
    char tenHang[65];
    date ngayNhap;
    int soLg;
    long dongia;
public:
    void nhap(){
        cout << "Ma hang: ";    cin >> maHang;  cin.ignore(1);
        cout << "Ten hang: ";   cin.getline(tenHang, 65);
        cout << "- Ngay nhap" << endl;  ngayNhap.nhap();
        cout << "So luong: ";   cin >> soLg;
        cout << "Don gia: ";    cin >> dongia;
        cin.ignore(1);
    }
    void xuat(){
        cout << setw(20) << maHang << setw(20) << tenHang;
        ngayNhap.xuat();
        cout << setw(15) << soLg << setw(15) << dongia << endl;
    }
    long getTt(){
        return soLg*dongia;
    }
};

class list{
    int n;
    hangHoa *a;
public:
    void nhap(){
        cout << "Tong so mat hang can nhap: ";  cin >> n;   cin.ignore(1);
        cout << endl << "Nhap danh sach mat hang" << endl;
        a = new hangHoa[n];
        for(int i=0; i<n; i++){
            cout << "Mat hang " << i+1 << endl;
            a[i].nhap();
        }
    }
    void xuat(){
        cout << setw(50) << "QUAN LY HANG HOA" << endl;
        cout << setw(20) << "MaHang" << setw(20) << "TenHang" << setw(20) << "NgayNhap" << setw(15) << "SoLuong" << setw(15) << "DonGia" << endl;
        for(int i=0; i<n; i++)  a[i].xuat();
        cout << endl;
    }
    long tongTt(){
        int tong = 0;
        for(int i=0; i<n; i++){
            tong+=a[i].getTt();
        }
        return tong;
    }
};

int main(){
    list a;
    cout << "Nhap danh sach hang hoa" << endl;  a.nhap();
    cout << endl;   a.xuat();
    cout << "Tong thanh tien cua cac mat hang la: " << a.tongTt() << endl;
    return 0;
}