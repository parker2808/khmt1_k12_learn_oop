#include <iostream>
#include "string.h"
#include "iomanip"
using namespace std;

class list;

class date{
    int day, month, year;
public:
    date(){
        day = month = year = 0;
    }
    date(int a, int b, int c){
        day = a;
        month = b;
        year = c;
    }
    void xuat(){
        cout << setw(20) << day << "/ " << month << "/ " << year;
    }
};

class hangHoa{
    int maHang;
    char tenHang[65];
    date ngayNhap;
    int soLg;
    long donGia;
public:
    hangHoa(){
        maHang = soLg = donGia = 0;
        strcpy(tenHang, " ");
        date();
    }
    hangHoa(int a, char b[65], int d, int e, int f, int g, long h){
        maHang = a;
        strcpy(tenHang, b);
        date(d, e, f);
        soLg = g;
        donGia = h;
    }
    void xuat(){
        cout << setw(20) << maHang << setw(20) << tenHang;
        ngayNhap.xuat();
        cout << setw(20) << soLg << setw(20) << donGia << endl;
    }
};

class list{
    int n;
    hangHoa *a;
public:
    list(){
        cout << "n = "; cin >> n;   cin.ignore(1);
        a = new hangHoa[n];
        for(int i=0; i<n; i++){
            
        }
    }
    ~list(){
        n = 0;
        delete a;
    }
};

int main(){
    
    return 0;
}