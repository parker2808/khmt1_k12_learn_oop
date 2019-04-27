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
        delete[] a;
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
    }
    cout << endl;
};