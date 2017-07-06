#include<iostream>
#include<cstdlib>
typedef int ElemType;
using namespace std;
typedef struct LinkList{
	ElemType data;
	struct LinkList *next;
}LinkList;
void initList(LinkList *&head){   //��ʼ������ 
	head = new LinkList;
	head->next=NULL;
}

LinkList *createList(LinkList *&head){	  //β�巨 
	LinkList *temp=head,*ptr=head->next;
	int n;
	cout<<"������Ҫ��������Ԫ�أ�";
	cin>>n;
	for(int i=0;i<n;i++){
		ptr=new LinkList;
		cin>>ptr->data;
		temp->next=ptr;
		temp=ptr;
	}
	temp->next=NULL;
	return head;
}
void appendList(LinkList *&head,int data){     //��β��׷�� 
	LinkList *ptr=head->next,*temp;
	temp = new LinkList;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	ptr->next=temp;
	temp->data=data;
	temp->next=NULL;
}
void showList(LinkList *&head){     //������� 
	LinkList *ptr=head->next;
	while(ptr){
		cout<<ptr->data<<"  ";
		ptr=ptr->next;
	}
	cout<<endl;
}
bool isEmpty(LinkList *&head){      //�ж��Ƿ�Ϊ�� 
	return (head->next==NULL);
}
bool inseartList(LinkList *&head,int data){     //�������в������� 
	LinkList *ptr=head->next,*Node;
	int n;
	cout<<endl<<"������Ҫ����λ��������룺";
	cin>>n; 
	while(ptr){
		if(n==ptr->data){
			Node=new LinkList;
			Node->data=data;
			Node->next=ptr->next;
			ptr->next=Node;
			cout<<"�����������"<<endl;
			return true;
		}		
		ptr=ptr->next;
	}
	cout<<"���޴���"<<endl;
	return false;	 
} 
bool deleteList(LinkList *&head,int data){    //ɾ�������е����� 
	LinkList *ptr=head->next,*temp=head;
	while(ptr){
		if(data=ptr->data){
			temp->next=ptr->next;
			cout<<"ɾ���ɹ�"<<endl;
			free(ptr);
			return true;
		}
		temp=ptr;
		ptr=ptr->next;
	}
	cout<<"���޴���"<<endl;
	return false;
} 
bool updateList(LinkList *&head,int key,int value){    //���������е����� 
	LinkList *temp=head,*ptr=head->next;
	while(ptr){
		if(key==ptr->data){
			ptr->data=value;
			cout<<"�޸����"<<endl;
			return true;
		}
		temp=ptr;
		ptr=ptr->next;
	}
	cout<<"�޸�ʧ��,�����п���û�������޸ĵ���..."<<endl;
	return false; 
}
int getLocation(LinkList *&head,int data){     //�õ������������е�λ�� 
	LinkList *ptr=head->next,*temp=head;
	int i=0;
	while(ptr){
		i++;
		if(data==ptr->data){
			return i;
		}
		temp=ptr;
		ptr=ptr->next;
	}
	cout<<"���޴���"<<endl;
	return 0;
}

void reverseList(LinkList *&head){
	LinkList *pre=head,*ptr=NULL,*cur=pre->next;
	while(ptr!=NULL){
		ptr=cur->next;
		cur->next=pre;
		pre=cur;
		cur=ptr;
	}
	head->next=NULL;
	head=pre;
}
void destroyList(LinkList *&head){   //�������� 
	LinkList *ptr=head->next;
	while(ptr){
		free(head);
		head=ptr;
		ptr=ptr->next;
	}
	free(head);
} 
int main(){
	LinkList *head;
	initList(head);
	cout<<"��ʼ����ɣ�"<<endl;
	head=createList(head);
	cout<<"�����������"<<endl;
	
	cout<<endl<<"�Ƿ�Ϊ�գ�"<<isEmpty(head)<<endl;
	
	cout<<endl<<"�������";
	showList(head);
	
	cout<<endl<<"��Ҫ�������в�������..."<<endl; 
	inseartList(head,7);	 
	cout<<"�������";
	showList(head);
	cout<<endl<<"�Ƿ�Ϊ�գ�"<<isEmpty(head)<<endl;
	
	cout<<endl<<"Ҫ���ҵ����������е�λ��Ϊ��"<<getLocation(head,8)<<endl;
	
	cout<<endl<<"��Ҫɾ�������е�����..."<<endl; 
	deleteList(head,1);
	cout<<"�������";
	showList(head);
	
	cout<<endl<<"Ҫ���ҵ����������е�λ��Ϊ��"<<getLocation(head,2)<<endl; 
	
	
	cout<<"�޸�����...";
	updateList(head,2,99);
	cout<<"�������";
	showList(head);
	
	cout<<endl<<"׷������...";
	appendList(head,0);
	cout<<"�������";
	showList(head);
	
	cout<<endl<<"�������ã�";
	reverseList(head);
	showList(head);
	 
	destroyList(head);	
	cout<<endl<<"�����������"<<endl;
	cout<<endl<<"�Ƿ�Ϊ�գ�"<<isEmpty(head)<<endl;
	
	return 0;
}

/*
void Link(LinkList *&L1, LinkList *&L2)
{
    LinkList *p= L1;
    while(p->next != NULL)   //�ҵ�L1��β�ڵ�
        p = p->next;
    p->next = L2->next;  //��L2���׸����ݽڵ����ӵ�L1��β�ڵ��
    free(L2);   //�ͷŵ��Ѿ����õ�L2��ͷ�ڵ�
}
*/
 


 








 








