#include <iostream>
using namespace std;

class sapXep{
    float *a;
    int n;
public:
    sapXep operator++(){
        for(int i=1; i<n; i++){
            for(int j=0; j<n-i; j++){
                if(a[j] > a[j+1]){
                    float tg = a[j];    a[j] = a[i];    a[i] = tg;
                }
            }
        }
        return *this;
    }
    sapXep operator--(){
        for (int i = 1; i < n; i++){
            for (int j = 0; j < n - i; j++){
                if (a[j] < a[j+1]){
                    float tg = a[j];    a[j] = a[i];    a[i] = tg;
                }
            }
        }
        return *this;
    }
    friend istream &operator>>(istream &x, sapXep &y);
    friend ostream &operator<<(ostream &x, sapXep y);
};

istream &operator>>(istream &x, sapXep &y){
    cout << "Nhap vao kich thuoc mang: ";   x >> y.n;
    y.a = new float[y.n];
    cout << "Nhap cac gia tri cho mang:" << endl;
    for(int i=0; i<y.n; i++){
        cout << "a[" << i+1 << "] = ";
        x >> y.a[i];
    }
    return x;
}

ostream &operator<<(ostream &x, sapXep y){
    for(int i=0; i<y.n; i++)    x << y.a[i] << ", ";
    cout << endl;
    return x;
}

int main(){
    sapXep a;
    cout << "Nhap mang A" << endl;  cin >> a;
    cout << "Cac gia tri cua mang A: " << a;
    cout << "Cac gia tri cua mang A sap xep tang dan: " << ++a;
    cout << "Cac gia tri cua mang A sap xep giam dan: " << --a;
    return 0;
}