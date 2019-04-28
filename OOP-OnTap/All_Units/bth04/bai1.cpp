#include <iostream>
#include "iomanip"
#include "string.h"
using namespace std;

class list;

class date{
    int day, month, year;
public:
    friend class list;
    friend long tongThanhTienThang8(list x);
    friend long maxDonGia(list x);
    friend void hienThiDonGiaCaoNhat(list x);
};

class hangHoa{
    int maHang;
    char tenHang[65];
    date ngayNhap;
    int soLg;
    long donGia;
    long thanhTien;
public:
    friend class list;
    friend long tongThanhTienThang8(list x);
    friend long maxDonGia(list x);
    friend void hienThiDonGiaCaoNhat(list x);
    friend void sapXepGiam(list x);
};

class list{
    int n;
    hangHoa *a;
public:
    void nhap(){
        cout << "Tong so hang can nhap: ";  cin >> n;
        while(n>30){
            cout << "Yeu cau nhap n<=30, moi nhap lai: ";
            cin >> n;
        }
        cin.ignore(1);
        a = new hangHoa[n];
        cout << "Nhap thong tin hang hoa" << endl;
        for(int i=0; i<n; i++){
            cout << "---- Mat hang thu " << i+1 << " ----" << endl;
            cout << "Ma hang: ";    cin >> a[i].maHang; cin.ignore(1);
            cout << "Ten hang: ";   cin.getline(a[i].tenHang, 65);
            cout << "- Nhap thoi gian" << endl;
            cout << "Ngay: ";   cin >> a[i].ngayNhap.day;
            cout << "Thang: ";  cin >> a[i].ngayNhap.month;
            cout << "Nam: ";    cin >> a[i].ngayNhap.year;
            cout << "So luong: ";   cin >> a[i].soLg;
            cout << "Don gia: ";    cin >> a[i].donGia;
            cin.ignore(1);
            a[i].thanhTien = a[i].soLg * a[i].donGia;
        }
    }
    void xuat(){
        cout << endl << setw(60) << "---- Danh sach hang hoa ----" << endl;
        cout << endl << setw(10) << "MaHang" << setw(20) << "TenHang"
             << setw(20) << "NgayNhap" << setw(10) << "SoLuong" << setw(15) << "DonGia"
             << setw(20) << "ThanhTien" << endl;
        for(int i=0; i<n; i++){
            cout << setw(10) << a[i].maHang << setw(20) << a[i].tenHang 
                 << setw(11) << a[i].ngayNhap.day << "/ " << a[i].ngayNhap.month << "/ " << a[i].ngayNhap.year 
                 << setw(10) << a[i].soLg << setw(15) << a[i].donGia 
                 << setw(20) << a[i].thanhTien << endl;
        }
    }
    friend long tongThanhTienThang8(list x);
    friend long maxDonGia(list x);
    friend void hienThiDonGiaCaoNhat(list x);
    friend void sapXepGiam(list x);
};

long tongThanhTienThang8(list x){
    long thanhTien = 0;
    for(int i=0; i<x.n; i++){
        if(x.a[i].ngayNhap.month == 8 && x.a[i].ngayNhap.year == 2017){
            thanhTien+=(long)(x.a[i].thanhTien);
        }
    }
    return thanhTien;
}

long maxDonGia(list x){
    long maxDG = x.a[0].donGia;
    for(int i=0; i<x.n; i++){
        if(x.a[i].donGia > maxDG)   maxDG = x.a[i].donGia;
    }
    return maxDG;
}

void hienThiDonGiaCaoNhat(list x){
    long tg = maxDonGia(x);
    cout << endl
         << setw(10) << "MaHang" << setw(20) << "TenHang"
         << setw(20) << "NgayNhap" << setw(10) << "SoLuong" << setw(15) << "DonGia"
         << setw(20) << "ThanhTien" << endl;
    for(int i=0; i<x.n; i++){
        if(x.a[i].donGia == tg){
            cout << setw(10) << x.a[i].maHang << setw(20) << x.a[i].tenHang
                 << setw(11) << x.a[i].ngayNhap.day << "/ " << x.a[i].ngayNhap.month << "/ " << x.a[i].ngayNhap.year
                 << setw(10) << x.a[i].soLg << setw(15) << x.a[i].donGia
                 << setw(20) << x.a[i].soLg * x.a[i].donGia << endl;
        }
    }
}

void swap(list &a, list &b){
    list tg = a;
    a = b;
    b = tg;
}

void sapXepGiam(list x){
    for(int i=1; i<x.n; i++){
        for(int j=0; j<x.n-i; j++){
            if(x.a[j].thanhTien < x.a[j+1].thanhTien)   swap(x.a[j], x.a[j+1]);
        }
    }
}

int main(){
    list a;
    a.nhap();
    a.xuat();
    cout << endl << "Tong thanh tien cac hang hoa nhap thang 8 nam 2017 la: " << tongThanhTienThang8(a) << endl;
    cout << endl << "Danh sach cac mat hang co don gia cao nhat" << endl;
    hienThiDonGiaCaoNhat(a);
    cout << endl << "Danh sach hang hoa sau khi sap xep theo chieu giam dan cua thanh tien" << endl;    sapXepGiam(a);
    a.xuat();
    return 0;
}