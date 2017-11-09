#include <iostream>
#include <malloc.h>
using namespace std;


typedef int ElemType;	//����Ԫ�ص�����ΪElemType����ElemType����Ϊint����

typedef struct QNode	/*�������*/
{	ElemType  data;
	struct QNode  *next;  
}LinkQueueNode, *LinkQList;

typedef struct			/*���������ͣ���¼��ͷָ��Ͷ�βָ��*/
{	   
  	LinkQueueNode  *last; 
	LinkQueueNode  *first;/*��βָ��*/                    
}LinkQueue;

/*��ʼ��һ����������q*/
int initQueue(LinkQueue *q)
{ 
	q->first=q->last=new LinkQueueNode; /*����ͷ���ռ�*/
    if (q->last!=NULL)
    { 
		q->last->next=q->last; /*ͷ��βָ���ָ��ͷ���*/
        return 1;
    }
	else   
		return 0;
}   
void VIP (LinkQueue &q,int c){
	LinkQueueNode *s=new LinkQueueNode;
	s->next=q.first->next;
	s->data=c;
  
	q.first->next=s;
	
	

}


/*---------------���Ӳ���--------------------*/
/*Ҫ�󣺽�ֵΪx������Ԫ�ز��뵽��q�У�ʹ֮��Ϊ�µĶ�βԪ��
�㷨˼·��β�巨*/

/*-------------�������¿հ�������ɽ��Ӳ�����Դ����--------------*/

int Enterqueue(LinkQueue *q, ElemType x,int &count)
{
	LinkQueueNode *s;
 	s = new LinkQueueNode;	/*�����½��ռ�*/
	if (s==NULL)
	{
		return 0;
	}
	else
  	{
		s->data=x;
		s->next=q->last->next;/*�½���Ա��ֵ*/
     	q->last->next=s; 
    	q->last=s; /*��β�巨��ʽ������*/
    	// count++;
     	return 1; 
	}
} 

/*--------------------------���Ӳ���---------------------------*/ 
/*�㷨˼·����ɾ����һ����㣬ע�������ֻ��һ��Ԫ�ص����*/


/*-------------�������¿հ�������ɳ��Ӳ�����Դ����-----------------*/

int deletequeue (LinkQueue* q, ElemType * x,int &count)
{ 	
	LinkQueueNode *p;
    if (q->last->next==q->last) 	/*�ն���*/
    	return 0;	   
    p=q->last->next->next;  	/*�ҵ�Ҫɾ����Ԫ��*/ 
	q->last->next->next=p->next;  	/*��������q�Ķ�ͷԪ��*/
	
    if (p == q->last)    
		q->last->next=q->last; /*��Ҫɾ����Ϊ��βԪ��,���޸�βָ��last*/

   	// count--; 
	*x=p->data;	/*���ر�ɾ��Ԫ�ص�ֵ*/
	delete p; 	/*ɾ����Ԫ��*/
	return 1;
}

/*---------------�������Ͽհ�������ɳ��Ӳ�����Դ����------------------*

/*������в��� 
Ҫ������������׵���β��Ԫ��ֵ*/

void ListTra(LinkQueue* q,int count)
{
	if (q->last->next==q->last)
	{
		cout<<"��ǰ������û��Ԫ��!"<<endl;
		return;
	}
	LinkQueueNode *p;
	p=q->last->next->next;		/*pָ���һ������Ԫ��*/
	cout<<"\n�����е�Ԫ������Ϊ��";
	while(p!=q->last->next)
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
	int i,count=0;

	LinkQueue q;	//qΪLinkQueue���͵Ľṹ�������first��ԱΪ��¼����ָ�룬last��ԱΪ��βָ��

	cout<<endl;
	cout<<"**********�ŶӾͲͶ���**********"<<endl;
	cout<<"**********���˵�**********"<<endl;
	cout<<" 1.��ʼ��������"<<endl;
	cout<<" 2.������"<<endl;
	cout<<" 3.�߿���"<<endl;
	cout<<" 4.�鿴�Ŷ�"<<endl;
	cout<<" 5.���ŵ���"<<endl;
	cout<<"6.VIP"<<endl;
	cout<<"********************"<<endl;
	while (1)
	{
		cout<<"---------------------------------------- "<<endl;

		cout<<" ѡ����Ҫ�Ĳ��� (1 - 5): ";
		
		//option = getche();	//��ȡ�û�����Ĳ�������
		cin>>option;
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
			i=Enterqueue(&q,e,count);
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

			i=deletequeue(&q,&e,count);
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
			ListTra(&q,count);
			cout<<endl;
			break;
		case '5':
			cout<<endl;
			return 0;
		case '6':
			cout<<"����vip����";int c;
			cin>>c;
			VIP(q,c);
			break;
		}
	}

}