#include <iostream>
using namespace std;

class soPhuc{
    float thuc, ao;
public:
    soPhuc(){
        thuc = ao = 0;
    }
    soPhuc(int a, int b){
        thuc = a;
        ao = b;
    }
    soPhuc operator!(){
        soPhuc tg;
        tg.thuc = -thuc;
        tg.ao = -ao;
        return tg;
    }
    soPhuc operator+(soPhuc b){
        soPhuc tg;
        tg.thuc = thuc + b.thuc;
        tg.ao = ao + b.ao;
        return tg;
    }
    soPhuc operator-(soPhuc b){
        soPhuc tg;
        tg.thuc = thuc - b.thuc;
        tg.ao = ao - b.ao;
        return tg;
    }
    friend istream &operator>>(istream &a, soPhuc &b);
    friend ostream &operator<<(ostream &a, soPhuc b);
};

istream &operator>>(istream &a, soPhuc &b){
    cout << "Phan thuc = "; a >> b.thuc;
    cout << "Phan ao = ";   a >> b.ao;
    return a;
}

ostream &operator<<(ostream &a, soPhuc b){
    a << b.thuc << " + " << b.ao << "i";
    return a;
}

int main(){
    soPhuc a, b;
    cout << "- Nhap so phuc a" << endl;   cin >> a;
    cout << "- Nhap so phuc b" << endl;   cin >> b;
    cout << "- So phuc a sau khi doi dau: " << !a << endl;
    cout << "- So phuc b sau khi doi dau: " << !b << endl;
    cout << "- Tong hai so phuc: (" << a << ") + (" << b << ") = " << a+b << endl;
    cout << "- Hieu hai so phuc: (" << a << ") + (" << b << ") = " << a-b << endl;
    return 0;
}