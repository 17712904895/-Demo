#include<iostream>
using namespace std;
#define MAXSIZE 100
typedef char elemtype;

typedef struct BiTNode
{
	char data;
    struct BiTNode *lchild,*rchild; 
}BiTreeNode,*BiTree;

void CreateBiTree(BiTree &T)
{
	/*
	BiTree p[MAXSIZE],s;
	int i,j;
	cout<<"请输入编号(0退出二叉树建立):";
	cin>>i;
	while(i!=0)
	{
		s=new BiTreeNode;
		cout<<"请输入数据（char):";
		cin>>s->data;
		s->lchild=s->rchild=NULL;
		p[i]=s;
		if(i==1)
			root=s;
		else
		{
			j=i/2;
			if(i%2==0)
				p[j]->lchild=s;
			else
				p[j]->rchild=s;
		}
		cout<<"请输入编号:";
		cin>>i;
	}
	*/
	char ch;
    cin>>ch;
    if(ch=='#') T=NULL;
    else{
        T=new BiTreeNode;
        T->data=ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }

}
void LevelPrint(BiTree root)  //层次输出
{
	BiTree Q[MAXSIZE],p;
	int front,rear;
	front=rear=0;
	Q[rear]=root;
	rear=(rear+1)%MAXSIZE;
	while(rear!=front)
	{
		p=Q[front];
		front=(front+1)%MAXSIZE;
		cout<<p->data <<" ";
		if(p->lchild!=NULL)
		{
			Q[rear]=p->lchild;
			rear=(rear+1)%MAXSIZE;
		}
		if(p->rchild!=NULL)
		{
			Q[rear]=p->rchild;
			rear=(rear+1)%MAXSIZE;
		}
	}
}
void TreePrint(BiTree root,int level)
{
	if(!root)
	{
		return ;
	}
	TreePrint(root->rchild,level+1);
	for(int i=0;i<level;i++)
		cout<<"  ";
	cout<<root->data<<endl;
    TreePrint(root->lchild,level+1);
}


BiTree Print(char str[]){
	BiTree bt;
	char ch;
	static int i=0;
	ch=str[i];
	if(ch=='#')
	bt=NULL;
	else{
		bt=new BiTreeNode;
		bt->data=ch;
		bt->lchild=Print(str);
		bt->rchild=Print(str);
	} 
	return bt;
} 


//二叉树递归先序
void PreOrderTraversal(BiTree tn){
	if(tn){
		cout<<tn->data<<" ";
		PreOrderTraversal(tn->lchild);
		PreOrderTraversal(tn->rchild);
	}
} 
//二叉树递归中序
void InOrderTraversal(BiTree tn) {
	if(tn){
		PreOrderTraversal(tn->lchild);
		cout<<tn->data;
		PreOrderTraversal(tn->rchild);
	}	
}
//二叉树递归后序 
void PostOrderTraversal(BiTree tn) {
	if(tn){
		PreOrderTraversal(tn->lchild);
		PreOrderTraversal(tn->rchild);
		cout<<tn->data;
	}	
}
 //二叉树中序非遍历 
 void InOrder(BiTree tn){
 	BiTree s[100],p=tn; 
 	int top=-1;
 	if(p==NULL)return;
 	do{
 		while(p!=NULL){
 			s[++top]=p;
 			p->lchild=p;
 		}
 		if(top=-1)return;
 		//直到没有左结点，出队列 
 		else{
 		p=s[top--];
		cout<<p->data<<" ";	
		p=p->rchild;
 		}
 	}while(p!=NULL||top!=-1);
 }
 
//二叉树先序非遍历 
void PreOrder(BiTree p){
 	BiTree s[100];
 	
 	int top=-1;
 	if(p==NULL)return;
 	do{
 		while(p!=NULL){
 			s[++top]=p;
			cout<<p->data<<" ";	
 			p->lchild=p;
 		}
 		if(top=-1)return;
 		else{
 		p=s[top--];
		p=p->rchild;
 		}
 	}while(p!=NULL||top!=-1);
 }
 //二叉树后序非遍历 
void PostOrder(BiTree tn){
 	BiTreeNode *s[100],*p=tn;
 	int top=-1;
 	if(p==NULL)return;
 	do{
 		while(p!=NULL){
 			//入队列 
 			s[++top]=p;
			cout<<p->data<<" ";	
			p=s[top--];
 			p->lchild=p;
 		}
 		if(top=-1)return;
 		else{
		p=p->rchild;
 		}
 	}while(p!=NULL||top!=-1);
 }
 
int main(){
	BiTree root;
	CreateBiTree(root);
/*	LevelPrint(root);
	cout<<"树形结构输出\n";
	TreePrint(root,1);
	
*/	
/*	*/	//二叉树中序非遍历 
	InOrder(root);
	cout<<endl;
	//二叉树先序非遍历 
	PreOrder(root);
	cout<<endl;
	//二叉树后序非遍历 
	PostOrder(root);
	cout<<endl;

	
/*
	//二叉树递归先序
	PreOrderTraversal(root); 
	cout<<endl;
	//二叉树递归中序
	InOrderTraversal(root); 
	cout<<endl;
	//二叉树递归后序
	PostOrderTraversal(root); 
	cout<<endl;
		
	*/

	return 0;
}



















