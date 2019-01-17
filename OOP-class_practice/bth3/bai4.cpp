#include <iostream>
#include "string.h"
#include "iomanip"
using namespace std;

class QUANLY{
    string maQL, hoTen;
public:
    void nhap(){
        cout << "Ma quan ly: ";     getline(cin, maQL);
        cout << "Ho ten: ";         getline(cin, hoTen);
    }
    void xuat(){
        cout << "Ma quan ly: " << maQL << setw(20) << "Ho ten: " << hoTen << endl;
    }
};

class MAY{
    string maMay, kieuMay, tinhTrang;
public:
    void nhap(){
        cout << "Ma may: ";     getline(cin, maMay);
        cout << "Kieu may: ";   getline(cin, kieuMay);
        cout << "Tinh trang: "; getline(cin, tinhTrang);
    }
    void xuat(){
        cout << setw(10) << maMay << setw(20) << kieuMay << setw(20) << tinhTrang << endl;
    }
};

class PHONGMAY{
    string maPhong, tenPhong;
    float dienTich;
    QUANLY x;
    MAY *y;     int n;
public:
    void nhap(){
        cout << "Ma phong: ";   getline(cin, maPhong);
        cout << "Ten phong: ";  getline(cin, tenPhong);
        cout << "Dien tich: ";  cin >> dienTich;
        cin.ignore(1);
        cout << endl << "THONG TIN QUAN LY" << endl;      x.nhap();
        cout << endl << "THONG TIN MAY" << endl;
        cout << "Tong so may: ";    cin >> n;
        cin.ignore(1);
        y = new MAY[n];
        for(int i=0; i<n; i++){
            cout << "STT" << i+1 << endl;
            y[i].nhap();
        }
    }
    void xuat(){
        cout << "Ma phong: " << maPhong << setw(22) << "Ten phong: " << tenPhong << endl;
        cout << "Dien tich: " << dienTich << endl;
        x.xuat();
        cout << endl << setw(35) << "THONG TIN MAY" << endl;
        cout << setw(10) << "MAMAY" << setw(20) << "KIEUMAY" << setw(20) << "TINHTRANG" << endl;
        for(int i=0; i<n; i++){
            y[i].xuat();
        }
    }
};

int main(){
    PHONGMAY a;
    a.nhap();
    cout << endl << setw(40) << "THONG TIN PHONG MAY" << endl;
    a.xuat();
    return 0;
}