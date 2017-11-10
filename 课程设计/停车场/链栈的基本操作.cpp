#include <iostream>
#include <conio.h>
using namespace std;


typedef int ElemType;	//数据元素的类型为ElemType，将ElemType定义为int类型

typedef struct LSNode
{
    ElemType  data;
	struct   LSNode  *next;
}LSNode, *LinkStack;


/*初始化一个空栈S*/
LinkStack InitLinkStack( )
{
	LinkStack  top;
	top=(LSNode *)malloc(sizeof(LSNode));
	top->next=NULL; 
	return top;
}




//判断栈S是否为空
/*栈S为空栈时返回值为1， 反之为0*/
int isempty (LinkStack top)
{
   if(top->next == NULL) return 1;
   else return 0;
} 



//返回栈S的长度
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

//取出栈S的栈顶元素的值。
int gettop (LinkStack top,ElemType *e)
 {
   if(top->next == NULL) return 0; 	/*栈S为空栈,取值失败，返回0*/
   *e=top->next->data;			
	return 1;		 /*取值成功，返回1*/
}



/*---------------进栈操作--------------------*/
/*要求：将值为e的数据元素插入到栈S中，使之称为新的栈顶元素
算法思路：先将top增1，然后将入栈元素e存入top所指的位置上。*/

/*-------------请在以下空白区域完成进栈操作的源代码--------------*/

int Push(LinkStack top , ElemType  e)
{	LinkStack  s;
	s=(LSNode *)malloc(sizeof(LSNode));
	if (s==NULL)  return  0; 
/*  申请新结点失败，返回错误标志 */
s->data=e; 
s->next=top->next;
top->next=s;
return 1;
}




/*---------------请在以上空白区域完成进栈操作的源代码---------------*/








/*--------------------------出栈操作---------------------------*/ 
/*算法思路：先取出栈顶元素的值，再将游标top减1。*/


/*-------------请在以下空白区域完成出栈操作的源代码-----------------*/

int Pop(LinkStack top , ElemType  *e)
{	LinkStack  p;
	if(top->next==NULL)	return 0;
/*  栈空删除失败，返回错误标志 */
p=top->next;
*e=p->data;	/*  取栈顶元素  */
top->next=p->next;
free(p);
return 1;	}


/*---------------请在以上空白区域完成出栈操作的源代码------------------*/







/*输出栈操作 
要求：依次输出栈顶到栈底的元素值*/

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

	LinkStack top;	//创建结点指针

	cout<<endl;
	cout<<"**********第一次使用请先初始化链栈**********"<<endl;
	cout<<"**********主菜单**********"<<endl;
	cout<<" 1.初始化链栈"<<endl;
	cout<<" 2.进栈"<<endl;
	cout<<" 3.出栈"<<endl;
	cout<<" 4.输出栈"<<endl;
	cout<<" 5.判断栈是否为空"<<endl;
	cout<<" 6.输出栈的长度"<<endl;
	cout<<" 7.输出栈顶元素的值"<<endl;
	cout<<" 8.退出"<<endl;
	cout<<"********************"<<endl;
	while (1)
	{
		cout<<"---------------------------------------- "<<endl;

		cout<<" 选择你要的操作 (1 - 8): ";
		
		option = getche();	//获取用户输入的操作符号
		cout<<endl;

		switch (option)
		{
		case '1':
			top=InitLinkStack( );
			break;
		case '2':
			cout <<"输入要进栈的元素的值:"<<endl;
			cin>>e;
			i=Push(top,e);
			if(i==1)
			{
			cout <<"进栈成功!"<<endl;
			}
			else
			{
			cout<<"进栈失败!"<<endl;
			}
			break;
		case '3':

			i=Pop(top,&e);
			if (i == 0)
			{
			cout <<"栈为空，出栈失败。"<<endl;
			}
			else
			{
			cout <<"出栈成功，"<<e<<"已出栈!"<<endl;
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
			cout <<"栈非空"<<endl;
			}
			else
			{
			cout <<"栈为空"<<endl;
			}
			break;
		case '6':
			k=ListLength(top);
			cout <<"栈的长度为："<<k<<endl;
			break;
		case '7':
			gettop (top,&e);
			cout <<"栈顶元素的值为："<<e<<endl;
			break;
		case '8':
			cout<<endl;
			return 0;
		}
	}

}