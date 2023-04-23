#include<iostream>
using namespace std;
// quicksort2 phổ biến và thường được sử dụng nhiều hơn
int partition2(int a[],int l,int r){
	int x=a[r];														//chọn phần tử cuối cùng làm khóa
	int i=l-1;                                                      //khởi tạo một biến nhớ nhằm đánh dấu vị trí mới của phần tử khóa;     
	for(int j=l;j<r;j++){
		if(a[j]<=x){												//chia mảng thành 2 phần, phần bên trái gồm những phần tử nhỏ hơn khóa và ngược lại
			i++;
			swap(a[i],a[j]);
		}
	}
	i++;
	swap(a[i],a[r]);												//chuyển phần tử khóa về vị trí nằm giữa 2 phần vừa được chia bên trên
	return i;														//trả về vị trí của phần tử khóa
}
void quicksort2(int a[],int l,int r){
	if(l>=r)return;													
	int p=partition2(a,l,r);											//khởi tạo một biến nhớ làm khóa 
	quicksort2(a,l,p-1);												//đệ quy đến phần bên trái;
	quicksort2(a,p+1,r);												//đệ quy đến phần bên phải;
}
int partition(int a[],int l,int r){
	int x=a[l];														//chọn phần tử đầu tiên làm chốt;
	int i=l-1, j=r+1;												//khởi tạo hai biến đánh giấu giá trị bên trái, phải
	while(1){														//lặp vĩnh viễn
		do{
			i++;
		}while(a[i]<x);												//tìm phần tử bên trái có giá trị lớn hơn hoặc bằng chốt(sai vị trí)
		do{
			j--;
		}while(a[j]>x);												//tìm phần tử bên phải có giá trị nhỏ hơn hoặc bằng chốt(sai vị trí)
		if(i<j){
			swap(a[i],a[j]);										//đổi vị trí hai phần tử bên trên để nó trở về đúng vị trí						
		}else return j;
	}
}
void quicksort(int a[],int l,int r){
	if(l>=r)return;
	int p=partition(a,l,r);											//khởi tạo một biến nhớ làm chốt
	quicksort(a,l,p);												//hàm đệ quy
	quicksort(a,p+1,r);
}
int main(){
	int n,a[1000];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	quicksort(a,0,n-1);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	int m,b[1000];
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>b[i];
	}
	quicksort2(b,0,m-1);
	for(int i=0;i<m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}