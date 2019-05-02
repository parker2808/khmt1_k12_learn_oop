#include <iostream>
#include "iomanip"
#include "string.h"
using namespace std;

class list;

class noiDangKy{
    char huyen[30];
    char tinh[30];
public:
    void nhap(){
        cout << "Huyen: ";  cin.getline(huyen, 30);
        cout << "Tinh : ";  cin.getline(tinh, 30);
        cin.ignore(1);
    }
    void xuat(){
        cout << huyen << " - " << tinh;
    }
};

class date{
    int ngay, thang, nam;
public:
    void nhap(){
        cout << "Ngay : ";   cin >> ngay;
        cout << "Thang: ";  cin >> thang;
        cout << "Nam  : ";    cin >> nam;
        cin.ignore(1);
    }
    void xuat(){
        cout << ngay << "/" << thang << "/" << nam;
    }
    friend class list;
};

class xe{
protected:
    char hoTen[30];
    char bienSo[20];
    noiDangKy noiDk;
    date ngayDk;
public:
    void nhap(){
        cout << "Ho ten chu so huu: ";  cin.getline(hoTen, 30);
        cout << "Bien so: ";    cin.getline(bienSo, 20);
        cout << "-- Nhap noi dang ky --" << endl;
        noiDk.nhap();
        cout << "-- Nhap ngay dang ky --" << endl;
        ngayDk.nhap();
    }
    void xuat(){
        cout << setw(15) << hoTen << setw(15) << bienSo << setw(15);
        noiDk.xuat();
        cout << setw(10);
        ngayDk.xuat();
    }
    friend class list;
};

class xeMay : public xe{
    long giaTien;
    char mauSon[30];
public:
    void nhap(){
        xe::nhap();
        cout << "Gia tien: ";   cin >> giaTien; cin.ignore(1);
        cout << "Mau son: ";    cin.getline(mauSon, 30);
    }
    void xuat(){
        xe::xuat();
        cout << setw(15) << giaTien << setw(15) << mauSon << endl; 
    }
    friend class list;
};

class list{
    int n;
    xeMay *a;
public:
    void nhap(){
        cout << "Tong so xe may can nhap: ";    cin >> n;   cin.ignore(1);
        a = new xeMay[n];
        for(int i=0; i<n; i++){
            cout << "-- xe thu " << i+1 << " --" << endl;
            a[i].nhap();
        }
    }
    void xuat(){
        cout << setw(40) << "-- Danh sach xe may --" << endl;
        cout << "- Danh sach cac xe may dang ky nam 2016 va tren 20 trieu" << endl;
        cout << setw(15) << "HoTen" << setw(15) << "BienSo" << setw(20) << "NoiDK" << setw(24) << "NgayDK" << setw(15) << "GiaTien" << setw(15) << "MauSon" << endl;
        for(int i=0; i<n; i++){
            if(a[i].giaTien >= 20000000 && a[i].ngayDk.nam == 2016)  a[i].xuat(); 
            else{
                cout << endl << "- Danh sach khong co thong tin xe thoa man yeu cau" << endl;
                break;
            }
        }
    }
};

int main(){
    list a;
    a.nhap();
    a.xuat();
    return 0;
}