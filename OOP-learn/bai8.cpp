#include <iostream>
#include "string.h"
#include "iomanip"
#include "fstream"
using namespace std;


class sinhvien{
    int masv;
    char ht[30];
    int tuoi;
public:
    friend istream &operator>>(istream &x, sinhvien &y);
    friend ostream &operator<<(ostream &x, sinhvien y);
};

istream &operator>>(istream &x, sinhvien &y){
    cout << "Ma sinh vien: ";   x >> y.masv;    cin.ignore(1);
    cout << "Ho ten: ";         x.getline(y.ht, 200);
    cout << "Tuoi: ";           x >> y.tuoi;
    return x;
}

ostream &operator<<(ostream &x, sinhvien y){
    x << setw(20) << y.masv << setw(20) << y.ht << setw(20) << y.tuoi << endl;
    return x;
}

int main(){
    sinhvien a, b;
    cout << "Nhap sv A: " << endl;  cin >> a;
    cout << "Nhap sv B: " << endl;  cin >> b;
    cout << setw(20) << "MaSV" << setw(20) << "HoTen" << setw(20) << "Tuoi" << endl;
    cout << a;  cout << b;

    ofstream f("bai8.txt", ios::out);
    f << setw(20) << "MaSV" << setw(20) << "HoTen" << setw(20) << "Tuoi" << endl;
    f << a; f << b;
    return 0;
}