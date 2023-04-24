#include<iostream>
#include<bits/stdc++.h>

#include<map>											//thư viện chứa map
using namespace std;
//map là tập hợp các ánh xạ được khai báo theo kiểu map<key,value> mp
//giống như set các phần tử trong map được sắp xếp theo một trình tự xác định và không có phần tử nào có cùng cặp key
//map được coi là mảng các pair
struct cmp{
	bool operator()(int x,int y){
		return x>y;
	}
};
int main(){
	map<int,int> a;										//khai báo 1 map có cả key và value đèu là kiểu int		O(log(n))
	a.insert({4,400});									//insert(a,b) với a là key và b là value thêm 1 phần tử vào map		O(log(n))
	a.insert({3,300});
	a[5]=500;											//có thể thêm bằng cách a[x]=y với x,y là key value		O(log(n))
	a[2]=200;
	//cũng như nhiều container khác map cũng có thể sử dụng iterator để duyệt qua các phần tử 
	//vì bản chất của map là mảng các pair nên để truy cập vào key, value của map ta phải sử dụng 1 trong 2 cách sau:
	for(map<int,int> :: iterator it=a.begin();it!=a.end();it++){
		cout<<(*it).first<<"-"<<(*it).second<<"   ";	//(*it).first truy cập vào key, (*it).second truy cập vào value
	}
	cout<<endl;
	for(map<int,int> :: iterator it=a.begin();it!=a.end();it++){
		cout<<it->first<<"-"<<it->second<<"   ";		//it->first truy cập vào key, it->second truy cập vào value
	}													//giống như truy cập vào từng phần tử của struct
	cout<<endl;
	a[5]=600;											//thay vì thêm cặp (5,600) thì map sẽ thay đổi value của phần tử trước đó từ 500->600
	for(auto it=a.begin();it!=a.end();it++){			//có thể thay việc khai báo iterator bằng auto
		cout<<it->first<<"-"<<it->second<<"   ";
	}
	cout<<endl;
	map<int,char,cmp>b;									//có thể định nghĩa lại trình tự sắp xếp qua struct cmp
	b.insert({1,'a'});
	b[3]='c';
	b[2]='b';
	b[4]='d';
	for(auto x:b){										//cũng có thể duyệt map bằng vòng lặp for x
		cout<<x.first<<"-"<<x.second<<" ";				//các phần tử được sắp xếp từ lớn đến nhỏ theo key
	}
	cout<<endl;
	if(!b.empty())cout<<"map c khong rong"<<endl;		//hàm empty() trả về true nếu map rỗng ngược lai trả về 0	O(1)
	cout<<b.size()<<endl;								//hàm size() trả về số lượng phần tử của map	O(1)
	b.erase(3);											//hàm erase(x) với x là một key nào đó trong map sẽ xóa cặp (key, value) đó		O(log(n))
	for(auto x:b){
		cout<<x.first<<"-"<<x.second<<" ";
	}
	cout<<endl;
	b.erase(b.begin());									//cũng có thể xóa phần tử dựa vào iterator	O(log(n))
	for(auto x:b){
		cout<<x.first<<"-"<<x.second<<" ";
	}
	cout<<endl;
	b.erase(b.begin(),b.end());							//cách xóa này như các container khác
	b.clear();											//xóa tất cả các phần tử của map	O(n)
	if(b.empty())cout<<"map b rong"<<endl;
	map<int,int> c;	
	a.swap(c);											//cháo đổi các phần tử của 2 map	O(n)
	//b.swap(c);										//lỗi biên dịch trong trường hợp 2 map có kiểu dữ liệu khác nhau
	for(auto x:c){
		cout<<x.first<<"-"<<x.second<<" ";
	}
	cout<<endl;
	if(c.find(3)!=c.end()){								//hàm find() trả về iterator trỏ đến phần tử có key chỉ định	O(log(n))
		cout<<"3 la 1 key trong map c"<<endl;
	}
	if(c.find(1)==c.end()){								//trong trường hợp không có key trong map thì hàm sẽ trả về end()
		cout<<"1 khong phai la 1 key trong c"<<endl;
	}
	auto it1=c.upper_bound(3);							//trả về iterator trỏ đến phần từ có key lớn hơn key cho trước 	O(log(n))
	auto it2=c.lower_bound(3); 							//trả về iterator trỏ đến phần từ có key lớn hơn hoặc bằngkey cho trước		O(log(n))
	cout<<it1->first<<"-"<<it1->second<<endl;
	cout<<it2->first<<"-"<<it2->second<<endl;
	return 0;
}