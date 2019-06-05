#include <iostream>
#include "string.h"
#include "iomanip"
using namespace std;

class quanLy;
class chuyenVien;
class congTacVien;
class nhanVien{
    char ten[10];
    int tuoi;
    char maSo[10];
    int ngayCong;
protected:
    void nhap(){
        cout << "Ten: ";        cin.getline(ten, 10);
        cout << "Tuoi: ";       cin >> tuoi;
        cin.ignore(1);
        cout << "Ma so: ";      cin.getline(maSo, 10);
        cout << "Ngay cong: ";  cin >> ngayCong;
        cin.ignore(1);
    }
    void xuat(){
        cout << setw(15) << ten << setw(15) << tuoi << setw(15) << maSo << setw(15) << ngayCong;
    }
};

class quanLy : nhanVien{
    string chucVu;
    string phongBan;
    int n;
public:
    void nhap(){
        cout << "Nhap vao so nhan vien la Quan Ly: ";  cin >> n;
        cin.ignore(1);
        for(int i=0; i<n; i++){
            cout << " - Quan Ly " << i+1 << ":" << endl;
            nhanVien::nhap();
            cout << "Chuc vu: ";    getline(cin, chucVu);
            cout << "Phong ban: ";  getline(cin, phongBan);
            cin.ignore(1);
        }
    }
    void xuat(){
        cout << setw(40) << "DANH SACH NHAN VIEN QUAN LY" << endl;
        cout << setw(15) << "Ten" << setw(15) << "Tuoi" << setw(15) << "MaSo"
             << setw(15) << "NgayCong" << setw(15) << "ChucVu" << setw(15) << "PhongBan" << endl;
        for(int i=0; i<n; i++){
            nhanVien::xuat();
            cout << setw(15) << chucVu << setw(15) << phongBan << endl;
        }
        cout << endl;
    }
    friend int soLuongNhanVien(quanLy a, chuyenVien b, congTacVien c);
};

class chuyenVien : nhanVien{
    string phongBan;
    string soDienThoai;
    int soHoaDon;
    int n;
public:
    void nhap(){
        cout << "Nhap vao so nhan vien la Chuyen Vien: ";  cin >> n;
        cin.ignore(1);
        for(int i=0; i<n; i++){
            cout << " - Chuyen Vien " << i+1 << ":" << endl;
            nhanVien::nhap();
            cout << "Phong ban: ";              getline(cin, phongBan);
            cout << "So dien thoai: ";          getline(cin, soDienThoai);
            cout << "So hoa don can xu ly: ";   cin >> soHoaDon;
            cin.ignore(1);
        }
        cout << endl;
    }
    void xuat(){
        cout << setw(40) << "DANH SACH NHAN VIEN CHUYEN VIEN" << endl;
        cout << setw(15) << "Ten" << setw(15) << "Tuoi" << setw(15) << "MaSo"
             << setw(15) << "NgayCong" << setw(15) << "PhongBan" << setw(15) << "SDT" << setw(15) << "HoaDon" << endl;
        for(int i=0; i<n; i++){
            nhanVien::xuat();
            cout << setw(15) << phongBan << setw(15) << soDienThoai << setw(15) << soHoaDon << endl;
        }
        cout << endl;
    }
    friend int soLuongNhanVien(quanLy a, chuyenVien b, congTacVien c);
};

class congTacVien : nhanVien{
    string kieuCV;
    int n;
public:
    void nhap(){
        cout << "Nhap vao so nhan vien la Cong Tac Vien: "; cin >> n;
        cin.ignore(1);
        for(int i=0; i<n; i++){
            cout << " - Cong Tac Vien " << i+1 << ":" << endl;
            nhanVien::nhap();
            cout << "Kieu cong viec (part-time/full-time): ";   getline(cin, kieuCV);
            cin.ignore(1);
        }
        cout << endl;
    }
    void xuat(){
        cout << "DANH SACH NHAN VIEN CONG TAC VIEN" << endl;
        cout << setw(15) << "Ten" << setw(15) << "Tuoi" << setw(15) << "MaSo"
             << setw(15) << "NgayCong" << setw(15) << "KieuCV" << endl;
        for (int i = 0; i < n; i++){
            nhanVien::xuat();
            cout << setw(15) << kieuCV << endl;
        }
    }
    friend int soLuongNhanVien(quanLy a, chuyenVien b, congTacVien c);
};

int soLuongNhanVien(quanLy a, chuyenVien b, congTacVien c){
    return a.n + b.n + c.n;
}

int main(){
    quanLy a;
    chuyenVien b;
    congTacVien c;
    a.nhap();   b.nhap();   c.nhap();
    a.xuat();   b.xuat();   c.xuat();
    cout << "- So luong nhan vien cong ty quan ly la: " << soLuongNhanVien(a, b, c) << endl;
    return 0;
}