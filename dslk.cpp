#include<iostream>
//DSLK có thể mở rộng hoặc thu hẹp một cách linh hoạt
//Các phần tử trong DSLK được gọi là Node,được cấp phát động
//Phần tử cuối cùng trong danh sách liên kết trỏ vào NULL
//Không lãng phí bộ nhớ nhưng cần bộ nhớ để lưu phần con trỏ
//Đây là CTDL cấp phát động nên khi còn dữ liệu còn thêm được phần tử vào DSLK
using namespace std; 
struct node{
	int data;									//du lieu
	struct node *next;							//link
};
node* makeNode(int x){
	node *newNode = new node();
	newNode->data=x;
	newNode->next=NULL;
	return newNode;
}

node* addNode(node *p,int x){
	node *tmp=new node();
	tmp->data=x;
	tmp->next=NULL;
	p->next=tmp;
	return tmp;
}

void duyet(node* head){							//duyệt DSLK
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
}
int count(node* head){							//hàm trả về số Node
	int dem=0;
	while(head!=NULL){
		dem++;
		head=head->next;
	}
	return dem;
}
void pushFront(node**head,int x){						//hàm thêm 1 phần tử vào DSLK(đầu danh sách)
	node* newNode = makeNode(x);						//bản chất là dùng con trỏ trỏ đến con trỏ khác lưu địa chỉ của head
	newNode->next= *head;								//có thể dùng cho cả C và C++
	*head= newNode;
}
void pushFront2(node *&head,int x){						//cũng là thêm 1 phần tử vào DSLK
	node* newNode = makeNode(x);						//bản chất là truyền tham chiếu head
	newNode->next= head;								//chỉ có thể dùng trong C++, C không hỗ trợ tham chiếu
	head = newNode;
}

int main(){
	node *head= makeNode(1); 
	node *p=head;
	for(int i=2;i<=15;i++){
		p=addNode(p,i);
	}
	duyet(head);
	cout<<endl;
	cout<<count(head)<<endl;
	for(int i=1;i<=20;i++){
		pushFront2(head,i);
	}
	duyet(head);
	cout<<endl;
	cout<<count(head)<<endl;
}