#include <iostream>
#include "string.h"
#include "iomanip"
using namespace std;

class SACH{
    string masach, tensach, nxb;
    int sotrang;
    float giatien;
public:
    void nhap(){
        cout << "Ma sach: ";    getline(cin, masach);
        cout << "Ten sach: ";   getline(cin, tensach);
        cout << "Nha xuat ban: ";   getline(cin, nxb);
        cout << "So trang: ";   cin >> sotrang;
        cout << "Gia tien: ";   cin >> giatien;
        cin.ignore(1);
    }
    void xuat(){
        cout << setw(10) << masach << setw(20) << tensach << setw(20) << nxb << setw(10) << sotrang << setw(20) << giatien << endl; 
    }
};

int main(){
    int n;
    cout << "Nhap vao so luong sach: ";     cin >> n;
    cin.ignore(1);
    SACH *a=new SACH[n];
    for(int i=0; i<n; i++){
        cout << "Loai sach " << i+1 << ":" << endl;
        a[i].nhap();
    }
    cout << setw(10) << "MASACH" << setw(20) << "TENSACH" << setw(20) << "NXB" << setw(10) << "SOTRANG" << setw(20) << "GIATIEN" << endl;
    for(int i=0; i<n; i++){
        a[i].xuat();
    }
    return 0;
}
