#include <iostream>
#include "string.h"
#include "iomanip"
#include "bai3.h"
using namespace std;

int main(){
    int n;
    cout << "Nhap vao tong so mat hang: ";  cin >> n;
    cin.ignore(1);
    HANG *a = new HANG[n];
    for(int i=0; i<n; i++){
        cout << "(STT" << i+1 << ")" << endl;
        a[i].nhap();
    }
    cout << endl <<  "DU LIEU BAN VUA NHAP LA:" << endl << endl;
    cout << setw(10) << "MAHANG" << setw(20) << "TENHANG" << setw(10) << "DONGIA" << setw(10) << "SOLUONG" << setw(20) << "THANHTIEN" << endl;
    for(int i=0; i<n; i++){
        a[i].xuat();
    }
    return 0;
}
