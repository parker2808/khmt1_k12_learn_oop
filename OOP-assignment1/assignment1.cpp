#include <iostream>
#include "string.h"
#include "iomanip"
using namespace std;

class Phieu_VPP;

class DATE{
    int d, m, y;
public:
    void nhap(){
        cout << "Ngay  : ";       cin >> d;
        cout << "Thang : ";       cin >> m;
        cout << "Nam   : ";       cin >> y;
    }
    void xuat(){
        cout << "Ngay lap:  " << d << "/ " << m << "/ " << y << endl;
    }
};

class NCC{
    string maNCC, tenNCC, diaChi, soDT;
public:
    void nhap(){
        cout << "Ma nha cung cap  : ";       getline(cin, maNCC);
        cout << "Ten nha cung cap : ";       getline(cin, tenNCC);
        cout << "Dia chi          : ";       getline(cin, diaChi);
        cout << "So dien thoai    : ";       getline(cin, soDT);
        cin.ignore(1);
    }
    void xuat(){
        cout << "Ma nha cung cap: " << maNCC << setw(32) << "Ten nha cung cap: " << tenNCC << endl;
        cout << "Dia chi: " << diaChi << setw(12) << "SDT: " << soDT << endl;
    }
};

class SP{
    string maSP, tenSP;
    int soLuong;
    float donGia;
public:
    void nhap(){
        cout << "Ma san pham  : ";       getline(cin, maSP);
        cout << "Ten san pham : ";       getline(cin, tenSP);
        cout << "So luong     : ";       cin >> soLuong;
        cout << "Don gia      : ";       cin >> donGia;
        cin.ignore(1);
    }
    void xuat(){
        cout << setw(15) << maSP << setw(15) << tenSP << setw(15) << soLuong << setw(15) << donGia << setw(15) << (float)soLuong*donGia << endl;
    }
    friend class Phieu_VPP;
    friend int dem_SoLuong(Phieu_VPP check);
    friend void sapXep_DonGia(Phieu_VPP sort);
};

class Phieu_VPP{
    string tenDH, maPhieu;
    DATE ngayLap;
    NCC nhaCC;
    SP *sanPham;    int n;
public:
    void nhap(){
        cout << endl << "Ten truong dai hoc : ";     getline(cin, tenDH);
        cout << endl << "NHAP THONG TIN PHIEU VAN PHONG PHAM" << endl;
        cout << endl << "Ma phieu           : ";     getline(cin, maPhieu);
        cout << endl << "NGAY THANH LAP" << endl;   ngayLap.nhap();     cin.ignore(1);
        cout << endl << "NHA CUNG CAP" << endl;     nhaCC.nhap();
        cout << endl << "THONG TIN SAN PHAM" << endl;
        cout << "Tong so san pham: ";   cin >> n;   cin.ignore(1);
        sanPham = new SP[n];
        for(int i=0; i<n; i++){
            cout << endl << "STT " << i+1 << endl;
            sanPham[i].nhap();
        }
    }
    void xuat(){
        cout << endl << "-----------------------------------------------------------------------------" << endl;
        cout << endl << endl << "Dai hoc " << tenDH << endl;
        cout << setw(45) << "PHIEU NHAP VAN PHONG PHAM" << endl << endl;
        cout << "Ma phieu:        " << maPhieu << setw(25);    ngayLap.xuat();
        nhaCC.xuat();   cout << endl;
        cout << setw(15) << "Ma SP" << setw(15) << "Ten san pham" << setw(15) << "So luong" << setw(15) << "Don gia" << setw(15) << "Thanh tien" << endl;
        float tong = 0;
        for(int i=0; i<n; i++){
            sanPham[i].xuat();
            tong += (float)sanPham[i].soLuong*sanPham[i].donGia;
        }
        cout << endl << setw(37) << "TONG" << setw(38) << tong << endl << endl;
        cout << setw(20) << "Hieu truong" << setw(25) << "Phong tai chinh" << setw(25) << "Nguoi lap" << endl << endl;
        cout << "-----------------------------------------------------------------------------" << endl;
    }
    friend int dem_SoLuong(Phieu_VPP check);
    friend void sapXep_DonGia(Phieu_VPP sort);
};

int dem_SoLuong(Phieu_VPP check){
    int dem = 0;
    for(int i=0; i<check.n; i++){
        if(check.sanPham[i].soLuong<80)    dem++;
    }
    return dem;
}

void doiCho(SP &a, SP &b){
    SP tg = a;  a = b;  b = tg;
}

void sapXep_DonGia(Phieu_VPP sort){
    for(int i=1; i<sort.n; i++){
        for(int j=0; j<sort.n-i; j++){
            if(sort.sanPham[j].donGia > sort.sanPham[j+1].donGia){
                doiCho(sort.sanPham[j], sort.sanPham[j+1]);
            }
        }
    }
}

int main(){
    Phieu_VPP a;
    a.nhap();
    a.xuat();
    cout << endl << "- So san pham co so luong nhap nho hon 80 trong danh sach la: " << dem_SoLuong(a) << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << endl << "- Phieu van phong pham sau khi duoc sap xep theo don gia :" << endl;
    sapXep_DonGia(a);
    a.xuat();
    return 0;
}