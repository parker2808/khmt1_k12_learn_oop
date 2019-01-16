#include <iostream>
#include "string.h"
using namespace std;

class SINHVIEN{
    string masv, hoten;
    int tuoi;
    int diem;
 public:
    void nhap(){
        cout << "Nhap ma sinh vien: ";  getline(cin, masv);
        cout << "Nhap ho va ten sinh vien: ";  getline(cin, hoten);
        cout << "Nhap tuoi sinh vien: ";    cin >> tuoi;
        cout << "Nhap diem cua sinh vien: ";    cin >> diem;
        cin.ignore(1);
    }
    void xuat(){
        cout << "MaSV: " << masv << "       " << "Hoten: " << hoten << "        " << "Tuoi: " << tuoi << "      " << "Diem: " << diem << endl;
    }
};

int main(){
    SINHVIEN a, b;
    a.nhap();   b.nhap();
    a.xuat();   b.xuat();
    return 0;
}
