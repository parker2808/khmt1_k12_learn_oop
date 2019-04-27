#include <iostream>
#include "string.h"
#include "iomanip"
using namespace std;

class phieuGiao;

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

class nguoiGiao{
    char hoTen[30];
    char soDt[12];
public:
    void nhap(){
        cout << "Ho ten shiper: "; cin.getline(hoTen, 30);
        cout << "So dien thoai: ";  cin.getline(soDt, 12);
        cin.ignore(1);
    }
    void xuat(){
        cout << setw(20) << hoTen << setw(20) << soDt;
    }
};

class hangHoa{
    char tenH[60];
    int soLg;
    long donGia;
public:
    void nhap(){
        cout << "Ten hang: ";   cin.getline(tenH, 60);
        cout << "So luong: ";   cin >> soLg;
        cout << "Don gia: ";    cin >> donGia;
        cin.ignore(1);
    }
    void xuat(){
        cout << setw(20) << tenH << setw(15) << soLg << setw(15) << donGia;
    }
    long getTt(){
      return soLg*donGia;
    }
    friend class phieuGiao;
};

class phieuGiao{
    int maPhieu;
    char tenKh[30];
    date ngayGiao;
    nguoiGiao shiper;
    hangHoa hang;
    int khoangCach;
public:
    void nhap(){
        cout << "Ma phieu: ";   cin >> maPhieu; cin.ignore(1);
        cout << "Ten khach hang: "; cin.getline(tenKh, 30);
        cout << "- Ngay giao hang" << endl;  ngayGiao.nhap();
        cout << "- Nguoi giao" << endl;  shiper.nhap();
        cout << "- Hang hoa" << endl;    hang.nhap();
        cout << "Khoang cach: ";    cin >> khoangCach;  cin.ignore(1);
    }
    long tienTra(){
        long phiGiao = 0;
        if(khoangCach<5)    phiGiao = 0;
        else{
            if(5<=khoangCach && khoangCach <=15)    phiGiao = 50000;
            else    phiGiao = 100000;
        }
        return hang.getTt() + phiGiao;
    }
    void xuat(){
        cout << "Ma phieu: " << maPhieu << endl;
        cout << "Ten khach hang: " << tenKh << endl;
        cout << "Ngay giao hang: "; ngayGiao.xuat();
        cout << endl << setw(20) << "HoTenShiper" << setw(20) << "SDTShiper" << setw(20) << "TenHang" << setw(15) << "SoLuong" << setw(15) << "DonGia" << setw(20) << "KhoangCach" << endl;
        shiper.xuat();
        hang.xuat();
        cout << setw(20) << khoangCach << endl;
    }
};

int main(){
    phieuGiao a;
    cout << "Nhap thong tin phieu giao" << endl;    a.nhap();
    cout << endl << "Thong tin phieu giao hang" << endl; a.xuat();
    cout << "Tong so tien khach hang can thanh toan: " << a.tienTra() << endl;
    return 0;
}
