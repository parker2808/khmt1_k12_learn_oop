#include <iostream>
#include "iomanip"
#include "string.h"
using namespace std;

class PRINTER{
protected:
    float trongLuong, tocDo;
    string hangSX;
    int namSX;
};

class DOTPRINTER : public PRINTER{
    int matDoKim;
public:
    void nhap(){
        cout << "Trong luong: ";    cin >> trongLuong;
        cin.ignore(1);
        cout << "Hang san xuat: ";  getline(cin, hangSX);
        cout << "Nam san xuat: ";   cin >> namSX;
        cout << "So trang/ phut: "; cin >> tocDo;
        cout << "Mat do kim: "; cin >> matDoKim;
        cin.ignore(1);
    }
    void xuat(){
        cout << setw(20) << trongLuong << setw(20) << hangSX << setw(20) << namSX << setw(20) << tocDo << setw(20) << matDoKim << endl;
    }
};

class LASERPRINTER : public PRINTER{
    string resolution;
public:
    void nhap(){
        cout << "Trong luong: ";    cin >> trongLuong;
        cin.ignore(1);
        cout << "Hang san xuat: ";  getline(cin, hangSX);
        cout << "Nam san xuat: ";   cin >> namSX;
        cout << "So trang/ phut: "; cin >> tocDo;
        cin.ignore(1);
        cout << "Do phan giai: ";   getline(cin, resolution);
    }
    void xuat(){
        cout << setw(20) << trongLuong << setw(20) << hangSX << setw(20) << namSX << setw(20) << tocDo << setw(20) << resolution << endl;
    }
};

int main(){
    DOTPRINTER mayKim;
    cout << "Nhap thong tin may kim" << endl;   mayKim.nhap();
    cout << endl << setw(60) << "THONG TIN MAY KIM" << endl << endl;
    cout << setw(20) << "TRONG LUONG" << setw(20) << "HANG SX" << setw(20) << "NAM SX" << setw(20) << "TOC DO" << setw(20) << "MAT DO KIM" << endl;
    mayKim.xuat();

    cout << endl;

    LASERPRINTER mayLaser;
    cout << "Nhap thong tin may laser" << endl; mayLaser.nhap();
    cout << endl << setw(60) << "THONG TIN MAY LASER" << endl << endl;
    cout << setw(20) << "TRONG LUONG" << setw(20) << "HANG SX" << setw(20) << "NAM SX" << setw(20) << "TOC DO" << setw(20) << "DO PHAN GIAI" << endl;
    mayLaser.xuat();
    return 0;
}