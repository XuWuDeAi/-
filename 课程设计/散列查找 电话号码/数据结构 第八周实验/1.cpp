// Note:Your choice is C++ IDE
#include <iostream>
using namespace std;
#include<iostream>
using namespace std;
#define m 14

void ClearHashList(int *b)		//��ʼ��ɢ�б���ʼ��������Ԫ��ֵΪ0
{
for(int i=0; i<m; i++)
b[i]=0;
}


void Insert(int *b,int k)			//����k��ɢ�б��ɢ��λ��
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



int Search(int *b,int k) 		//����k��ɢ�б��λ��

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
    cout<<"����Ҫ���ҵ�ֵ��"<<endl;
    cin>>k;
   p= Search(a,k);
   if(p==-1)
   cout<<"û�ҵ�";
   else cout<<"Ҫ���ҵ�ֵ��"<<p<<"λ��";
    return 0;
}