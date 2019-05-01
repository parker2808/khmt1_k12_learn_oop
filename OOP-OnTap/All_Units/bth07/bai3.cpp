#include <iostream>
#include "string.h"
#include "iomanip"
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
        cout << day << "/" << month << "/" << year;
    }
    friend class khoa;
    friend class nhanSu;
};

class Truong{
    char tenTruong[70];
    date ngayThanhLap;
public:
    friend class khoa;
    friend void findStudent(list x);
};

class khoa{
    char tenKhoa[60];
    date ngayThanhLap;
    Truong truong;
public:
    void nhap(){
        cout << "Ten khoa: ";   cin.getline(tenKhoa, 60);
        cout << "-- Ngay thanh lap khoa --" << endl;    ngayThanhLap.nhap();
        cout << "Ten truong: "; cin.getline(truong.tenTruong, 70);
        cout << "-- Ngay thanh lap truong --" << endl;  truong.ngayThanhLap.nhap();
    }
    void xuat(){
        cout << setw(15) << tenKhoa << setw(15);
        ngayThanhLap.xuat();
        cout << setw(15) << truong.tenTruong << setw(15);
        truong.ngayThanhLap.xuat();
    }
    friend void findStudent(list x);
};

class nhanSu{
protected:
    char hoTen[30];
    date ngaySinh;
    char hoKhauTt[50];
public:
    void nhap(){
        cout << "Ho ten: "; cin.getline(hoTen, 30);
        cout << "-- Ngay sinh --" << endl;  ngaySinh.nhap();
        cout << "Ho khau thuong tru: ";  cin.getline(hoKhauTt, 50);
    }
    void xuat(){
        cout << setw(15) << hoTen << setw(15);
        ngaySinh.xuat();
        cout << setw(15) << hoKhauTt;
    }
    nhanSu(){
        strcpy(hoTen, " ");
        ngaySinh.day = ngaySinh.month = ngaySinh.year = 0;
        strcpy(hoKhauTt, " ");
    }
    nhanSu(char a[30], int b, int c, int d, char e[50]){
        strcpy(hoTen, a);
        ngaySinh.day = b;
        ngaySinh.month = c;
        ngaySinh.year = d;
        strcpy(hoKhauTt, e);
    }
};

class sinhVien : public nhanSu{
    khoa Khoa;
    char tenLop[20];
    double diemTk;
public:
    void nhap(){
        nhanSu::nhap();
        Khoa.nhap();
        cout << "Ten lop: ";    cin.getline(tenLop, 20);
        cout << "Diem tong ket: ";  cin >> diemTk;  cin.ignore(1);
    }
    void xuat(){
        nhanSu::xuat();
        Khoa.xuat();
        cout << setw(15) << tenLop << setw(15) << diemTk << endl;
    }
    friend void sapXepTang(list x);
    friend void findStudent(list x);
};

class list{
    int n;
    sinhVien *a;
public:
    void nhap(){
        cout << "Nhap tong so sinh vien: "; cin >> n;   cin.ignore(1);
        a = new sinhVien[n];
        for(int i=0; i<n; i++){
            cout << endl << "-- Sinh vien thu " << i+1 << " --" << endl;
            a[i].nhap();
        }
    }
    void xuat(){
        cout << endl << setw(70) << "-- Danh sach sinh vien --" << endl;
        cout << setw(15) << "HoTen" << setw(22) << "NgaySinh" << setw(15) << "HoKhau" << setw(15) << "Khoa" << setw(22) << "NgayTlKhoa" << setw(15) << "Truong" << setw(22) << "NgayTlTruong" << setw(15) << "Lop" << setw(15) << "DiemTk" << endl;
        for(int i=0; i<n; i++)  a[i].xuat();
        cout << endl;
    }
    friend void sapXepTang(list x);
    friend void findStudent(list x);
};

void swap(list &a, list &b){
    list tg = a;    a = b;  b = tg;
}

void sapXepTang(list x){
    for(int i=1; i<x.n; i++){
        for(int j=0; j<x.n-i; j++){
            if(x.a[j].diemTk > x.a[j+1].diemTk)   swap(x.a[j], x.a[j+1]);
        }
    }
}

void findStudent(list x){
    for(int i=0; i<x.n; i++){
        if(strcmp(x.a[i].Khoa.truong.tenTruong, "DHCNHN")==0) x.a[i].xuat();
    }
    cout << endl;
}

int main(){
    list a;
    a.nhap();
    a.xuat();
    sapXepTang(a);
    cout << "-- Danh sach sinh vien sau khi sap xep tang dan theo diem tong ket --" << endl;    a.xuat();
    cout << "-- Danh sach sinh vien cua truong DHCN Ha Noi --" << endl; findStudent(a);
    return 0;
}