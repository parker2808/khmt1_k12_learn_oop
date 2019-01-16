#include <iostream>
#include "string.h"
#include "iomanip"
using namespace std;

class TRUONG{
    string matr, tentr, diachi;
    int sogv;
public:
    void nhap(){
        cout << "Ma truong: ";  getline(cin, matr);
        cout << "Ten truong: "; getline(cin, tentr);
        cout << "Dia chi: ";    getline(cin, diachi);
        cout << "So giao vien: ";   cin >> sogv;
        cin.ignore(1);
    }
    void xuat(){
        cout << setw(20) << matr << setw(20) << tentr << setw(20) << diachi << setw(20) << sogv << endl;
    }
};

int main(){
    int n;
    cout << "Nhap vao so truong can nhap: ";    cin >> n;
    cin.ignore(1);
    TRUONG *a = new TRUONG[n];
    for(int i=0; i<n; i++){
        cout << "STT" << i+1 << ": " << endl;
        a[i].nhap();
    }
    cout << setw(20) << "MATRUONG" << setw(20) << "TENTRUONG" << setw(20) << "DIACHI" << setw(20) << "SOGIAOVIEN" << endl;
    for(int i=0; i<n; i++){
        a[i].xuat();
    }
    return 0;
}
