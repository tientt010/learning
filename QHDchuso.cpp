#include<bits/stdc++.h>
//cách làm chung của dạng quy hoạch động chứ số:
//int a[]                                             //lưu số cho trước dưới dạng mảng các chữ số
//int f[i][j]                                         //lưu giá trị của hàm thu(i,false,j)
// int thu(int i,bool gh,int j){
//     i dùng để lưu chữ số ta đang xét
//     gh dùng để lưu xem chữ số đó có bị giới hạn hay không
//     gh=true nếu tất cả các số đằng trước nó đã đạt đến giới hạn rồi ngược lại là false
//     j là yêu cầu của đề bài
//     if(i<0){        nếu ta đã xét hết các chữ số
//         return 1    nếu thỏa mãn
//         return 0    ngược lại
//     }
//     nếu giá trị của hàm thu(i,false,j)đã được tính trước đó rồi thì không phải tính lại
//     if(gh==false&&f[i][sodu]>=0)return f[i][sodu]
//     int kq
//     int maxc=(gh?ai:9)[]    nếu chữ số thứ i đạt giới hạn thì giá trị max của nó phải bé hơn a[i] ngược lại max=9
//     for(C=0;c<=maxc;c++){
//         kq+=thu(i-1,gh&&(c==maxc),...)  gọi đệ quy đến chữ số tiếp theo
//     }
//     if(gh==false)f[i][j]=kq      lưu lại giá trị của hàm thu(i,false,j) để không phai tính lại
//     return kq;
// }


//số các số có tổng bình phương các chữ số chia hết cho 3 nhỏ hơn n;
const long long mod=1e9+7;
long long a[1002];
long long f[1002][3];

long long thu(long long i,bool gh,long long sodu){
    if(i<0){
        if(sodu==0)return 1;
        else return 0;
    }
    if(gh==false&&f[i][sodu]>=0)return f[i][sodu];
    long long kq=0;
    long long maxc=(gh?a[i]:9);
    for(long long c=0;c<=maxc;c++){
        kq+=thu(i-1,gh&&(c==maxc),(sodu+c*c)%3);
    } 
    if(gh==false)f[i][sodu]=kq%mod;
    return kq%mod;
}

using namespace std;
int main(){
    memset(f,-1,sizeof(f));
    string s;
    cin>>s;
    long long n=s.size();
    long long loai=0;
    for(long long i=0;i<n;i++){
        a[n-1-i]=(long long)s[i]-'0';
        loai+=a[n-1-i]*a[n-1-i];
    }
    if(loai%3==0)loai=1;
    else loai =0;
    cout<<thu(n-1,true,0)-loai;
}