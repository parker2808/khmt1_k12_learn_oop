#include <iostream>
#include "iomanip"
#include "string.h"
using namespace std;

class HANG;

class DATE{
    int d, m, y;
public:
    friend class HANG;
    friend void search_Year(HANG *a, int n, int find_Year);
};

class HANG{
    string maHang, tenHang;
    DATE ngaySX;
public:
    void nhap(){
        cout << "Ma hang: ";    getline(cin, maHang);
        cout << "Ten hang: ";   getline(cin, tenHang);
        cout << "Ngay: ";    cin >> ngaySX.d;
        cout << "Thang: ";  cin >> ngaySX.m;
        cout << "Nam: ";    cin >> ngaySX.y;
        cin.ignore(1);
    }
    void xuat(){
        cout << setw(15) << maHang << setw(15) << tenHang << setw(15) << ngaySX.d << setw(15) << ngaySX.m << setw(15) << ngaySX.y << endl;
    }
    friend void search_Year(HANG *a, int n, int find_Year);
};

void search_Year(HANG *a, int n, int find_Year){
    int check = 0 ;
    for(int i=0; i<n; i++){
        if(a[i].ngaySX.y == find_Year)  check++;
    }
    if(check == 0)    cout << "Khong co mat hang nao duoc san xuat trong nam 2017" << endl;
    else{
        cout << setw(15) << "MaHang" << setw(15) << "TenHang" << setw(15) << "Ngay" << setw(15) << "Thang" << setw(15) << "Nam" << endl;
        for(int i=0; i<n; i++)  a[i].xuat();
    }
}

int main(){
    int n;
    cout << "Tong so mat hang: ";   cin >> n;   cin.ignore(1);
    HANG *a = new HANG [n];
    for(int i=0; i<n; i++){
        cout << "STT" << i+1 << endl;
        a[i].nhap();
    }
    cout << setw(30) << "Nhung mat hang san xuat trong nam 2017" << endl;
    search_Year(a, n, 2017);
    return 0;
}

