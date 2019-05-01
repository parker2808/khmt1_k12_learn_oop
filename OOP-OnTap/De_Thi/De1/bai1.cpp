#include <iostream>
using namespace std;

class vector{
    int n;
    float *a;
public:
    vector(){
        n = 0;
        a = NULL;
    }
    vector(int x, float *b){
        n = x;
        a = new float[n];
        for(int i=0; i<n; i++)  a[i] = b[i];
    }
    ~vector(){
        n = 0;
        delete a;
    }
    float maxVector(){
        float mAx = a[0];
        for(int i=0; i<n; i++){
            if(a[i]>mAx)    mAx = a[i];
        }
        return mAx;
    }
    float minVector(){
        float mIn = a[0];
        for (int i = 0; i < n; i++){
            if(a[i]<mIn)    mIn = a[i];
        }
        return mIn;
    }
    friend istream &operator>>(istream &x, vector &y);
    friend ostream &operator<<(ostream &x, vector y);
};

istream &operator>>(istream &x, vector &y){
    cout << "n = "; x >> y.n;
    y.a = new float[y.n];
    for(int i=0; i<y.n; i++){
        cout << "a[" << i << "] = ";
        x >> y.a[i];
    }
    return x;
}

ostream &operator<<(ostream &x, vector y){
    for(int i=0; i<y.n; i++)    x << y.a[i] << ", ";
    x << endl;
    return x;
}

int main(){
    float b[10] = {5, 4, 3, 2, 1, -1, -2, -3, -4, -5};
    vector x(10, b);
    cout << "max[b] = " << x.maxVector() << endl;
    cout << "min[b] = " << x.minVector() << endl;
    cout << "- Thong tin mang khoi tao X: " << x;

    vector c;
    cout << "-- Nhap du lieu cho vector --" << endl;    cin >> c;
    cout << "- Gia tri nho nhat cua vector: " << c.minVector() << endl;
    cout << "- Gia tri lon nhat cua vector: " << c.maxVector() << endl;
    cout << "- Thong tin mang nhap C: " << c;
    return 0;
}