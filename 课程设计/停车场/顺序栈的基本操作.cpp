#include <iostream>
#include <conio.h>
using namespace std;

#define MAXSIZE 50	//˳��ջ�洢�ռ������
typedef int ElemType;	//����Ԫ�ص�����ΪElemType����ElemType����Ϊint����

/*˳��ջ�����Ͷ���*/
typedef struct
{
ElemType  elem[MAXSIZE];	/*Ϊջ���ٵ��㹻�������ռ� */
int top;	/*�������ջ��Ԫ�ص��±�*/
}SeqStack;


/*��ʼ��һ����ջS*/ 
void  InitStack(SeqStack *S)
{
  S->top= -1;
}


//�ж�ջS�Ƿ�Ϊ��
/*ջSΪ��ջʱ����ֵΪ1�� ��֮Ϊ0*/
int isempty (SeqStack *S)
{
   if(S->top == -1) return 1;
   else return 0;
} 

//�ж�ջS�Ƿ���
/*ջ��ʱ����ֵΪ1�� ��֮Ϊ0*/
int isfull (SeqStack *S)
{
if ( S->top == MAXSIZE-1 )
    return 1;
else  
    return 0;
} 


//����ջS�ĳ���
int getlen (SeqStack *S)
{
	return S->top+1;
}

//ȡ��ջS��ջ��Ԫ�ص�ֵ����e���ء�
int gettop (SeqStack *S,ElemType *e)
 {
   if(S->top==-1) return 0; 	/*ջSΪ��ջ,ȡֵʧ�ܣ�����0*/
   *e=S->elem[S->top];			/*��ջ��Ԫ�ص�ֵ����ָ��e��ָ����ڴ浥Ԫ*/
	return 1;		 /*ȡֵ�ɹ�������1*/
}



/*---------------��ջ����--------------------*/
/*Ҫ�󣺽�ֵΪe������Ԫ�ز��뵽ջS�У�ʹ֮��Ϊ�µ�ջ��Ԫ��
�㷨˼·���Ƚ�top��1��Ȼ����ջԪ��e����top��ָ��λ���ϡ�*/

/*-------------�������¿հ�������ɽ�ջ������Դ����--------------*/

int Push(SeqStack *S, ElemType e)
{
if(S->top== MAXSIZE-1)  return 0;	/*ջ����*/
S->top++;	/*ջ��λ������*/
S->elem[S->top]=e;
return 1;
}


/*---------------�������Ͽհ�������ɽ�ջ������Դ����---------------*/








/*--------------------------��ջ����---------------------------*/ 
/*�㷨˼·����ȡ��ջ��Ԫ�ص�ֵ���ٽ��α�top��1��*/


/*-------------�������¿հ�������ɳ�ջ������Դ����-----------------*/

int Pop(SeqStack * S, ElemType *e)
{  /* ��ջS��ջ��Ԫ��ȡ���� �ŵ�e��ָ�Ĵ洢�ռ��� */
   if(S->top==-1)   /*ջΪ��*/
	return 0;
else
   {*e= S->elem[S->top];
       S->top--;	/* �޸�ջ��ָ�� */
	return 1;	}
}

/*---------------�������Ͽհ�������ɳ�ջ������Դ����------------------*/







/*���ջ���� 
Ҫ���������ջ����ջ�׵�Ԫ��ֵ*/

void Liststack (SeqStack *S)
{ int i;
for(i=S->top;i>=0;i--)
cout<<S->elem[i]<<",";
} 



int main()
{
	char option;
	ElemType e;
	int k,i;

	SeqStack S;	//����˳��ջ������ΪS

	cout<<endl;
	cout<<"**********��һ��ʹ�����ȳ�ʼ��˳��ջ**********"<<endl;
	cout<<"**********���˵�**********"<<endl;
	cout<<" 1.��ʼ��˳��ջ"<<endl;
	cout<<" 2.��ջ"<<endl;
	cout<<" 3.��ջ"<<endl;
	cout<<" 4.���ջ"<<endl;
	cout<<" 5.�ж�ջ�Ƿ����"<<endl;
	cout<<" 6.�ж�ջ�Ƿ�Ϊ��"<<endl;
	cout<<" 7.���ջ�ĳ���"<<endl;
	cout<<" 8.���ջ��Ԫ�ص�ֵ"<<endl;
	cout<<" 9.�˳�"<<endl;
	cout<<"********************"<<endl;
	while (1)
	{
		cout<<"---------------------------------------- "<<endl;

		cout<<" ѡ����Ҫ�Ĳ��� (1 - 9): ";
		
		option = getche();	//��ȡ�û�����Ĳ�������
		cout<<endl;

		switch (option)
		{
		case '1':
			InitStack(&S);
			break;
		case '2':
			cout <<"����Ҫ��ջ��Ԫ�ص�ֵ:"<<endl;
			cin>>e;
			i=Push(&S,e);
			if(i==1)
			{
			cout <<"��ջ�ɹ�!"<<endl;
			}
			else
			{
			cout<<"��ջʧ�ܣ�ջ����!"<<endl;
			}
			break;
		case '3':

			i=Pop(&S,&e);
			if (i == 0)
			{
			cout <<"ջΪ�գ���ջʧ�ܡ�"<<endl;
			}
			else
			{
			cout <<"��ջ�ɹ���"<<e<<"�ѳ�ջ!"<<endl;
			}
			break;
		case '4':
			Liststack (&S);
			cout<<endl;
			break;

		case '5':
			i=isfull(&S);
			if (i == 0)
			{
			cout <<"ջ��δ����"<<endl;
			}
			else
			{
			cout <<"ջ�Ѵ���"<<endl;
			}
			break;
		case '6':
			i=isempty(&S);
			if (i == 0)
			{
			cout <<"ջ�ǿ�"<<endl;
			}
			else
			{
			cout <<"ջΪ��"<<endl;
			}
			break;
		case '7':
			k=getlen (&S);
			cout <<"ջ�ĳ���Ϊ��"<<k<<endl;
			break;
		case '8':
			gettop (&S,&e);
			cout <<"ջ��Ԫ�ص�ֵΪ��"<<e<<endl;
			break;
		case '9':
			cout<<endl;
			return 0;
		}
	}

}