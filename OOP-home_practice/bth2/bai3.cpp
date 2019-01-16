#include <iostream>
using namespace std;
class findvalue{
    int n;
    float *a;
public:
    void input(){
        cout << "Nhap vao so phan tu mang: ";   cin >> n;
        a = new float[n];
        cout << "Nhap mang: " << endl;
        for(int i=0; i<n; i++){
            cout << "a[" << i << "] = ";
            cin >> a[i];
        }
    }
    void output(){
        for(int i=0; i<n; i++){
            cout << a[i] << ", ";
        }
    }
    float Max(){
        float MAX=a[0];
        for(int i=0; i<n; i++){
            if(a[i]>MAX)    MAX=a[i];
        }
        return MAX;
    }
    float Min(){
        float MIN=a[0];
        for(int i=0; i<n; i++){
            if(a[i]<MIN)    MIN=a[i];
        }
        return MIN;
    }
};
int main(){
    findvalue a;
    a.input();
    cout << "Cac phan tu mang la: ";    a.output();
    cout << endl;
    cout << "Phan tu lon nhat cua mang la: " << a.Max() << endl;
    cout << "Phan tu nho nhat cua mang la: " << a.Min() << endl;
    return 0;
}
