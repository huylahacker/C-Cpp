#include <iostream>
using namespace std;
void nhap(int &n);
int SHH(int n);
void xuat(int kq);
int main()
{
    int n;
    nhap(n);
    int kq=SHH(n);
    xuat(kq);
}
void nhap(int &n){
    cout<<"Nhập vào số nguyên dương n: ";
    cin>>n;
}
int SHH(int n)
{
    int sum=0;
    if(n==0)
        return false;
    for(int i=1; i<=n/2; i++)
        if (n % i == 0)
            sum = sum + i;
        if (sum == n)
            return true;
        else
            return false;
}
void xuat(int kq) {
    if(kq==true)
        cout<<"Là số hoàn hảo";
    else
        cout<<"Không là số hoàn hảo";
}
