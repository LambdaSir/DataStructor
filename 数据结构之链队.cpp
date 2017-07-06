#include<iostream>
#include<cstdlib>
typedef int ElemType;
using namespace std;
typedef struct Node{
	ElemType data;
	struct Node *next;    //���нṹ 
}Node;
typedef struct ListQueue{
	Node *front;
	Node *rear;           //��ͷ�Ͷ�βָ�� 
}ListQueue;

void InitQueue(ListQueue *&head){
	head = new ListQueue;
	head->front=head->rear=NULL;//��ͷ�Ͷ�β��ֵΪ�� 
}
void EnQueue(ListQueue *&head,int data){
	Node *ptr= new Node;
	ptr->data=data;
	ptr->next=NULL;
	if(head->front==NULL){
		head->front=head->rear=ptr;
	}
	else{
		head->rear->next=ptr;
		head->rear=ptr;
	}
}
bool DeQueue(ListQueue *&head,ElemType &data){
	Node *ptr;
	if(head->rear==NULL){
		return false;
	}
	ptr=head->front;
	data = ptr->data;
	if(head->front==head->rear){
		head->front=head->rear=NULL;
	}
	else{
		head->front=head->front->next;
	}
	free(ptr);
	return true;
}
bool isEmpty(ListQueue *&head){
	return head->front==head->rear;
}
int lenth(ListQueue *&head){
	Node *ptr=head->front;
	int i=0;
	if(ptr==NULL){
		return 0;
	}
	while(ptr){
		i++;
		ptr=ptr->next;
	}
	return i;
}

void showQueue(ListQueue *&head){
	
	Node *ptr = head->front;
	while(ptr){
		cout<<ptr->data<<"  ";
		ptr = ptr->next;
	}
}
void destroy(ListQueue *&head)  //��������
{
    Node *ptr=head->front->next;   //pָ���ͷ���ݽڵ�
    while(ptr){
    	free(head->front);
    	head->front=ptr;
    	ptr=ptr->next;
	}
	free(head->front);
}
int main(){
	ListQueue *head;
	
	InitQueue(head);
	cout<<"��ʼ���������..."<<endl;
	
	for(int i = 0;i<9;i++){
		EnQueue(head,i);
	}
	cout<<"������..."<<endl;
	cout<<"�����е�Ԫ��Ϊ��";
	showQueue(head);
	cout<<"\n���еĳ��ȣ�"<<lenth(head)<<endl;
	cout<<"�Ƿ�Ϊ�գ�"<<isEmpty(head)<<endl;
	
	for(int i = 0;i<4;i++){
		ElemType data;
		DeQueue(head,data);
		cout<<"�ѳ���һ��Ԫ��:"<<data<<endl;
	}
	
	cout<<"���еĳ��ȣ�"<<lenth(head)<<endl;
	
	cout<<"�����е�Ԫ��Ϊ��";
	showQueue(head);
	cout<<"\n���еĳ��ȣ�"<<lenth(head)<<endl;
	
	destroy(head);
	cout<<"\n�����ٶ���."<<endl;
	cout<<"�Ƿ�Ϊ�գ�"<<isEmpty(head)<<endl;
	
	return 0;
}
