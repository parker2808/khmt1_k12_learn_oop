#include <iostream>
using namespace std;

class soPhuc{
    float thuc, ao;
public:
    soPhuc(){
        thuc = ao = 0;
    }
    soPhuc(float a, float b){
        thuc = a;
        ao = b;
    }
    soPhuc operator+(soPhuc y){
        soPhuc tg;
        tg.thuc = thuc + y.thuc;
        tg.ao = ao + y.ao;
        return tg;
    }
    friend istream &operator>>(istream &x, soPhuc &y);
    friend ostream &operator<<(ostream &x, soPhuc y);
};

istream &operator>>(istream &x, soPhuc &y){
    cout << "phan thuc = "; x >> y.thuc;
    cout << "phan ao   = "; x >> y.ao;
    return x;
}

ostream &operator<<(ostream &x, soPhuc y){
    if(y.ao>0)
        x << y.thuc << " + " << y.ao << "i";
    else
        x << y.thuc << " - " << abs(y.ao) << "i";
    return x;
}

int main(){
    int n;
    soPhuc *a;
    cout << "n = "; cin >> n;
    a = new soPhuc[n];
    for(int i=0; i<n; i++){
        cout << "-- so phuc thu " << i+1 << " --" << endl;
        cin >> a[i];
    }

    // tong cac so phuc vua nhap
    soPhuc tong;
    for(int i=0; i<n; i++)  tong = tong + a[i];
    cout << "Tong cac so phuc vua nhap: " << tong << endl;
    return 0;
}