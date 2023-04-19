#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
//Có 3 kiểu khai báo vector thường được sử dụng:
//vector<int> vt;                               //khai báo thông thường
//vector<int> vt(n);                            //khai báo vector có n phần tử
//vector<int> vt(n,value);                      //khai báo vector có n phần tử đồng thời gán cho chúng giá trị value 
int main(){
    vector<int> vt;                             //khai báo vector vt kiểu int
    vt.push_back(10);                           //đẩy 1 phần tử vào cuối vector
    vt.push_back(20);                         
    vt.push_back(30);
    cout<<vt.size()<<endl;                      //truy suất đến số phần tử của vector
    vt.push_back(40);
    cout<<vt.size()<<endl;
    cout<<"phan tu dau tien trong vector la:"<< vt[0]<<endl;                    //có thể truy suất đến 1 phần tử dựa vào index
    cout<<"phan tu cuoi cung trong vector la:"<< vt[vt.size()-1]<<endl;
    cout<<"phan tu dau tien trong vector la:"<< vt.back()<<endl;                //truy xuất đến phần tử cuối cùng
    cout<<"phan tu co chi so la 2 trong vector la:"<<*(vt.begin()+2)<<endl;     //truy cấp đến 1 phần tử bất kì dựa vào iterator(bản chất là con trỏ)
    int m=vt.size();
    for(int i=0;i<m;i++){                                                       //duyệt vector thông thường dựa vào chỉ số
        cout<<vt[i]<<" ";
    }
    cout<<endl;
    for(int x:vt){                                                              //duyệt vector bằng vòng lập for x
        cout<<x<<" ";
    }
    cout<<endl;
    for(vector<int>::iterator it = vt.begin();it!=vt.end();it++){               //duyệt vector bằng iterator
        cout<<*it<<" ";
    }
    cout<<endl;
    for(auto it=vt.begin();it!=vt.end();it++){                                  //có thể thay vector<int>::iterator bằng auto
        cout<<*it<<" ";                                                     
    }
    cout<<endl;
    vt.resize(10);                                                              //hàm resize(n) sẽ thay đổi kích thước của vector thành n
    for(auto x:vt){                                                             //nếu số phần tử hiện tại của vector bé hơn n thì vector 
        cout<<x<<" ";                                                           //sẽ tự dộng thêm các phần tử bằng 0 vào chỗ còn thiếu
    }   
    cout<<endl;       
    vt.resize(3);                                                               //trong trường hợp số n nhỏ hơn số phần tử hiện tại của vector
    for(auto x:vt){                                                             //nó cũng sẽ tự động xóa những phần tử thừa, ưu tiên xóa các phần tử có chỉ số lớn hơn
        cout<<x<<" ";
    }                                                         
    cout<<endl;
    vt.resize(6,15);                                                            //hàm resize(n,p) nó tương tự như resize(n)                                            
    for(auto x:vt){                                                             //nhưng nó sẽ thêm(nếu có) các phần tử bằng p thay vì bằng 0 vào vector 
        cout<<x<<" ";                                                           //nó sẽ không làm ảnh hưởng đến những giá trị đã tồn tại sẵn trong vector
    }
    cout<<endl;
    int n;cin>>n;
    vector<int> test(n,100);                                                    //khai báo vector kiểu số nguyên có n phần tử và gán cho nó giá trị 100
    for(int x:test){
        cout<<x<<" ";
    }
    cout<<endl;
    vector<int> v(n);                                                           //khai báo vector kiểu số nguyên có n phần tử
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int x : v){
        cout<<x<<" ";
    }
    cout<<endl;
    vector<string> ten;                                                         //không chỉ làm việc với int vector còn có thể làm việc với rất nhiều kiểu dữ liệu khác
    ten.push_back("lap ");                                                      //string là 1 ví dụ
    ten.push_back("trinh ");
    ten.push_back("khong ");
    ten.push_back("kho ");
    for(vector<string> :: iterator it=ten.begin();it!=ten.end();it++){          //tương tự như int duyệt mảng bằng iterator cũng có thể áp dụng với cả kiểu string
        cout<<*it<<" ";
    }
    cout<<endl;
    string s= "lien quan mobile";
    stringstream ss(s);                                                         //hàm tách chữ sau này sẽ học
    string tmp;
    vector<string> game;
    while(ss>>tmp){                                                             //có thể dùng vector như một cách để tách chữ nhanh chóng
        game.push_back(tmp);
    }
    for(string x:game){
        cout<<x<<endl;
    }
    return 0; 
}
//Ngoài các hàm đã liệt kê phía trên còn một số hàm khác như:
//pop_back() xóa phần tử cuối cùng(có chỉ số cao nhất) trong vector
//front()trả về giá trị của phần tử đầu tiên trong vector
//back()trả về giá trị của phần tử cuối cùng có trong vector
//Một trong những hàm được sử dụng rát phổ biến nữa là erase();
//Cú pháp sử dụng vt.erase(it_l,it_r+1)
//it_l, it_r là 2 iterator biểu diễn đoạn phần tử muốn xóa
//VD muốn xóa 2 phần tử đầu ta dùng vt.erase(vt.begin(),vt.begin()+2);
//Xóa 2 phần tử cuối ta dùng vt.erase(vt.end()-2,vt.end());
//Muốn xóa các phần tử có chỉ số từ 5 đén 10 ta dùng vt.erase(vt.begin()+5,vt.begin()+11);
//Nói một cách tổng quan thì nếu ta muốn xóa tất cả các phần tử có chỉ số từ l đến r ta dùng vt.(vt.begin()+l,vt.begin()+r+1);