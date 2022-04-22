//��������������(ʹ�ö�ջ�Ĳ���)

//����
//����
#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
	char data;
	struct Node *left,*right;
}BiTreeNode,*BiTree;

//���򴴽������� 
//AB#CD##E##F#GH###
void CreateBiTree(BiTree &t){
	//����������������� 
	char ch;
	cin>>ch;
	if(ch=='#')t=NULL;
	else{
		//ֻ�н�����ʼ�������ܲ������ݵ�Ŷ 
		t=new BiTreeNode;
		t->data=ch;
		CreateBiTree(t->left);
		CreateBiTree(t->right);
	} 
} 
//�������������
void PreOrderTreaversal(BiTree t){
	if(t){
		cout<<t->data<<" ";
		PreOrderTreaversal(t->left);
		PreOrderTreaversal(t->right);
	}
} 
//�������������
void InOrderTreaversal(BiTree t){
	if(t){
		PreOrderTreaversal(t->left);
		cout<<t->data<<" ";
		PreOrderTreaversal(t->right);
	}
} 
//�������������
void PostOrderTreaversal(BiTree t){
	if(t){
		PreOrderTreaversal(t->left);
		PreOrderTreaversal(t->right);
		cout<<t->data<<" ";
	}
}  
 
int main(){
	BiTree root;
	CreateBiTree(root);
	cout<<"���������";
	PreOrderTreaversal(root);
	cout<<endl;
	cout<<"���������";
	InOrderTreaversal(root); 
	cout<<endl;
	cout<<"���������";
	PostOrderTreaversal(root);
	cout<<endl;
	return 0;
}
