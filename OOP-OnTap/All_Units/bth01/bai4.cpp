#include <iostream>
#include "string.h"
#include "iomanip"
using namespace std;

class hocSinh{
    char hoTen[30];
    int tuoi;
    double diemToan, diemLy, diemHoa;
public:
    void nhap(){
        cout << "Ho ten: "; cin.getline(hoTen, 100);
        cout << "Tuoi: ";   cin >> tuoi;
        cout << "Diem toan: ";  cin >> diemToan;
        cout << "Diem ly: ";    cin >> diemLy;
        cout << "Diem hoa: ";   cin >> diemHoa;
        cin.ignore(1);
    }
    void xuat(){
        cout << setw(40) << "Thong tin hoc sinh" << endl;
        cout << setw(20) << "Ho Ten" << setw(20) << "Tuoi" << setw(20) << "Diem Toan" << setw(20) << "Diem Ly" << setw(20) << "Diem Hoa" << endl;
        cout << setw(20) << hoTen << setw(20) << tuoi << setw(20) << diemToan << setw(20) << diemLy << setw(20) << diemHoa << endl;
    }
    void xepLoai(){
        double trungBinh = (diemToan + diemLy + diemHoa)/3;
        if(trungBinh < 4) cout << "Hoc sinh trung binh." << endl;
        else{
            if(4 <= trungBinh && trungBinh <8)  cout << "Hoc sinh kha." << endl;
            else    cout << "Hoc sinh gioi." << endl;
        }
    }
};

int main(){
    hocSinh a;
    a.nhap();
    a.xuat();
    a.xepLoai();
    return 0;
}