#include<bits/stdc++.h>
#include<map>

using namespace std;
//Khai báo map<key,value>mp;
//cũng giống như set các phần tử trong map cũng được sắp xếp theo chiều tăng dần của key.
 
int main(){
	map<int, int> mp;
	mp[1] = 100;													//có thể thêm phần tử cho map theo 2 cách
	mp[2] = 200;
	mp[4] = 400;
	mp.insert({3,300});
	mp.insert({5,500});
	cout<<mp.size()<<endl;
	mp[3]=600;														//khi thêm 1 phần tử vào map, nếu phần tử đó có key giống với phần tử trước đó thì map sẽ không thêm phần tử mới
	cout<<mp.size()<<endl;											//mà nó sẽ cập nhật giá trị của cái key bị trùng ấy bởi giá trị mới(600)
	for(pair<int, int>x : mp){										//cách duyệt map. Lưu ý:bản chất của map là các cặp pair lên khi khai báo x phải khai báo kiểu pair, có thể thay bằng auto
		cout<<x.first<<" "<<x.second<<endl;
	}
	for(map<int, int>::iterator	it=mp.begin();it!=mp.end();it++){   //cũng có thể sử dụng iterator để duyệt map
		cout<<(*it).first<<" "<<(*it).second<<endl;
	}
	if(mp.count(3)!=0){												//tìm kiếm key trong map. Lưu ý:chỉ tìm đc key không tìm đc gái trị. 
		cout<<"Ton tai key la 3 trong map"<<endl;
	}else{
		cout<<"Khong co key nao la 3 trong map"<<endl;
	}
	if(mp.find(3)!=mp.end()){										//cũng có thể dùng hàm find() để tìm kiếm nhưng phải chú ý là bản chất của hàm find() sẽ trả về iterator có giá trị bằng 3
			cout<<"Ton tai key la 3 trong map"<<endl;			    //vì vậy thay vì dùng !=0 thì ta dùng !=mp.end()
	}else{
		cout<<"Khong co key nao la 3 trong map"<<endl;
	}
	mp.erase(3);													//cũng gióng như set có thể dùng hàm erase()để xóa 1 phần tử, nhưng lưu ý: nó sễ xóa cả key và value.
	for(map<int, int>::iterator it=mp.begin();it!=mp.end();it++){
		cout<<(*it).first<<" "<<(*it).second<<endl;
	}
	return 0;
}