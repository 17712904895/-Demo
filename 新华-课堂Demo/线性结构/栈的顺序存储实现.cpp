//堆栈
#include<iostream>
using namespace std;

typedef int ElementType;
#define MaxSize 100
typedef struct sNode *Stack;

typedef struct sNode{
	ElementType data[MaxSize];
	int top;
}sNode;
//初始化
Stack InitStack(){
	Stack s=new sNode;
	s->top=-1;
	return s;
}
//判满
bool isFull(Stack s){
	if(s->top==MaxSize-1){
		return true;
	}
	return false;
}
//入栈
void Push(Stack s,ElementType item){
	if(isFull(s)){
		return; 
	}else{
		s->data[++s->top]=item;
		return;
	}
}
//判空
bool IsEmpty(Stack s){
	if(s->top==-1){
		return true;
	}else{
		return false;
	}
}
//出栈 
ElementType Pop(Stack s){
	if(IsEmpty(s)){
		return 0;
	} else{
		return (s->data[s->top--]);
	}
}

int main(){
	Stack s;
	s=InitStack();
	//入栈 
	
	Push(s,5);
	Push(s,6);
	Push(s,7);
	Push(s,8);
	cout<<Pop(s)<<" "<<Pop(s)<<" "<<Pop(s)<<" "<<Pop(s);
	
	
	while(true){
		int x;
		cin>>x;
		if(x!=0){
			Push(s,x);
		}else{
			break;
		}
	}
	while(!IsEmpty(s)) {
		cout<<Pop(s)<<" ";
	}
	
	return 0;
}
