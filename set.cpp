#include<iostream>
#include<set>

using namespace std;
// set sẽ không lưu các phần tử trùng nhau
// set sẽ tự động sắp xếp các phần tử theo thứ tự từ nhỏ đến lớn 
struct cmp{														//viết lại hàm so sánh trong set(từ lớn tới bé)
	bool operator()(int a,int b){								//biến so sánh
		return a>b;												//nếu a>b return 1 ngược lại return 0
	}
};
int main(){
	set<int> a;
	a.insert(4);												//dùng hàm a.insert(x) để thêm x vào a		O(log(n))
	a.insert(3);
	a.insert(7);
	a.insert(6);
	a.insert(4);												//không thể thêm 1 phần tử nếu phần tử đó đã tồn tại trong set
	for(set<int>::iterator it=a.begin();it!=a.end();it++){		//cũng như các container khác có thể sử dụng iterator để duyệt set
		cout<<*it<<" ";
	}
	cout<<endl;
	cout<<a.size()<<endl;										//hàm size() dùng để truy xuất đến số phần tử của set		O(1)
	if(!a.empty())cout<<"set a khong rong"<<endl;				//hàm empty() trả về true(1) nếu set rỗng ngược lại trả về false(0)		O(1)
	set<int,cmp> b;												//có thể khai báo set bằng cách set<int,cmp> với cmp là 1 struct
	b.insert(4);												//bây giờ set b sẽ có quy luật sắp xếp được viết trong struct cmp(từ lớn tới bé)
	b.insert(3);
	b.insert(7);
	b.insert(6);
	b.insert(4);
	for(int x:b){												//có thể duyệt set bằng vòng lặp for x
		cout<<x<<" ";
	}
	cout<<endl;
	set<int>::iterator it=b.find(4);							//hàm find(x)sẽ trả về iterator trỏ đến phần tử mang giá trị x trong set	O(log(n))
	if(it==b.end()){											//trong trường hợp không tồn tại x trong set hàm sẽ trả về s.end()
		cout<<"khong ton tai 4 trong b"<<endl;
	}else{
		cout<<"ton tai 4 trong b"<<endl;
	}	
	set<int>c;
	for(int i=1;;i=i*2+1){									
		c.insert(i);											//1 3 7 15 31 63 127
		if(c.size()==7)break;
	}
	//hàm erase() có tác dụng xóa 1 hoặc nhiều phần tử trong set
	//để xóa 1 phần tử trong set c ta dùng câu lệnh c.erase(x)		O(log(n))
	c.erase(7);													//x có thể là 1 giá trị cụ thể set sẽ tìm và xóa phần tử có giá trị =x
	c.erase(c.begin());											//x cũng có thể là 1 iterator chỉ đến phần tử ta muốn xóa
	for(int x:c){
		cout<<x<<" ";											//3 15 31 63 127
	}
	cout<<endl;
	//để xóa nhiều phần tử từ l đến r ta phải tìm đc iterator chỉ đén điểm đầu (l) và điểm cuối +1 (r+1)
	set<int>::iterator it1=c.begin(),it2=c.begin();				//tạo 2 iterator chỉ vào phần tử đầu tiên trong set
	advance(it1,1);												//it1 chỉ vào phần tử thứ 2
	advance(it2,3);												//it2 chỉ vào phần tử thứ 4
	c.erase(it1,it2);											//xóa tất cả các phần tử từ thứ 2 đến thứ 3
	for(int x:c){
		cout<<x<<" ";											//3 63 127
	}		
	cout<<endl;
	it1=c.upper_bound(63);										//upper_bound(x)trả về iterator chỉ đến phần tử nhỏ nhất >x		O(log(n))
	it2=c.lower_bound(63);										//lower_bound(x)trả về iterator chỉ đến phần tử nhỏ nhất >=x	O(log(n))
	cout<<*it1<<" "<<*it2<<endl;								//127 63 trong trường hợp k có số thỏa mãn trong set thì trả về end()
	
	return 0;		
}
