//二叉树基本操作(使用堆栈的操作)

//输入
//遍历
#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
	char data;
	struct Node *left,*right;
}BiTreeNode,*BiTree;

//先序创建二叉树 
//AB#CD##E##F#GH###
void CreateBiTree(BiTree &t){
	//按照先序输入二叉树 
	char ch;
	cin>>ch;
	if(ch=='#')t=NULL;
	else{
		//只有将结点初始化，才能插入数据的哦 
		t=new BiTreeNode;
		t->data=ch;
		CreateBiTree(t->left);
		CreateBiTree(t->right);
	} 
} 
//二叉树先序遍历
void PreOrderTreaversal(BiTree t){
	if(t){
		cout<<t->data<<" ";
		PreOrderTreaversal(t->left);
		PreOrderTreaversal(t->right);
	}
} 
//二叉树中序遍历
void InOrderTreaversal(BiTree t){
	if(t){
		PreOrderTreaversal(t->left);
		cout<<t->data<<" ";
		PreOrderTreaversal(t->right);
	}
} 
//二叉树后序遍历
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
	cout<<"先序遍历：";
	PreOrderTreaversal(root);
	cout<<endl;
	cout<<"中序遍历：";
	InOrderTreaversal(root); 
	cout<<endl;
	cout<<"后序遍历：";
	PostOrderTreaversal(root);
	cout<<endl;
	return 0;
}
