#include <iostream>
#include "string.h"
#include "iomanip"
using namespace std;

class DN{
    string tendn, diachi;
    int sonv;
    float doanhthu;
public:
    void nhap();
    void xuat();
};

void DN::nhap(){
    cout << "Ten doanh nghiep: ";   getline(cin, tendn);
    cout << "Dia chi: ";            getline(cin, diachi);
    cout << "So nhan vien: ";       cin >> sonv;
    cout << "Doanh thu: ";          cin >> doanhthu;
    cin.ignore(1);
}

void DN::xuat(){
    cout << setw(10) << tendn << setw(15) << diachi << setw(10) << sonv << setw(10) << doanhthu << endl;
}
