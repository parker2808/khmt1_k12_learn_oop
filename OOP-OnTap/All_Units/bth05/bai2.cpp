#include <iostream>
#include "string.h"
#include "iomanip"
using namespace std;

class list;

class date{
    int day, month, year;
public:
    date(){
        day = month = year = 0;
    }
    date(int a, int b, int c){
        day = a;
        month = b;
        year = c;
    }
    void xuat(){
        cout << setw(11) << day << "/ " << month << "/ " << year;
    }
    friend class list;
    friend class hangHoa;
    friend long tongThanhTienThang8(list a);
};

class hangHoa{
    int maHang;
    char tenHang[65];
    date ngayNhap;
    int soLg;
    long donGia;
public:
    hangHoa(){
        maHang = soLg = donGia = 0;
        strcpy(tenHang, " ");
        date();
    }
    hangHoa(int a, char b[65], int d, int e, int f, int g, long h){
        maHang = a;
        strcpy(tenHang, b);
        date(d, e, f);
        soLg = g;
        donGia = h;
    }
    void xuat(){
        cout << setw(20) << maHang << setw(20) << tenHang;
        ngayNhap.xuat();
        cout << setw(20) << soLg << setw(20) << donGia;
    }
    friend class list;
    friend long tongThanhTienThang8(list a);
    friend long findMax(list x);
    friend void hienThiDonGiaMax(list x);
};

class list{
    int n;
    hangHoa *a;
public:
    list(){
        cout << "n = "; cin >> n;   cin.ignore(1);
        a = new hangHoa[n];
        for(int i=0; i<n; i++){
            cout << "- Mat hang thu " << i+1 << endl;
            cout << "Ma hang: ";    cin >> a[i].maHang; cin.ignore(1);
            cout << "Ten hang: ";   cin.getline(a[i].tenHang, 65);
            cout << "- Date" << endl;
            cout << "Ngay: ";   cin >> a[i].ngayNhap.day;
            cout << "Thang: ";  cin >> a[i].ngayNhap.month;
            cout << "Nam: ";    cin >> a[i].ngayNhap.year;
            cout << "So luong: ";   cin >> a[i].soLg;
            cout << "Don gia: ";    cin >> a[i].donGia;
            cin.ignore(1);
        }
    }
    ~list(){
        n = 0;
        delete a;
    }
    void xuat(){
        cout << setw(20) << "MaHang" << setw(20) << "TenHang" << setw(20)
             << "NgayNhap" << setw(20) << "SoLuong" << setw(20) << "DonGia" << setw(20)
             << "ThanhTien" << endl;
        for(int i=0; i<n; i++){
            a[i].xuat();
            cout << setw(20) << a[i].soLg * a[i].donGia << endl;
        }
    }
    friend long tongThanhTienThang8(list a);
    friend long findMax(list x);
    friend void hienThiDonGiaMax(list x);
};

long tongThanhTienThang8(list x){
    long thanhTien = 0;
    for(int i=0; i<x.n; i++){
        if(x.a[i].ngayNhap.month == 8 && x.a[i].ngayNhap.year == 2017)
            thanhTien += (x.a[i].soLg * x.a[i].donGia);
    }
    return thanhTien;
}

long findMax(list x){
    long aMax = x.a[0].donGia;
    for(int i=0; i<x.n; i++){
        if(x.a[i].donGia>aMax)   aMax = x.a[i].donGia;
    }
    return aMax;
}

void hienThiDonGiaMax(list x){
    cout << setw(20) << "MaHang" << setw(20) << "TenHang" << setw(20)
         << "NgayNhap" << setw(20) << "SoLuong" << setw(20) << "DonGia" << setw(20)
         << "ThanhTien" << endl;
    for(int i=0; i<x.n; i++){
        if(x.a[i].donGia == findMax(x)){
            x.a[i].xuat();
            cout << setw(20) << x.a[i].soLg * x.a[i].donGia << endl;
        }
    }
}

void swap(hangHoa &a, hangHoa &b){
    hangHoa tg = a;
    a = b;
    b = tg;
}

void sapXepGiamThanhTien(list x){
    
}

int main(){
    list a;
    cout << endl << setw(50) << "---- Danh sach mat hang vua nhap ----" << endl;    a.xuat();
    cout << "- Tong thanh tien cac mat hang duoc nhap vao thang 8 nam 2017 la: " << tongThanhTienThang8(a) << endl;
    cout << "- Danh sach cac mat hang co don gia cao nhat" << endl; hienThiDonGiaMax(a);

    a.~list();
    return 0;
}