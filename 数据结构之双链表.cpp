#include<iostream>
#include<cstdlib>
typedef int ElemType;
using namespace std;
typedef struct DoubleList{
	int data;
	struct DoubleList *pre;
	struct DoubleList *next;
}DoubleList;

void initList(DoubleList *&head){
	head = new DoubleList;
	head->pre=head->next=NULL;
	
}
DoubleList *createList(DoubleList *&head){
	DoubleList *ptr=head->next,*temp=head;
	int n;
    cout<<"������Ҫ�����������ݣ�";
    cin>>n;
    for(int i=0;i<n;i++){
    	ptr = new DoubleList;
    	cin>>ptr->data;
    	temp->next=ptr;
    	ptr->pre=temp;
    	temp=ptr;
	}
	temp->next=NULL;
	return head;
}
bool inseartList(DoubleList *&head,int key,int value){
	DoubleList *ptr=head->next,*Node;
	while(ptr){
		if(key==ptr->data){
			Node = new DoubleList;
			Node->data=value;
			Node->next=ptr->next;
			Node->pre=ptr;
			ptr->next=Node;
			cout<<"�������"<<endl;
			return true; 
		}
		ptr=ptr->next;
	}
	cout<<"����ʧ��,����û�ҵ���Ҫ�����λ��..."<<endl;
	return false;
}
bool deleteList(DoubleList *&head,int data){
	DoubleList *temp = head,*ptr=head->next;
	while(ptr){
		if(data==ptr->data){
			temp->next=ptr->next;
			cout<<"ɾ���ɹ�"<<endl;
			free(ptr);
			return true;
		}
		temp=ptr;
		ptr=ptr->next;
	}
	cout<<"ɾ��ʧ��,����������û�������..."<<endl;
	return false;
}
void showList(DoubleList *&head){
	DoubleList *ptr=head->next;
	while(ptr){
		cout<<ptr->data<<"   ";
		ptr=ptr->next; 
	}
}
int main(){
	DoubleList *head;
	
	initList(head);
	cout<<"��ʼ�����"<<endl;
	
	head=createList(head);
	cout<<"�������"<<endl;
	
	cout<<"�������";
	showList(head); 
	
	cout<<"��������...";
	inseartList(head,2,9);
	cout<<"�������";
	showList(head);
	
	cout<<endl<<"ɾ������...";
	deleteList(head,2);
	cout<<"�������";
	showList(head);
	 
	return 0;
}
