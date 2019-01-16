#include <iostream>
#include "bai5.h"
using namespace std;

int main(){
    int n;  cout << "Nhap vao so loai xe: ";    cin >> n;
    cin.ignore(1);
    OTO *a = new OTO[n];
    for(int i=0; i<n; i++){
        cout << "STT" << i+1 << endl;
        a[i].nhap();
    }
    cout << endl << setw(35) << "DANH SACH OTO" << endl;
    cout << setw(10) << "MA OTO" << setw(10) << "GIAMUA" << setw(10) << "TYLE" << setw(10) << "NAMSD" << setw(15) << "GiaTriHT" << endl;
    for(int i=0; i<n; i++){
        a[i].xuat();
    }
    return 0;
}