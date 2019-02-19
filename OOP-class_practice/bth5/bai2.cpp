#include <iostream>
#include "string.h"
#include "iomanip"
using namespace std;

class PRINTER{
protected:
    float trongLuong, tocDo;
    int namSX;
    string hangSX;
public:
};

class DOTPRINTER : public PRINTER{
    int matDoKim;
public:
    void nhap(){
        cout << "Trong luong: ";    cin >> trongLuong;  cin.ignore(1);
        cout << "Hang san xuat: ";  getline(cin, hangSX);
        cout << "Nam san xuat: ";   cin >> namSX;
        cout << "Toc do: "; cin >> tocDo;
        cin.ignore(1);
    }
    void xuat(){
        cout << ...
    }
}

// xem tiep trong OOP - home_pratice =.=