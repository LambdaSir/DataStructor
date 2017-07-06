#include<iostream>
#include<cstdlib>
typedef int ElemType;
using namespace std;
typedef struct ListStack{
	ElemType data;
	struct ListStack *next;
}ListStack;

void initStack(ListStack *&head){
	head = new ListStack;
	head->next=NULL;
}
void push(ListStack *&head,int data){   //��ջ 
	ListStack *ptr;
	ptr=new ListStack;
	ptr->data=data;
	ptr->next=head->next;         //��ջ������Ϊջ�����ݣ�ͷָ�����һ�����ݣ� 
	head->next=ptr;
}

bool pop(ListStack *&head){      //��ջ 		
	ListStack *ptr=head->next;
	if(head->next==NULL)
	    return false;
	cout<<ptr->data<<endl;
	head->next=ptr->next;
	free(ptr);
	return true;
}
void show(ListStack *&head){
	ListStack *ptr=head->next;
	while(ptr!=NULL){
		cout<<ptr->data<<"   ";
		ptr=ptr->next;
	} 
}

int getLenth(ListStack *&head){
	ListStack *ptr=head->next;
	int i=0;
	while(ptr){
		i++;
		ptr=ptr->next;
	}
	return i;
} 

ElemType getTop(ListStack *&head){        //�õ�ջ����Ԫ�� 
	ListStack *ptr=head->next;
	return ptr->data;
}

bool isEmpty(ListStack *&head){      //�ж��Ƿ�Ϊ�� 
	return head->next==NULL;
}

void destroy(ListStack *&head){
	ListStack *ptr=head->next;
	while(ptr){
		free(head);
		head=ptr;
		ptr=ptr->next;
	}
	free(head);
}
int main(){
	ListStack *head;
	initStack(head);
	cout<<"��ʼ�����..."<<endl;	
	cout<<"��ջ..."<<endl;
	push(head,1);
	push(head,2);
	push(head,3);
	push(head,4);
	push(head,5);
	push(head,6);
	cout<<"��ջ��ɡ�"<<endl;
	cout<<"ջ������Ϊ��";
	show(head);
	cout<<endl<<"ջ�����Ϊ��"<<getLenth(head)<<endl;
	
	cout<<"ջ��Ԫ�أ�"<<getTop(head)<<endl;
	
	cout<<endl<<"����ջ��Ԫ��"<<endl; 
	pop(head);
	cout<<"ջ������Ϊ��";
	show(head);
	cout<<endl<<"ջ�����Ϊ��"<<getLenth(head)<<endl;
	
	cout<<"ջ��Ԫ�أ�"<<getTop(head)<<endl;
	
	cout<<"�Ƿ�Ϊ�գ�"<<isEmpty(head)<<endl; 
	
	destroy(head);
	cout<<endl<<"�������"<<endl;
	cout<<"�Ƿ�Ϊ�գ�"<<isEmpty(head)<<endl; 
	return 0;
}
