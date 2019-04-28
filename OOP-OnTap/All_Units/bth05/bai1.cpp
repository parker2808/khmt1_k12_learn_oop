#include <iostream>
using namespace std;

class intArray{
    int n;
    int *a;
public:
    intArray(){
        n = 0;
        a = NULL;
    }
    intArray(int x, int *y){
        n = x;
        a = new int[n];
        for(int i=0; i<n; i++)  a[i] = y[i];
    }
    ~intArray(){
        n = 0;
        delete a;
    }
    void nhap(){
        cout << "n = "; cin >> n;
        a = new int[n];
        for(int i=0; i<n; i++){
            cout << "a[" << i+1 << "] = ";
            cin >> a[i];
        }
    }
    void xuat(){
        for(int i=0; i<n; i++)  cout << a[i] << " ";
        cout << endl;
    }
};

int main(){
    //khoi tao mang y gom 5 phan tu
    int y[5] = {1, 2, 3, 4, 5};
    //khai bao mang a, khoi tao gia tri cho a gom 5 phan tu theo mang y duoc khai bao ben tren
    intArray a(5, y);
    a.xuat();
    
    intArray b;
    b.nhap();   b.xuat();
    //giai phong bo nho cho b
    b.~intArray();  b.xuat();
    return 0;
}
