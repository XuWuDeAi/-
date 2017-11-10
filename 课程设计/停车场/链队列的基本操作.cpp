#include <iostream>
#include <conio.h>
#include <malloc.h>
using namespace std;


typedef int ElemType;	//数据元素的类型为ElemType，将ElemType定义为int类型

typedef struct QNode	/*结点类型*/
{	ElemType  data;
	struct QNode  *next;  
}LinkQueueNode, *LinkQList;

typedef struct			/*链队列类型，记录队头指针和队尾指针*/
{	LinkQueueNode  *first;   /*队头指针*/
  	LinkQueueNode  *last;    /*队尾指针*/                    
}LinkQueue;

/*初始化一个空链队列q*/
int initQueue(LinkQueue *q)
  { q->first=new LinkQueueNode;
            /*申请头结点空间*/
     if (q->first!=NULL)
       {q->last= q->first; q->first->next=NULL;
         /*头、尾指针均指向头结点*/
         return 1;
         }
      else   return 0;
     }   


/*---------------进队操作--------------------*/
/*要求：将值为x的数据元素插入到队q中，使之称为新的队尾元素
算法思路：尾插法*/

/*-------------请在以下空白区域完成进队操作的源代码--------------*/

int Enterqueue(LinkQueue *q, ElemType x)
{ LinkQueueNode *s;
 s =new LinkQueueNode;	/*申请新结点空间*/
 if (s!=NULL)
  {	s->data=x;
	s->next=NULL;/*新结点成员赋值*/
     	q->last->next= s; 
    	 q->last=s;/*以尾插法方式插入结点*/
     	return 1; 
	}	
 return 0;
}                  




/*---------------请在以上空白区域完成进队操作的源代码---------------*/








/*--------------------------出队操作---------------------------*/ 
/*算法思路：即删除第一个结点，注意队列中只有一个元素的情况*/


/*-------------请在以下空白区域完成出队操作的源代码-----------------*/

int deletequeue  (LinkQueue* q, ElemType * x)
{ LinkQueueNode * p;
   if (q->first==q->last)/*空队列*/
         return 0;
   p=q->first->next; /*找到要删除的元素*/ 
   q->first->next=p->next; /*重新链接q的队头元素*/ 
   if  (p->next == NULL)    q->last=q->first;
/*若要删除的为队尾元素,即删除后队列为空,则修改尾指针last*/
   	*x=p->data;	/*带回被删除元素的值*/
	 free(p); /*删除该元素*/
   	return 1;
  }                  



/*---------------请在以上空白区域完成出队操作的源代码------------------*/



/*输出队列操作 
要求：依次输出队首到队尾的元素值*/

void ListTra(LinkQueue* q)
{
	if (q->first==q->last)
	{
	cout<<"当前队列中没有元素!"<<endl;
	return;
	}

	LinkQueueNode * p;
	p=q->first->next;		/*p指向第一个数据元素*/
	cout<<"\n链队列的元素依次为：";
	while(p!=NULL)
	{	
	cout<<p->data<<',';
	p=p->next;
	}
	cout<<"\n链队列的元素输出完毕!"<<endl;
}


int main()
{
	char option;
	ElemType e;
	int i;

	LinkQueue q;	//q为LinkQueue类型的结构体变量，first成员为记录队首指针，last成员为队尾指针

	cout<<endl;
	cout<<"**********第一次使用请先初始化链队列**********"<<endl;
	cout<<"**********主菜单**********"<<endl;
	cout<<" 1.初始化链队列"<<endl;
	cout<<" 2.进队"<<endl;
	cout<<" 3.出队"<<endl;
	cout<<" 4.输出队"<<endl;
	cout<<" 5.退出"<<endl;
	cout<<"********************"<<endl;
	while (1)
	{
		cout<<"---------------------------------------- "<<endl;

		cout<<" 选择你要的操作 (1 - 5): ";
		
		option = getche();	//获取用户输入的操作符号
		cout<<endl;

		switch (option)
		{
		case '1':
			i=initQueue(&q);
			if(i==1)
			{
			cout <<"初始化成功!"<<endl;
			}
			else
			{
			cout<<"初始化失败!"<<endl;
			}
			break;
		case '2':
			cout <<"输入要进队的元素的值:"<<endl;
			cin>>e;
			i=Enterqueue(&q,e);
			if(i==1)
			{
			cout <<"进队成功!"<<endl;
			}
			else
			{
			cout<<"进队失败!"<<endl;
			}
			break;
		case '3':

			i=deletequeue(&q,&e);
			if (i == 0)
			{
			cout <<"队为空，出队失败。"<<endl;
			}
			else
			{
			cout <<"出队成功，"<<e<<"已出队!"<<endl;
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