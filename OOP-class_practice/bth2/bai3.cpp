#include <iostream>
using namespace std;

class search{
    int n;
    float *a;
public:
    void input(){
        cout << "Nhap n = ";    cin >> n;
        a = new float[n];
        cout << "Nhap mang:" << endl;
        for(int i=0; i<n; i++){
            cout << "a[" << i << "] = ";
            cin >> a[i];
        }
    }
    float gtln(){
        float Max = a[0];
        for(int i=0; i<n; i++){
            if(a[i]>Max)    Max = a[i];
        }
        return Max;
    }
    float gtnn(){
        float Min = a[0];
        for(int i=0; i<n; i++){
            if(a[i]<Min)    Min = a[i];
        }
        return Min;
    }
};

int main(){
    search a;
    a.input();
    cout << "Gia tri lon nhat cua mang la: " << a.gtln() << endl;
    cout << "Gia tri nho nhat cua mang la: " << a.gtnn() << endl;
    return 0;
}