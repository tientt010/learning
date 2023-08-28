#include <bits/stdc++.h>

using namespace std;
//giải phương trình tuyến tính ax + by = lcd(a,b);
//nghiệm x của phương trình này cũng chính là nghiệm của phương trình đồng dư a*x = 1 mod b;
pair<int,int>euclid(int a,int b){
    if(b==0)return {1,0};
    auto tmp = euclid(b,a%b);
    int x1=tmp.first,y1=tmp.second;
    return {y1,x1-a/b*y1};
}
//tìm ước chung lớn nhất
int lcd(int a,int b){
    return (b ? lcd(b,a%b) : a); 
}
//tim 1 nghiệm của phương trình tuyến tính a*x + b*y = c
void tim_1_ng(int a,int b,int c){
    bool p=a<0;
    bool k=b<0;
    a=abs(a);
    b=abs(b);
    int g=lcd(a,b);
    if(c%g!=0){
        cout<<"phuong trinh vo nghiem !"<<endl;
    }else{
        auto tmp=euclid(a,b);
        int x=tmp.first*(c/g)*(p ? -1 : 1);
        int y=tmp.second*(c/g)*(k ? -1 : 1);
        cout<<"x = "<<x<<" y = "<<y<<endl;
    }
}
//tìm tất cả các nghiệm của phương trình tuyến tính a*x + b*y = c trong khoảng minx đến maxx và miny đến maxy 
void tim_all_ng(int a,int b,int c,int minx,int maxx,int miny,int maxy){
    int g=lcd(abs(a),abs(b));
    if(c%g!=0){
        cout<<"phuong trinh vo nghiem !"<<endl; 
    }else{
        int p=c/g;
        vector<pair<int,int>> nghiem;
        auto tmp=euclid(abs(a),abs(b));
        int x0=tmp.first*p;
        if(a<0)x0=-x0;
        int y0=tmp.second*p;
        if(b<0)y0=-y0;
        double lx,rx,ly,ry;
        lx=(double)(minx-x0)/(b*g);
        rx=(double)(maxx-x0)/(b*g);
        ly=(double)(miny-y0)/(-(a*g));
        ry=(double)(maxy-y0)/(-(a*g));
        if(lx>rx)swap(lx,rx);
        if(ly>ry)swap(ly,ry);
        int l=ceil(max(lx,ly));
        int r=floor(min(rx,ry));
        cout<<"phuong trinh da cho co tat ca "<<r-l+1<<" nghiem : "<<endl;
        for(int i=l;i<=r;i++){
            cout<<x0+i*b/g<<" "<<y0-i*a/g<<endl;
        }
    }
}
//tìm cặp nghiệm có tổng nhỏ nhất của phương trình a*x + b*y = c
void tim_tong_min(int a,int b,int c,int minx,int maxx,int miny,int maxy){
    int g=lcd(abs(a),abs(b));
    if(c%g!=0){
        cout<<"phuong trinh vo nghiem !"<<endl; 
    }else{
        int p=c/g;
        vector<pair<int,int>> nghiem;
        auto tmp=euclid(abs(a),abs(b));
        int x0=tmp.first*p;
        if(a<0)x0=-x0;
        int y0=tmp.second*p;
        if(b<0)y0=-y0;
        double lx,rx,ly,ry;
        lx=(double)(minx-x0)/(b*g);
        rx=(double)(maxx-x0)/(b*g);
        ly=(double)(miny-y0)/(-(a*g));
        ry=(double)(maxy-y0)/(-(a*g));
     
        if(lx>rx)swap(lx,rx);
        if(ly>ry)swap(ly,ry);
        int l=ceil(max(lx,ly));
        int r=floor(min(rx,ry));
        if(b>=a){
            cout<<x0+l*b/g<<" "<<y0-l*a/g<<endl;
        }else{
            cout<<x0+r*b/g<<" "<<y0-r*a/g<<endl;
        }
    }
}


int main(){
    int a,b,c,minx,maxx,miny,maxy;
    cin>>a>>b>>c>>minx>>maxx>>miny>>maxy;
    tim_all_ng(a,b,c,minx,maxx,miny,maxy);
    tim_tong_min(a,b,c,minx,maxx,miny,maxy);
}