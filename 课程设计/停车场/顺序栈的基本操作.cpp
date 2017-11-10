#include <iostream>
#include <conio.h>
using namespace std;

#define MAXSIZE 50	//顺序栈存储空间分配量
typedef int ElemType;	//数据元素的类型为ElemType，将ElemType定义为int类型

/*顺序栈的类型定义*/
typedef struct
{
ElemType  elem[MAXSIZE];	/*为栈开辟的足够大的数组空间 */
int top;	/*用来存放栈顶元素的下标*/
}SeqStack;


/*初始化一个空栈S*/ 
void  InitStack(SeqStack *S)
{
  S->top= -1;
}


//判断栈S是否为空
/*栈S为空栈时返回值为1， 反之为0*/
int isempty (SeqStack *S)
{
   if(S->top == -1) return 1;
   else return 0;
} 

//判断栈S是否满
/*栈满时返回值为1， 反之为0*/
int isfull (SeqStack *S)
{
if ( S->top == MAXSIZE-1 )
    return 1;
else  
    return 0;
} 


//返回栈S的长度
int getlen (SeqStack *S)
{
	return S->top+1;
}

//取出栈S的栈顶元素的值，用e带回。
int gettop (SeqStack *S,ElemType *e)
 {
   if(S->top==-1) return 0; 	/*栈S为空栈,取值失败，返回0*/
   *e=S->elem[S->top];			/*将栈顶元素的值存入指针e所指向的内存单元*/
	return 1;		 /*取值成功，返回1*/
}



/*---------------进栈操作--------------------*/
/*要求：将值为e的数据元素插入到栈S中，使之称为新的栈顶元素
算法思路：先将top增1，然后将入栈元素e存入top所指的位置上。*/

/*-------------请在以下空白区域完成进栈操作的源代码--------------*/

int Push(SeqStack *S, ElemType e)
{
if(S->top== MAXSIZE-1)  return 0;	/*栈已满*/
S->top++;	/*栈顶位置上移*/
S->elem[S->top]=e;
return 1;
}


/*---------------请在以上空白区域完成进栈操作的源代码---------------*/








/*--------------------------出栈操作---------------------------*/ 
/*算法思路：先取出栈顶元素的值，再将游标top减1。*/


/*-------------请在以下空白区域完成出栈操作的源代码-----------------*/

int Pop(SeqStack * S, ElemType *e)
{  /* 将栈S的栈顶元素取出， 放到e所指的存储空间中 */
   if(S->top==-1)   /*栈为空*/
	return 0;
else
   {*e= S->elem[S->top];
       S->top--;	/* 修改栈顶指针 */
	return 1;	}
}

/*---------------请在以上空白区域完成出栈操作的源代码------------------*/







/*输出栈操作 
要求：依次输出栈顶到栈底的元素值*/

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

	SeqStack S;	//创建顺序栈，名称为S

	cout<<endl;
	cout<<"**********第一次使用请先初始化顺序栈**********"<<endl;
	cout<<"**********主菜单**********"<<endl;
	cout<<" 1.初始化顺序栈"<<endl;
	cout<<" 2.进栈"<<endl;
	cout<<" 3.出栈"<<endl;
	cout<<" 4.输出栈"<<endl;
	cout<<" 5.判断栈是否存满"<<endl;
	cout<<" 6.判断栈是否为空"<<endl;
	cout<<" 7.输出栈的长度"<<endl;
	cout<<" 8.输出栈顶元素的值"<<endl;
	cout<<" 9.退出"<<endl;
	cout<<"********************"<<endl;
	while (1)
	{
		cout<<"---------------------------------------- "<<endl;

		cout<<" 选择你要的操作 (1 - 9): ";
		
		option = getche();	//获取用户输入的操作符号
		cout<<endl;

		switch (option)
		{
		case '1':
			InitStack(&S);
			break;
		case '2':
			cout <<"输入要进栈的元素的值:"<<endl;
			cin>>e;
			i=Push(&S,e);
			if(i==1)
			{
			cout <<"进栈成功!"<<endl;
			}
			else
			{
			cout<<"进栈失败，栈已满!"<<endl;
			}
			break;
		case '3':

			i=Pop(&S,&e);
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
			Liststack (&S);
			cout<<endl;
			break;

		case '5':
			i=isfull(&S);
			if (i == 0)
			{
			cout <<"栈还未存满"<<endl;
			}
			else
			{
			cout <<"栈已存满"<<endl;
			}
			break;
		case '6':
			i=isempty(&S);
			if (i == 0)
			{
			cout <<"栈非空"<<endl;
			}
			else
			{
			cout <<"栈为空"<<endl;
			}
			break;
		case '7':
			k=getlen (&S);
			cout <<"栈的长度为："<<k<<endl;
			break;
		case '8':
			gettop (&S,&e);
			cout <<"栈顶元素的值为："<<e<<endl;
			break;
		case '9':
			cout<<endl;
			return 0;
		}
	}

}