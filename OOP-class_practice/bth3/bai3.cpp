#include <iostream>
#include "string.h"
#include "iomanip"
using namespace std;

class HANG{
    string maH, tenH;
    float donGia;
public:
    void nhap(){
        cout << "Ma hang: ";    getline(cin, maH);
        cout << "Ten hang: ";   getline(cin, tenH);
        cout << "Don gia: ";    cin >> donGia;
        cin.ignore(1);
    }
    void xuat(){
        cout << setw(10) << maH << setw(15) << tenH << setw(15) << donGia << endl;
    }
};

class PHIEU{
    string maPhieu;
    HANG *x;
    int n;
public:
    void nhap(){
        cout << "Ma phieu: ";   getline(cin, maPhieu);
        cout << endl << "NHAP THONG TIN MAT HANG" << endl;
        cout << "Nhap tong so mat hang can nhap: ";     cin >> n;
        cin.ignore(1);
        x = new HANG[n];
        for(int i=0; i<n; i++){
            cout << "STT" << i+1 << endl;
            x[i].nhap();
        }
    }
    void xuat(){
        cout << setw(20) << "Ma phieu: " << maPhieu << endl;
        cout << endl << setw(30) << "THONG TIN MAT HANG" << endl << endl;
        cout << setw(10) << "MAHANG" << setw(15) << "TENHANG" << setw(15) << "DONGIA" << endl;
        for(int i=0; i<n; i++){
            x[i].xuat();
        }
    }
};

int main(){
    PHIEU a;
    a.nhap();
    cout << endl << setw(30) << "THONG TIN PHIEU NHAP" << endl;
    a.xuat();
    return 0;
}