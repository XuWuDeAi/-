// Note:Your choice is C++ IDE
#include <iostream>
using namespace std;
#include<iostream>
using namespace std;
#define m 14

void ClearHashList(int *b)		//初始化散列表，初始所有数组元素值为0
{
for(int i=0; i<m; i++)
b[i]=0;
}


void Insert(int *b,int k)			//插入k到散列表的散列位置
{
int j;
j=k%13;
int i=1,d=1;
while (b[j]!=0)
{
j=k%13;
j=(j+d)%m;
d++;
}
b[j]=k;
}



int Search(int *b,int k) 		//查找k在散列表的位置

{
int j,d=1;
j=k%13;
while (b[j]!=0)
 {
	if (b[j]==k) return j;
	else { j=k%13;j=(j+d)%m;d++;}
 }
 return -1;
}


int main()
{
    int a[m],k,i,p;
    ClearHashList(a);
    for(i=1;i<=10;i++)
    {
    	cin>>k;
    	Insert(a,k);
    }
    for(i=0;i<m;i++)
    {
    	cout<<a[i]<<"  ";

    }
      cout<<endl;
    cout<<"输入要查找的值："<<endl;
    cin>>k;
   p= Search(a,k);
   if(p==-1)
   cout<<"没找到";
   else cout<<"要查找的值在"<<p<<"位置";
    return 0;
}