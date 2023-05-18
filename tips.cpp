#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    //Chuyển xâu sang số number=stoi*(string,pointer,hệ cơ số)
    //number là kết quả sau khi chuyển từ xâu sang số
    //* là kí tự kiểu dữ liệu(chữ cái đầu) có thể là i(int),l(long int),ll(long long),f(float),d(double),.....
    //string là chuỗi truyền vào
    //pointer là con trỏ sẽ chứa vị trí đầu tiên của kí tự k phải là số trong string
    //hê số nguyên có thể là 2(nhị phân),8(bát phân),10(thập phân)
    string s="100";
    cout<<stoi(s,nullptr,2)<<endl;                  //4
    cout<<stoi(s,nullptr,10)<<endl;                 //100
    //nếu bỏ trống 2 tham số sau thì mặc định sẽ là con trỏ null và hệ cơ số 10
    cout<<stoi("0101")<<endl;                       //101
    s="114abc";
    size_t pos;
    cout<<stoi(s,&pos)<<endl;                            
    cout<<pos<<endl;
    //Tách xâu
    string s1="lap,trinh,khong,kho";
    string s2="lien quan mobile";
    stringstream ss1(s1);
    stringstream ss2(s2);
    string p;
    while(getline(ss1,p,',')){
        cout<<p<<endl;
    }
    while(ss2>>p){                                  //nếu kí tự ngăn cách là dấu cách thì có thể truyền thẳng ss2>>p
        cout<<p<<endl;
    }
    //Khởi tạo 1 mảng, 1 vector là một dãy số tăng dần
    //cú pháp iota(begin,end,start)
    //begin và end là con trỏ đầu và cuối, start là giá trị khởi đầu
    vector<int> v(10);
    int a[10];
    iota(v.begin(),v.end(),1);
    iota(a,a+10,100);
    for(int x:v)cout<<x<<" ";
    cout<<endl;
    for(int x:a)cout<<x<<" ";
    cout<<endl;
    v.clear();
    //Xóa các phần tử trùng lặp trong vector
    //bằng cách kết hợp hàm sort và hàm unique
    v = {4,1,4,5,2,3,3,1,2,4};
    sort(begin(v),end(v));
    //hàm unique sẽ lần lượt đưa các phần tử k trùng lặp liên tiếp về đầu dãy
    //hiểu 1 cách đơn giản thì lúc này vector sẽ chia làm 2 phần phần đầu là những phần tử không trùng lặp 
    //phần sau là những phần tử trùng lặp cần phải xóa
    //cuối cùng nó sẽ trả về iterator trỏ đến phần tử đầu tiên của phần thứ 2
    auto it= unique(v.begin(),v.end());                 
    v.erase(it,v.end());                            //bước cuối cùng là xóa toàn bộ phần thứ 2
    for(int x:v)cout<<x<<" ";
    cout<<endl;
    v.clear();
    //Khiến cho phần tử thứ k về đúng vị trí của nó trong vector sau khi sắp xép
    //Nhưng không sắp xếp lại vector
    //Nhược điểm là sẽ xáo trộn lại vị trí của các phần tử còn lại
    v={6, 2, 4, 1, 8, 7, 3, 5, 9, 10};
    nth_element(begin(v),begin(v)+3,end(v));        //đảm bảo phần tử thứ 3 đã ở đúng vị trí  
    for(int x:v)cout<<x<<" ";                       //2 1 3 4 5 6 7 8 9 10
    cout<<endl;
    //Xem giá trị của 1 biến nào đó ở dòng viết hiện tại 
    #define whatIs(x) cerr << "Line " << __LINE__ << ": " << #x << " = " << (x) << endl
    whatIs(v[0]);                                   //2
    whatIs(s2);                                     //lien quan mobile
    //Chuyển 1 số sang dạng chuỗi nhị phân
    //hàm biset sẽ chuyển đổitham số truyền vào thành số đó dưới dạng nhị phân x=bitset(n)
    //bản chất hàm bitset sẽ trả về kiểu số nguyên nhưng vì thông thường ta hay sử dụng xâu kí tự để lưu kết quả
    int n=100;
    s=bitset<10>(n).to_string();                                
    cout<<s<<endl;
}