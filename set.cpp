#include<bits/stdc++.h>
#include<set>

using namespace std;
// set sẽ không lưu các phần tử trùng nhau
// set sẽ tự động sắp xếp các phần tử theo thứ tự từ nhỏ đến lớn 
int main(){
	set<int> s;
	s.insert(100);										//thêm 1 phần tử
	s.insert(700);
	s.insert(300);
	s.insert(400);
	s.insert(100);
	s.insert(300);
	cout<<s.size()<<endl;								//in ra số phần tử
	if(s.find(700)!=s.end())							//kiểm tra xem 700 có nằm trong set hay không.
	{													//bản chất của s.find() là tìm đến interester(la lá con trỏ) có chứa phần tử 700 
		cout<<"700 co trong set"<<endl;
	}else{
		cout<<"khong tim thay 700"<<endl;
	}
	if(s.count(400)!=0)									//kiểm tra xem 400 có nằm trong set hay không tương tự như find.
	{													//bản chất cuẩ count là đếm xem có bao nhiêu phần tử trong set. 
		cout<<"400 co trong set"<<endl;
	}else{
		cout<<"khong tim thay 400"<<endl;
	}
	for(int x : s)										//in ra màn hình các phần tử của set
	{
		cout<<x<<" ";
	}
	cout<<endl;
	for(auto x:s){
		cout<<x<<" ";
	}
	cout<<endl;
	s.erase(700);										//xóa 1 phần tử trong set
	for(int x:s){
		cout<<x<<" ";
	}
	cout<<endl;
	cout<<*s.begin()<<endl;								//xuất ra phần tử đầu tiên có trong set(phần tử nhỏ nhất)
	cout<<*s.rbegin()<<endl;							//chỏ đến phần tử đối diện phần tử đầu tiên(phần tử cuối cùng)
	cout<<*s.lower_bound(300)<<endl;					//trả về iterator trỏ tới phần tử nhỏ nhất có giá trị lớn hơn hoặc bằng khóa key trong set.
	cout<<*s.upper_bound(300)<<endl;					//trả về iterator trỏ tới phần tử nhỏ nhất có giá trị lớn hơn khóa key trong set.
	set<int> b;
	int n;												//có thể coi set như 1 hàm sắp xếp nhanh
	cin>>n;
	for(int i=0; i<n;i++){
		int x;
		cin >>x;
		b.insert(x);
	}
	for(int x:b){
		cout<<x<<" ";
	}
	cout<<endl;
	multiset<string> ms;								//multiset giống y hệt set dùng chung các hàm của set nhưng chỉ khác là nó chấp nhận nhiều phần tử giống nhay
	ms.insert("tien");
	ms.insert("tuyen");
	ms.insert("thinh");
	ms.insert("thai");
	ms.insert("tu");
	ms.insert("thang");
	ms.insert("tien");
	ms.insert("tu");
	ms.insert("tuan");
	cout<<ms.size()<<endl;
	for(string x:ms){
		cout<<x<<" ";
	}
	cout<<endl;
	ms.erase("tien");									// khi sử dụng hàm erase trong multiset thì nó sẽ xóa tất cả các phần tử được khai báo.
	for(string x:ms){
		cout<<x<<" ";
	}
	cout<<endl;
	return 0;	
}

