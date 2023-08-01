#include <iostream>
using namespace std;
void input(int &n);
int Fibonacci(int n);
int main(){
    int n;
    input(n);
    int check=Fibonacci(n);
    return 0;
}
void input(int &n){
    cout << "Nhập số n: ";
    cin >>  n;
}
int Fibonacci(int n){
    int f0=0,f1=1,f;
        for (int i = 0; i <= n; i++)
        {
            if(i<=1)
                f=i;
            else
            {
                f = f0 + f1;
                f0 = f1;
                f1 = f;
            }
            cout<<"Dãy Fibonacci là:"<<f<<endl;
        }
}
