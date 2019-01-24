#include <iostream>
#include "iomanip"
#include "string.h"
#include "stdio.h"
using namespace std;

class nguoi{
protected:
    char hoten[20], diachi[20];
    int tuoi;
public:
    void nhap(){
        cout << "Ho ten: "; cin.getline(hoten, 20);
        cout << "Dia chi: ";    cin.getline(diachi, 20);
        cout << "Tuoi: ";   cin >> tuoi;
        cin.ignore(1);
    }
    void xuat(){
        cout << setw(20) << hoten << setw(20) << tuoi << setw(20) << diachi;
    }
    nguoi(char *x, int y, char *z){
        strcpy(hoten, x);
        tuoi = y;
        strcpy(diachi, z);
    }
};

class sinhvien : public nguoi{
    char masv[20], nganh[20];
public:
    void nhap(){
        nguoi::nhap();
        cout << "Ma sinh vien: ";   cin.getline(masv, 20);
        cout << "Nganh: ";  cin.getline(nganh, 20);
        cin.ignore(1);
    }
    void xuat(){
        nguoi::xuat();
        cout << setw(20) << masv << setw(20) << nganh << endl;
    }
    sinhvien(char *x, int y, char *z, char *p, char *q) : nguoi(x, y, z){
        strcpy(masv, p);
        strcpy(nganh, q);
    }
};

int main(){
    sinhvien x("Tran Van C", 19, "HN", "123456", "Tran Duy Hung");
    x.xuat();
    return 0;
}