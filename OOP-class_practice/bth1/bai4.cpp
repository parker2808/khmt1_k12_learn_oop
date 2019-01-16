#include <iostream>
#include "string.h"
#include "iomanip"
#include "bai4.h"
using namespace std;

int main(){
    int n;
    cout << "Nhap vao tong so sach: ";  cin >> n;
    cin.ignore(1);
    Sach *x = new Sach[n];
    for(int i=0; i<n; i++){
        cout << "(STT" << i+1 << ")" << endl;
        x[i].nhap();
    }
    cout << "DU LIEU BAN VUA NHAP LA:" << endl;
    cout << setw(20) << "MASACH" << setw(20) << "TENSACH" << setw(10) << "NXB" << setw(10) << "SOTRANG" << setw(10) << "GIATIEN" << endl;
    for(int i=0; i<n; i++){
        x[i].xuat();
    }
    return 0;
}
