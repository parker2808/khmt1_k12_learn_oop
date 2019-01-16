#include <iostream>
#include "iomanip"
#include "string.h"
using namespace std;

class TSKK{
    string tenTs, tinhTrang;
    int soLuong;
public:
    void nhap(){
        cout << "Ten tai san: ";    getline(cin, tenTs);
        cout << "Tinh Trang: ";     getline(cin, tinhTrang);
        cout << "So luong: ";       cin >> soLuong;
        cin.ignore(1);
    }
    void xuat(){
        cout << setw(15) << tenTs << setw(20) << soLuong << setw(10) << tinhTrang << endl;
    }
    friend class PHIEUKK;
};

class NVKK{
    string tenNv, chucVu;
public:
    void nhap(){
        cout << "Ten nhan vien: ";  getline(cin, tenNv);
        cout << "Chuc vu: ";        getline(cin, chucVu);
        cin.ignore(1);
    }
    void xuat(){
        cout << "Nhan Vien Kiem Ke: " << tenNv << setw(20) << "Chuc Vu: " << chucVu << endl;
    }
};

class PHONG{
    string maPhong, tenPhong, tenTP;
public:
    void nhap(){
        cout << "Ma phong: ";           getline(cin, maPhong);
        cout << "Ten phong: ";          getline(cin, tenPhong);
        cout << "Ten truong phong: ";   getline(cin, tenTP);
        cin.ignore(1);
    }
    void xuat(){
        cout << "Ma Phong: " << maPhong << setw(20) << "Ten Phong: " << tenPhong << endl;
        cout << "Ten Truong Phong: " << tenTP << endl;
    }
};

class PHIEUKK{
    string maPhieu, ngay;
    NVKK b;
    PHONG c;
    TSKK *a;    int n;
public:
    void nhap();
    void xuat();
};

void PHIEUKK::nhap(){
    cout << "Ma phieu: ";   getline(cin, maPhieu);
    cout << "Ngay: ";       getline(cin, ngay);
    cout << "Nhap thong tin nhan vien kiem ke: " << endl;
    b.nhap();
    cout << "Nhap thong tin phong kiem ke: " << endl;
    c.nhap();
    cout << "Nhap vao tong so tai san: ";   cin >> n;
    cin.ignore(1);
    a = new TSKK[n];
    cout << "Nhap thong tin tai san kiem ke: " << endl;
    for(int i=0; i<n; i++){
        cout << "STT" << i+1 << endl;
        a[i].nhap();
    }
}

void PHIEUKK::xuat(){
    cout << setw(30) << "PHIEU KIEM KE" << endl;
    cout << "Ma phieu: " << maPhieu << setw(20) << "Ngay: " << ngay << endl;
    b.xuat();
    c.xuat();
    cout << setw(15) << "TENTAISAN" << setw(20) << "SOLUONG" << setw(10) << "TRANGTHAI" << endl;
    for(int i=0; i<n; i++){
        a[i].xuat();
    }
    int tongSoLuong = 0;
    for(int i=0; i<n; i++)  tongSoLuong += a[i].soLuong;
    cout << "So tai san da kiem ke: " << n << setw(25) << "Tong so luong: " << tongSoLuong << endl;
}

int main(){
    PHIEUKK a;
    a.nhap();
    a.xuat();
    return 0;
}
