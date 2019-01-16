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
        cout << "Ma hang: ";   getline(cin, mahang);
        cout << "Ten hang: ";   getline(cin, tenhang);
        cout << "Don gia: ";   cin >> dongia;
        cout << "So luong: ";  cin >> soluong;
        cin.ignore(1);
    }
    void xuat(){
        cout << setw(10) << mahang << setw(20) << tenhang << setw(10) << dongia << setw(10) << soluong << setw(20) << dongia*soluong << endl;
    }
};

int main(){
    int n;
    cout << "Nhap vao tong so mat hang can nhap: ";     cin >> n;
    cin.ignore(1);
    HANG *a=new HANG[n];
    for(int i=0; i<n; i++){
        cout << "Nhap mat hang thu " << i+1 << ":" << endl;
        a[i].nhap();
    }
    cout << endl;
    cout << setw(10) << "MAHANG" << setw(20) << "TENHANG" << setw(10) << "DONGIA" << setw(10) << "SOLUONG" << setw(20) << "THANHTIEN" << endl;
    for(int i=0; i<n; i++){
        a[i].xuat();
    }
    return 0;
}
