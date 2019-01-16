#include <iostream>
#include "string.h"
#include "iomanip"
using namespace std;

class HANG{
    string mahang, tenhang;
    float dongia;
    int soluong;
public:
    void nhap(){
        cout << "Ma hang: ";    getline(cin, mahang);
        cout << "Ten hang: ";   getline(cin, tenhang);
        cout << "Don gia: ";    cin >> dongia;
        cout << "So luong: ";   cin >> soluong;
        cin.ignore(1);
    }
    void xuat(){
        cout << setw(10) << mahang << setw(20) << tenhang << setw(10) << dongia << setw(10) << soluong << setw(20) << (float)dongia*soluong << endl;
    }
};
