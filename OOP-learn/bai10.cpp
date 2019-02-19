#include <iostream>
#include "fstream"
using namespace std;

class ARRAY{
    float *a;
    int n;
public:
    friend istream &operator>>(istream &x, ARRAY &y);
    friend ostream &operator<<(ostream &x, ARRAY y);
};

istream &operator>>(istream &x, ARRAY &y){
    cout << "Tong so phan tu mang: ";   x >> y.n;
    y.a = new float[y.n];
    for(int i=0; i<y.n; i++){
        cout << "a[" << i+1 << "] = ";
        x >> y.a[i];
    }
    return x;
}

ostream &operator<<(ostream &x, ARRAY y){
    for(int i=0; i<y.n; i++)  x << y.a[i] << " ";
    x << endl;
    return x;
}

int main(){
    ARRAY a;
    cout << "Nhap mang thuc X" << endl; cin >> a;
    cout << "Mang thuc ban vua nhap la: "; cout << a;

    //xuat vao tep
    ofstream f;
    f.open("bai10.txt", ios::out);
    f << "Mang vua nhap: " << a;
    f.close();
    return 0;
}