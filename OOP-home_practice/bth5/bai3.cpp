#include <iostream>
#include "iomanip"
#include "string.h"
using namespace std;

class VEHICLE{
protected:
    string nhanHieu, hang;
    int namSX;
public:
    void nhap(){
        cout << "Nhan hieu: ";  getline(cin, nhanHieu);
        cout << "Nam san xuat: ";   cin >> namSX;
        cin.ignore(1);
        cout << "Hang san xuat: ";  getline(cin, hang);
    }
    void xuat(){
        cout << setw(20) << nhanHieu << setw(15) << namSX << setw(15) << hang;
    }
};

class OTO : public VEHICLE{
    int soChoNgoi;
    float dungTich;
public:
    void nhap(){
        VEHICLE :: nhap();
        cout << "So cho ngoi: ";    cin >> soChoNgoi;
        cout << "Dung tich: ";      cin >> dungTich;
        cin.ignore(1);
    }
    void xuat(){
        VEHICLE :: xuat();
        cout << setw(15) << soChoNgoi << setw(15) << dungTich << endl;
    }
};

class MOTO : public VEHICLE{
    float phanKhoi;
public:
    void nhap(){
        VEHICLE :: nhap();
        cout << "PHan khoi: ";  cin >> phanKhoi;
        cin.ignore(1);
    }
    void xuat(){
        VEHICLE :: xuat();
        cout << setw(15) << phanKhoi << endl;
    }
};

int main(){
    OTO x;
    cout << "Nhap thong tin oto" << endl;   x.nhap();
    cout << endl << setw(50) << "THONG TIN OTO" << endl;
    cout << setw(20) << "NHAN HIEU" << setw(15) << "NAM SX" << setw(15) << "HANG" << setw(15) << "SO SLOT" << setw(15) << "DUNG TICH" << endl;
    x.xuat();

    cout << endl;

    MOTO y;
    cout << "Nhap thong tin moto" << endl;  y.nhap();
    cout << endl << setw(50) << "THONG TIN MOTO" << endl;
    cout << setw(20) << "NHAN HIEU" << setw(15) << "NAM SX" << setw(15) << "HANG" << setw(15) << "PHAN KHOI" << endl;
    y.xuat();

    return 0;
}