#include <iostream>
#include "string.h"
#include "iomanip"
using namespace std;

class SINHVIEN{
    string masv, hoten;
    int tuoi;
    float diem;
public:
    void nhap(){
        cout << "Ma sinh vien: ";   getline(cin, masv);
        cout << "Ho Ten: ";         getline(cin, hoten);
        cout << "Tuoi: ";           cin >> tuoi;
        cout << "Diem: ";           cin >> diem;
        cin.ignore(1);
    }
    void xuat(){
        cout << setw(20) << masv << setw(20) << hoten << setw(10) << tuoi << setw(10) << diem << endl;
    }
};

int main(){
    SINHVIEN a, b;
    cout << "Nhap sinh vien a" << endl;
    a.nhap();
    cout << "Nhap sinh vien b" << endl;
    b.nhap();
    cout << endl << "Du lieu ban vua nhap la: " << endl;
    cout << setw(20) << "MASV" << setw(20) << "HOTEN" << setw(10) << "TUOI" << setw(10) << "DIEM" << endl;
    a.xuat();
    b.xuat();
    return 0;
}
