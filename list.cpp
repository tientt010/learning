#include<iostream>
#include<list>                                      //thư viện chứa list

using namespace std;
//Có 3 cách khai báo list thường dùng là:
//list<kiểu dữ liệu>lst;                        khai báo dsik lst thông thường,lst sẽ là rỗng
//list<kiểu dữ liệu>lst(n)                      khai báo dslk lst có n phần tử, mặc định các phần tử sẽ là 0
//list<kiểu dữ liệu>lst(n,p)                    khai báo dslk lst có n phần tử và khởi tạo tất cả các phần tử đó bằng p                       

int main(){
    list<int>a(5);                                              //khai báo dsik a có 5 phần tử và 5 phàn tử đó đều bằng 0;
    for(list<int>::iterator it=a.begin();it!=a.end();it++){     //đối với list chỉ có thể duyệt bằng iterator
        cout<<*it<<" ";
    }                  
    cout<<endl;                    
    list<int>b(6,5);                                            //khai báo dslk b có 6 phần tử và khởi tạo các phần tử đó bằng 5;
    for(auto it=b.begin();it!=b.end();it++){                    //có thể dùng auto để khai báo iterator một cách ngắn gọn
        cout<<*it<<" ";
    }
    cout<<endl;
    list<int>c;                                                 //khai báo dslk c rỗng
    for(int i=1;i<=5;i++){
        c.push_back(i);                                         //cũng giống như vector có thể sử dụng câu lệnh push_back() 
    }                                                           //để thêm 1 phần tử vào cuối dslk
    for(int x:c){                                               //cũng có thể dùng vòng lặp for x để duyệt qua dslk
        cout<<x<<" ";
    }
    cout<<endl;
    for(int i=1;i<=5;i++){                                  
        c.push_front(i);                                        //push_front cũng được dùng để đẩy 1 phần tử vào đầu dslk
    }
    for(int x:c){
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<c.front()<<" "<<c.back()<<endl;                       //hàm front() truy vấn đến phần tử nằm ở đầu dslk
    cout<<c.empty()<<endl;                                      //hàm empty() trả về true(1) nếu list rỗng ngược lại false(0)
    cout<<c.size()<<endl;                                       //hàm size() truy vấn đến số phần tử của dãy
    c.pop_back();                                               //xóa phàn tử ở đàu dslk
    c.pop_front();                                              //xóa phần tử ở cuối dslk
    for(int x:c){
        cout<<x<<" ";
    }
    cout<<endl;
    //Nhược điểm của list là khả năng truy vấn đến 1 phần tử bất kì trong dslk
    //Không thể truy vấn một cách đơn giản dựa theo chỉ số như trong mảng và vector với độ phức tạp là O(1)
    //Trong list muốn truy vấn đến 1 phần tử bất kì bắt buộc phải thông qua iterator với độ phức tạp là O(n)
    list<int> ::iterator p=c.begin();
    advance(p,2);                                               //advance(it,n)dịch con trỏ n lần
    *p=0;                                                       //bây giờ iterator p đang chỉ vào phần tử có chỉ só 2(số 2) 
    for(int x:c){                                               //4 3 0 1 1 2 3 4
        cout<<x<<" ";
    }
    cout<<endl;
    //Đối với list cũng giống như vector sử dụng câu lệnh erase() để xóa các phần tử
    //Nhưng với list không giống với vector, các phần tử trong líst chỉ có thể truy vấn dựa vào iterator 
    //nên không thể sử dụng câu lệnh nhanh v.erase(v.begin()+l,v.begin()+r+1) để xóa nhanh các phần tử từ l đến r được
    //Vì vậy để xóa các phần tử từ l đến r ta làm theo các bước sau:
    list<int>::iterator it1=c.begin(),it2=c.begin();            //khai báo 2 iterator it1 và it2 biểu thị cho l và r
    advance(it1,2);                                             //cần dịch phải it1 l lần để nó truy xuất đến phần tử có chỉ số l
    advance(it2,6);                                             //tương tự cũng phải dịch it2 r+1 lần để truy xuất đến phần tử r+1
    c.erase(it1,it2);                                           //hàm erase() để xóa phần tử
    for(int x:c){                                               //4 3 3 4
        cout<<x<<" ";
    }
    cout<<endl;
    c.remove(4);                                                //hàm remove(n) để xóa tất cả các phần tử có giá trị là n 
    for(int x:c){                                               //3 3
        cout<<x<<" ";
    }
    cout<<endl;
    list<int> d;
    d.push_back(4);
    d.push_back(7);
    d.push_back(2);
    d.push_back(6);
    d.push_back(5);
    d.sort();                                                   //để sắp xếp list từ bé đến lớn ta sử dụng hàm sort()
    for(int x:d){                                               //2 4 5 6 7
        cout<<x<<" ";
    }
    cout<<endl;
}