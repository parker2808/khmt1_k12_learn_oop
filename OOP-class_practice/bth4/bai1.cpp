#include <iostream>
#include "iomanip"
#include "string.h"
using namespace std;

class SINHVIEN{
    string maSV, hoTen;
    float toan, ly, hoa;
public:
    void nhap(){
        cout << "Ma sinh vien : ";  getline(cin, maSV);
        cout << "Ho ten       : ";  getline(cin, hoTen);
        cout << "Diem toan    : ";  cin >> toan;
        cout << "Diem ly      : ";  cin >> ly;
        cout << "Diem hoa     : ";  cin >> hoa;
        cin.ignore(1);
    }
    void xuat(){
        cout << setw(15) << maSV << setw(15) << hoTen << setw(15) << toan << setw(15) << ly << setw(15) << hoa << setw(15) << gettongDiem() << endl;
    }
    float gettongDiem(){
        return toan + ly + hoa;
    }
    friend void sort_TongDiem(SINHVIEN *a, int n);
};

void swap_Value(SINHVIEN &a, SINHVIEN &b){
    SINHVIEN tg = a;    a = b;  b = tg;
}

void sort_TongDiem(SINHVIEN *a, int n){
    for(int i=1; i<n; i++){
        for(int j=0; j<n-1; j++){
            if(a[j].gettongDiem() > a[j+1].gettongDiem())     swap_Value(a[j], a[j+1]);
        }
    }
}

int main(){
    int n;
    cout << "Tong so sinh vien: ";  cin >> n;   cin.ignore(1);
    SINHVIEN *a = new SINHVIEN [n];
    for(int i=0; i<n; i++){
        cout << "STT" << i+1 << endl;
        a[i].nhap();
    }
    cout << endl;
    sort_TongDiem(a, n);
    cout << setw(15) << "MaSinhVien" << setw(15) << "HoTen" << setw(15) << "DiemToan" << setw(15) << "DiemLy" << setw(15) << "DiemHoa" << setw(15) << "TongDiem" << endl;
    for(int i=0; i<n; i++)  a[i].xuat();
    return 0;
}
