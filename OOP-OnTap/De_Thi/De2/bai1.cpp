#include <iostream>
using namespace std;

class complex{
    float thuc, ao;
public:
    complex(){
        thuc = ao = 0;
    }
    complex(float a, float b){
        thuc = a;
        ao = b;
    }
    complex operator+(complex y){
        complex tg;
        tg.thuc = thuc + y.thuc;
        tg.ao = ao + y.ao;
        return tg;
    }
    friend istream &operator>>(istream &x, complex &y);
    friend ostream &operator<<(ostream &x, complex y);
};

istream &operator>>(istream &x, complex &y){
    cout << "Phan thuc = "; x >> y.thuc;
    cout << "Phan ao   = ";   x >> y.ao;
    return x;
}

ostream &operator<<(ostream &x, complex y){
    cout << y.thuc << "/" << y.ao;
    return x;
}

int main(){
    int n;
    complex *a;
    cout << "- Tong so phuc can nhap: ";  cin >> n;
    a = new complex[n];
    cout << "- Nhap cac so phuc" << endl;
    for(int i=0; i<n; i++){
        cout << "-- So phuc thu " << i+1 << " --" << endl;
        cin >> a[i];
    }
    //tinh tong cac so phuc trong mang vua nhap
    complex tong;
    for(int i=0; i<n; i++)  tong = tong + a[i];
    cout << "- Tong cac so phuc vua nhap: " << tong << endl;
    return 0;
}