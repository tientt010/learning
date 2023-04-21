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
	return 0;		
}
