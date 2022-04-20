#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE 200
//长度
//复制
//拼接
//比较
//求子串
//删除 

//长度
int getLength(char *s){
	int i=0;
	while(s[i]!='\0'){
		i++;
	}
	return i;
}

//复制
char* copyChar(char *s){
	static char x[MAXSIZE];
	//如果在使用返回值为char的情况下 ，无法返回正确的值： 
	//当包含自动变量的函数或代码块退出时，它们所占用的内存便被回收，它们的内容肯定会被下一个所调用的函数覆盖
	//因此需要使用静态函数只有拥有指向该数组的指针的函数（通过参数传递给它）才能修改这个静态数组 
	int len=getLength(s);
	for(int i=0;i<len;i++){
		x[i]=s[i];
	}
	return x;
} 
//拼接
void Strcat(char *s,char *a,char *b){
	int i=0;
	while(a[i]!='\0'){
		s[i]=a[i];
		i++;
	}
	int j=0;
	while(b[j]!='\0'){
		s[i++]=b[j++];//先赋值，后运算； 
	}
}
//比较
int Strcmp(char *x,char *y){
	int i=0;
	while(x[i]==y[i]&&x[i]!='\0'){
		i++;
	}
	return (x[i]-y[i]);
}
//求子串 
void substr(char *s,char *ss,int i,int len){
	int ii=i;
	int l=getLength(s);
	if(i<1||i>l||len<0||len>l-i+1)
	return;
	for(int j=0;j<len;j++){
		ss[j]=s[ii-1];
		ii++;
	}
} 
//删除 
char* delstr(char *s,int i,int len){
	int l=getLength(s);
	int k=0;
	static char ss[MAXSIZE];
	for(int j=0;j<l;j++){
		if(j>=i-1&&j<i+len-1)continue;
		ss[k]=s[j];
		k++;
	} 
	return ss;
}

int main(){
	//长度
	char a[MAXSIZE];
	cout<<"enter a:";
	cin>>a;
	cout<<"the length of a:";
	cout<<getLength(a)<<endl;
	//复制
	char x[MAXSIZE];
	cout<<"enter x:";
	cin>>x;
	cout<<"y is a copy of x:";
	char *y=copyChar(x);
	cout<<y<<endl;
	//拼接
	char b[MAXSIZE];
	cout<<"b is the connection between x and y:";
	Strcat(b,x,y); 
	cout<<b<<endl;
	//比较 
	char c[MAXSIZE],d[MAXSIZE];
	cout<<"enter c and d:";
	cin>>c>>d;
	cout<<Strcmp(c,d)<<endl; 
	//求子串
	int i,len1;
	char e[MAXSIZE];
	cout<<"enter the straring index and the length of the substring:";
	cin>>i>>len1;
	substr(a,e,i,len1); 
	cout<<e<<endl;
	//删除
	int f,len2;
	char g[MAXSIZE];
	cout<<"enter char g:";
	cin>>g;
	cout<<"enter the straring index and the length of the substring:";
	cin>>f>>len2;
	cout<<delstr(g,f,len2)<<endl;
	
	return 0;
}
