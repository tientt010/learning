#include<iostream>
#include<stack>

using namespace std;
int main(){
    stack<int>s;
    for(int i=1;i<=10;i++){
        s.push(i);                                          //push() thêm 1 phần tử vào stack      O(1)
    }                                                       //1 2 3 4 5 6 7 8 9 10
    cout<<s.size()<<endl;                                   //size()trả về kích thước của stack     O(1)
    if(!s.empty()){
        cout<<"stack khong rong"<<endl;                     //empty() trả về true(1) nếu rỗng và ngược lại  O(1)
    }
    s.pop();                                                //pop() loại bỏ phần tử ở đỉnh stack    O(1)
    s.pop();                                                //1 2 3 4 5 6 7 8 
    s.pop();                                                //1 2 3 4 5 6 7 
    cout<<s.top()<<endl;                                    //top()truy cập vào phần tử ở đỉnh stack                                    
    while(!s.empty()){                                      //duyệt stack
        cout<<s.top()<<" ";                                 //1 2 3 4 5 6 7
        s.pop();
    }
    return 0;
}