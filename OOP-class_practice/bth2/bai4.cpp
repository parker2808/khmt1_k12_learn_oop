#include <iostream>
#include "bai4.h"
using namespace std;

int main(){
    int n;      cout << "Nhap vao tong so doanh nghiep: ";  cin >> n;
    cin.ignore(1);
    DN *a = new DN[n];
    for(int i=0; i<n; i++){
        cout << "STT" << i+1 << endl;
        a[i].nhap();
    }
    cout << endl << setw(40) << "DANH SACH DOANH NGHIEP" << endl;
    cout << setw(10) << "TENDN" << setw(15) << "DIACHI" << setw(10) << "SONV" << setw(10) << "DOANHTHU" << endl;
    for(int i=0; i<n; i++){
        a[i].xuat();
    }
    return 0;
}
