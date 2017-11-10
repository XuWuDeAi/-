#include <iostream>
#include <conio.h>
#include <malloc.h>
using namespace std;


typedef int ElemType;	//����Ԫ�ص�����ΪElemType����ElemType����Ϊint����

typedef struct QNode	/*�������*/
{	ElemType  data;
	struct QNode  *next;  
}LinkQueueNode, *LinkQList;

typedef struct			/*���������ͣ���¼��ͷָ��Ͷ�βָ��*/
{	LinkQueueNode  *first;   /*��ͷָ��*/
  	LinkQueueNode  *last;    /*��βָ��*/                    
}LinkQueue;

/*��ʼ��һ����������q*/
int initQueue(LinkQueue *q)
  { q->first=new LinkQueueNode;
            /*����ͷ���ռ�*/
     if (q->first!=NULL)
       {q->last= q->first; q->first->next=NULL;
         /*ͷ��βָ���ָ��ͷ���*/
         return 1;
         }
      else   return 0;
     }   


/*---------------���Ӳ���--------------------*/
/*Ҫ�󣺽�ֵΪx������Ԫ�ز��뵽��q�У�ʹ֮��Ϊ�µĶ�βԪ��
�㷨˼·��β�巨*/

/*-------------�������¿հ�������ɽ��Ӳ�����Դ����--------------*/

int Enterqueue(LinkQueue *q, ElemType x)
{ LinkQueueNode *s;
 s =new LinkQueueNode;	/*�����½��ռ�*/
 if (s!=NULL)
  {	s->data=x;
	s->next=NULL;/*�½���Ա��ֵ*/
     	q->last->next= s; 
    	 q->last=s;/*��β�巨��ʽ������*/
     	return 1; 
	}	
 return 0;
}                  




/*---------------�������Ͽհ�������ɽ��Ӳ�����Դ����---------------*/








/*--------------------------���Ӳ���---------------------------*/ 
/*�㷨˼·����ɾ����һ����㣬ע�������ֻ��һ��Ԫ�ص����*/


/*-------------�������¿հ�������ɳ��Ӳ�����Դ����-----------------*/

int deletequeue  (LinkQueue* q, ElemType * x)
{ LinkQueueNode * p;
   if (q->first==q->last)/*�ն���*/
         return 0;
   p=q->first->next; /*�ҵ�Ҫɾ����Ԫ��*/ 
   q->first->next=p->next; /*��������q�Ķ�ͷԪ��*/ 
   if  (p->next == NULL)    q->last=q->first;
/*��Ҫɾ����Ϊ��βԪ��,��ɾ�������Ϊ��,���޸�βָ��last*/
   	*x=p->data;	/*���ر�ɾ��Ԫ�ص�ֵ*/
	 free(p); /*ɾ����Ԫ��*/
   	return 1;
  }                  



/*---------------�������Ͽհ�������ɳ��Ӳ�����Դ����------------------*/



/*������в��� 
Ҫ������������׵���β��Ԫ��ֵ*/

void ListTra(LinkQueue* q)
{
	if (q->first==q->last)
	{
	cout<<"��ǰ������û��Ԫ��!"<<endl;
	return;
	}

	LinkQueueNode * p;
	p=q->first->next;		/*pָ���һ������Ԫ��*/
	cout<<"\n�����е�Ԫ������Ϊ��";
	while(p!=NULL)
	{	
	cout<<p->data<<',';
	p=p->next;
	}
	cout<<"\n�����е�Ԫ��������!"<<endl;
}


int main()
{
	char option;
	ElemType e;
	int i;

	LinkQueue q;	//qΪLinkQueue���͵Ľṹ�������first��ԱΪ��¼����ָ�룬last��ԱΪ��βָ��

	cout<<endl;
	cout<<"**********��һ��ʹ�����ȳ�ʼ��������**********"<<endl;
	cout<<"**********���˵�**********"<<endl;
	cout<<" 1.��ʼ��������"<<endl;
	cout<<" 2.����"<<endl;
	cout<<" 3.����"<<endl;
	cout<<" 4.�����"<<endl;
	cout<<" 5.�˳�"<<endl;
	cout<<"********************"<<endl;
	while (1)
	{
		cout<<"---------------------------------------- "<<endl;

		cout<<" ѡ����Ҫ�Ĳ��� (1 - 5): ";
		
		option = getche();	//��ȡ�û�����Ĳ�������
		cout<<endl;

		switch (option)
		{
		case '1':
			i=initQueue(&q);
			if(i==1)
			{
			cout <<"��ʼ���ɹ�!"<<endl;
			}
			else
			{
			cout<<"��ʼ��ʧ��!"<<endl;
			}
			break;
		case '2':
			cout <<"����Ҫ���ӵ�Ԫ�ص�ֵ:"<<endl;
			cin>>e;
			i=Enterqueue(&q,e);
			if(i==1)
			{
			cout <<"���ӳɹ�!"<<endl;
			}
			else
			{
			cout<<"����ʧ��!"<<endl;
			}
			break;
		case '3':

			i=deletequeue(&q,&e);
			if (i == 0)
			{
			cout <<"��Ϊ�գ�����ʧ�ܡ�"<<endl;
			}
			else
			{
			cout <<"���ӳɹ���"<<e<<"�ѳ���!"<<endl;
			}
			break;
		case '4':
			ListTra(&q);
			cout<<endl;
			break;
		case '5':
			cout<<endl;
			return 0;
		}
	}

}