#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE 200
//����
//����
//ƴ��
//�Ƚ�
//���Ӵ�
//ɾ�� 

//����
int getLength(char *s){
	int i=0;
	while(s[i]!='\0'){
		i++;
	}
	return i;
}

//����
char* copyChar(char *s){
	static char x[MAXSIZE];
	//�����ʹ�÷���ֵΪchar������� ���޷�������ȷ��ֵ�� 
	//�������Զ������ĺ����������˳�ʱ��������ռ�õ��ڴ�㱻���գ����ǵ����ݿ϶��ᱻ��һ�������õĺ�������
	//�����Ҫʹ�þ�̬����ֻ��ӵ��ָ��������ָ��ĺ�����ͨ���������ݸ����������޸������̬���� 
	int len=getLength(s);
	for(int i=0;i<len;i++){
		x[i]=s[i];
	}
	return x;
} 
//ƴ��
void Strcat(char *s,char *a,char *b){
	int i=0;
	while(a[i]!='\0'){
		s[i]=a[i];
		i++;
	}
	int j=0;
	while(b[j]!='\0'){
		s[i++]=b[j++];//�ȸ�ֵ�������㣻 
	}
}
//�Ƚ�
int Strcmp(char *x,char *y){
	int i=0;
	while(x[i]==y[i]&&x[i]!='\0'){
		i++;
	}
	return (x[i]-y[i]);
}
//���Ӵ� 
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
//ɾ�� 
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
	//����
	char a[MAXSIZE];
	cout<<"enter a:";
	cin>>a;
	cout<<"the length of a:";
	cout<<getLength(a)<<endl;
	//����
	char x[MAXSIZE];
	cout<<"enter x:";
	cin>>x;
	cout<<"y is a copy of x:";
	char *y=copyChar(x);
	cout<<y<<endl;
	//ƴ��
	char b[MAXSIZE];
	cout<<"b is the connection between x and y:";
	Strcat(b,x,y); 
	cout<<b<<endl;
	//�Ƚ� 
	char c[MAXSIZE],d[MAXSIZE];
	cout<<"enter c and d:";
	cin>>c>>d;
	cout<<Strcmp(c,d)<<endl; 
	//���Ӵ�
	int i,len1;
	char e[MAXSIZE];
	cout<<"enter the straring index and the length of the substring:";
	cin>>i>>len1;
	substr(a,e,i,len1); 
	cout<<e<<endl;
	//ɾ��
	int f,len2;
	char g[MAXSIZE];
	cout<<"enter char g:";
	cin>>g;
	cout<<"enter the straring index and the length of the substring:";
	cin>>f>>len2;
	cout<<delstr(g,f,len2)<<endl;
	
	return 0;
}
