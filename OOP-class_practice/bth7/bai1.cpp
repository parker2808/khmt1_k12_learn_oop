#include <iostream>
#include "string.h"
#include "iomanip"
using namespace std;

class NSX{
    char tenNSX[30], diaChi[30];
public:
    void nhap(){
        cout << "Ten nha san xuat: ";   cin.getline(tenNSX, 100);
        cout << "Dia chi: ";    cin.getline(diaChi, 100);
    }
    void xuat(){
        cout << setw(15) << tenNSX << setw(15) << diaChi;
    }
    friend class HANG;
};

class HANG{
protected:
    char tenHang[30];
    NSX x;
    float donGia;
public:
    void nhap(){
        cout << "Ten hang: ";   cin.getline(tenHang, 100);
        x.nhap();   //nhap thong tin tu class NSX
        cout << "Don gia: ";    cin >> donGia; cin.ignore(1);
    }
    void xuat(){
        cout << setw(15) << tenHang;
        x.xuat();
        cout << setw(15) << donGia;
    }
    HANG(){
        strcpy(tenHang, " ");
        strcpy(x.tenNSX, " ");
        strcpy(x.diaChi, " ");
        donGia = 0;
    }
};

class DATE{
    int d, m, y;
public:
    void nhap(){
        cout << "Day: ";    cin >> d;
        cout << "Month: ";  cin >> m;
        cout << "Year: ";   cin >> y;
    }
    void xuat(){
        cout << setw(15) << d << "/ " << m << "/ " << y;
    }
    friend class TIVI;
};

class TIVI : public HANG{
    float kichThuoc;
    DATE ngayNhap;
public:
    void nhap(){
        HANG::nhap();
        cout << "Kich thuoc tivi: ";    cin >> kichThuoc;
        cout << "NGAY NHAP HANG" << endl;  ngayNhap.nhap();
    }
    void xuat(){
        HANG::xuat();
        cout << setw(15) << kichThuoc;
        ngayNhap.xuat();
        cout << endl;
    }
    TIVI() : HANG(){
        kichThuoc = 0;
        ngayNhap.d = ngayNhap.m = ngayNhap.y = 0;
    }
};

int main(){
    TIVI a;
    a.nhap();
    cout << setw(40) << "THONG TIN TIVI" << endl;
    cout << setw(15) << "TEN HANG" << setw(15) << "TEN NSX" << setw(15) << "ADDRESS" << setw(15) << "DON GIA" << setw(15) << "SIZE" << setw(23) << "NGAY NHAP" << endl;
    a.xuat();
    return 0;
}