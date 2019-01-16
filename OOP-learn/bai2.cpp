#include <iostream>
#include "string.h"
#include "iomanip"
using namespace std;

class NCC{
    string mancc, tenncc;
public:
    void nhap(){
        cout << "Ma nha cung cap: ";    getline(cin, mancc);
        cout << "Ten nha cung cap: ";   getline(cin, tenncc);
        cin.ignore(1);
    }
    void xuat(){
        cout << "MA NHA CUNG CAP: " << mancc << endl;
        cout << "TEN NHA CUNG CAP: " << tenncc << endl;
    }
};

class HANG{
    string mah, tenh;
    float gia;
public:
    void nhap(){
        cout << "Ma hang: ";    getline(cin, mah);
        cout << "Ten hang: ";   getline(cin, tenh);
        cout << "Gia: ";    cin >> gia;
        cin.ignore(1);
    }
    void xuat(){
        cout << setw(10) << mah << setw(15) << tenh << setw(15) << gia << endl;
    }
};

class PHIEUNHAP{
    string maphieu;
    int ngay;
    NCC a;
    HANG *b;
    int n;
public:
    void nhap(){
        cout << "Ma phieu: ";   getline(cin, maphieu);
        cout << "Ngay: ";   cin >> ngay;
        cin.ignore(1);
        a.nhap();
        cout << "Nhap vao tong so mat hang: ";  cin >> n;
        cin.ignore(1);
        b = new HANG[n];
        for(int i=0; i<n; i++){
            cout << "(STT" << i+1 << ")" << endl;
            b[i].nhap();
        }
    }
    void xuat(){
        cout << endl;
        cout << setw(30) << "THONG TIN PHIEU NHAP" << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "MA PHIEU: " << maphieu << endl;
        cout << "NGAY: " << ngay << endl;
        a.xuat();
        cout << "-----------------------------------------------------------" << endl;
        cout << setw(30) << "DANH SACH PHIEU NHAP" << endl;
        cout << setw(10) << "MAHANG" << setw(15) << "TENHANG" << setw(15) << "GIA" << endl;
        for(int i=0; i<n; i++){
            b[i].xuat();
        }
    }
};

int main(){
    PHIEUNHAP x;
    x.nhap();
    cout << "-----------------------------------------------------------" << endl;
    x.xuat();
    cout << "-----------------------------------------------------------" << endl;
    return 0;
}
