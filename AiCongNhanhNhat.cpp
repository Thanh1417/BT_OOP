#include<iostream>
class C{
    int a, b;
    public:
        void nhap(){std::cin >> a >> b;}
        int cong(){return a + b;}
};
int main(){
    C x; x.nhap(); std::cout << x.cong();
}