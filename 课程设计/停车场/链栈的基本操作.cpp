#include <iostream>
#include <conio.h>
using namespace std;


typedef int ElemType;	//����Ԫ�ص�����ΪElemType����ElemType����Ϊint����

typedef struct LSNode
{
    ElemType  data;
	struct   LSNode  *next;
}LSNode, *LinkStack;


/*��ʼ��һ����ջS*/
LinkStack InitLinkStack( )
{
	LinkStack  top;
	top=(LSNode *)malloc(sizeof(LSNode));
	top->next=NULL; 
	return top;
}




//�ж�ջS�Ƿ�Ϊ��
/*ջSΪ��ջʱ����ֵΪ1�� ��֮Ϊ0*/
int isempty (LinkStack top)
{
   if(top->next == NULL) return 1;
   else return 0;
} 



//����ջS�ĳ���
 int ListLength(LinkStack top) 
{   
      LinkStack p;
      p=top->next;	
      int j=1;
      while( p!=NULL )
      {	
          p=p->next; 
          j ++; 
      }
      return j-1;
}

//ȡ��ջS��ջ��Ԫ�ص�ֵ��
int gettop (LinkStack top,ElemType *e)
 {
   if(top->next == NULL) return 0; 	/*ջSΪ��ջ,ȡֵʧ�ܣ�����0*/
   *e=top->next->data;			
	return 1;		 /*ȡֵ�ɹ�������1*/
}



/*---------------��ջ����--------------------*/
/*Ҫ�󣺽�ֵΪe������Ԫ�ز��뵽ջS�У�ʹ֮��Ϊ�µ�ջ��Ԫ��
�㷨˼·���Ƚ�top��1��Ȼ����ջԪ��e����top��ָ��λ���ϡ�*/

/*-------------�������¿հ�������ɽ�ջ������Դ����--------------*/

int Push(LinkStack top , ElemType  e)
{	LinkStack  s;
	s=(LSNode *)malloc(sizeof(LSNode));
	if (s==NULL)  return  0; 
/*  �����½��ʧ�ܣ����ش����־ */
s->data=e; 
s->next=top->next;
top->next=s;
return 1;
}




/*---------------�������Ͽհ�������ɽ�ջ������Դ����---------------*/








/*--------------------------��ջ����---------------------------*/ 
/*�㷨˼·����ȡ��ջ��Ԫ�ص�ֵ���ٽ��α�top��1��*/


/*-------------�������¿հ�������ɳ�ջ������Դ����-----------------*/

int Pop(LinkStack top , ElemType  *e)
{	LinkStack  p;
	if(top->next==NULL)	return 0;
/*  ջ��ɾ��ʧ�ܣ����ش����־ */
p=top->next;
*e=p->data;	/*  ȡջ��Ԫ��  */
top->next=p->next;
free(p);
return 1;	}


/*---------------�������Ͽհ�������ɳ�ջ������Դ����------------------*/







/*���ջ���� 
Ҫ���������ջ����ջ�׵�Ԫ��ֵ*/

void ListTra(LinkStack top )
{
LinkStack p;
p=top->next;
while(p!=NULL)
{	
	cout<<p->data<<',';
	p=p->next;
}
	cout<<endl;
}


int main()
{
	char option;
	ElemType e;
	int k,i;

	LinkStack top;	//�������ָ��

	cout<<endl;
	cout<<"**********��һ��ʹ�����ȳ�ʼ����ջ**********"<<endl;
	cout<<"**********���˵�**********"<<endl;
	cout<<" 1.��ʼ����ջ"<<endl;
	cout<<" 2.��ջ"<<endl;
	cout<<" 3.��ջ"<<endl;
	cout<<" 4.���ջ"<<endl;
	cout<<" 5.�ж�ջ�Ƿ�Ϊ��"<<endl;
	cout<<" 6.���ջ�ĳ���"<<endl;
	cout<<" 7.���ջ��Ԫ�ص�ֵ"<<endl;
	cout<<" 8.�˳�"<<endl;
	cout<<"********************"<<endl;
	while (1)
	{
		cout<<"---------------------------------------- "<<endl;

		cout<<" ѡ����Ҫ�Ĳ��� (1 - 8): ";
		
		option = getche();	//��ȡ�û�����Ĳ�������
		cout<<endl;

		switch (option)
		{
		case '1':
			top=InitLinkStack( );
			break;
		case '2':
			cout <<"����Ҫ��ջ��Ԫ�ص�ֵ:"<<endl;
			cin>>e;
			i=Push(top,e);
			if(i==1)
			{
			cout <<"��ջ�ɹ�!"<<endl;
			}
			else
			{
			cout<<"��ջʧ��!"<<endl;
			}
			break;
		case '3':

			i=Pop(top,&e);
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
			ListTra(top);
			cout<<endl;
			break;

		case '5':
			i=isempty(top);
			if (i == 0)
			{
			cout <<"ջ�ǿ�"<<endl;
			}
			else
			{
			cout <<"ջΪ��"<<endl;
			}
			break;
		case '6':
			k=ListLength(top);
			cout <<"ջ�ĳ���Ϊ��"<<k<<endl;
			break;
		case '7':
			gettop (top,&e);
			cout <<"ջ��Ԫ�ص�ֵΪ��"<<e<<endl;
			break;
		case '8':
			cout<<endl;
			return 0;
		}
	}

}