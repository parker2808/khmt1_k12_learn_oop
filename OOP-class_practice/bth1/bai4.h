#include <iostream>
#include "string.h"
#include "iomanip"
using namespace std;

class Sach{
    string masach, tensach, nxb;
    int sotrang;
    float giatien;
public:
    void nhap(){
        cout << "Ma sach: ";    getline(cin, masach);
        cout << "Ten sach: ";   getline(cin, tensach);
        cout << "Nha xuat ban: ";   getline(cin, nxb);
        cout << "So trang: ";   cin >> sotrang;
        cout << "Gia tien: ";   cin >> giatien;
        cin.ignore(1);
    }
    void xuat(){
        cout << setw(20) << masach << setw(20) << tensach << setw(10) << nxb << setw(10) << sotrang << setw(10) << giatien << endl;
    }
};
