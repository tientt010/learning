#include <iostream>
using namespace std;

void swap1(int &x,int &y){                          //truyền tham chiếu
    int tmp=x;
    x=y;
    y=tmp;
}

void swap2(int *x,int *y){                          //truyền con trỏ
    int tmp=(*x);
    (*x)=(*y);
    (*y)=tmp;
}
int main()
{
    int a=2,b=5;
    //swap1(a,b);
    swap1(a,b);
    cout<<a<<" "<<b;
}