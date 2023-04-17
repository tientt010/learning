#include<iostream>
#include<utility>												//thư viện chứa pair
#include<tuple>													//thư viện chứa tuple

using namespace std;
int main(){
	pair<int,int> v{100,200};
	cout<< v.first<<endl;
	cout<< v.second<<endl;
	tuple<int,int,int>t={1,2,3};
	cout<<get<0>(t)<<endl;
	return 0;
	
}