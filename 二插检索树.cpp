#include<iostream>
using namespace std;
#define MIN -1000
#define SUCC 1
#define NOTFOUND 0
#define ZERO 0

typedef struct Bnode
{
	int data;
	Bnode *Lson, *Rson;
}Bnode, *Bptr;
void insert(int x, Bptr &p)
{
	  if (p == NULL)       //遇到空树
     {  p = new  Bnode;   //申请新结点
	    p->data = x;   //置新结点的值域
	    p->Lson = p->Rson = NULL;  //新结点作叶子
	        return;    //插入完毕，返回
	} //否则，尚未找到插入点，继续查找
	if (x <= p->data) insert(x, p->Lson);  //递归的向左找插入点
    else insert(x, p->Rson);   //递归的向右找插入点


}//添加值为x的结点
Bptr creat()
{
	Bptr  root;   int x;
	     root = NULL;  	//开始时树为空
	     cin >> x;  	//开始读入元素序列
	      while (x != ZERO) 	//ZERO是输入结束标记
	{
		       insert(x, root); 		 	//插入x
				cin >> x;		//读入下一个元素
	}
	     return  root;  //构造完毕，返回根结点指针


}//构造二叉检索树

Bptr search(int x, Bptr p)
{
	if (p == NULL) return  NULL;   //遇到空树
	   if (x == p->data) return p; //找到值等于x的结点,返回该结点的指针
	   if (x<p->data)
		return search(x, p->Lson); //递归查找左子树
	   else  return  search(x, p->Rson);  //递归查找右子树




}//查找值为x的结点，返回该结点的指针
int deleteT(int x, Bptr root)
{
	Bptr f, p, q, s, r;
	p = NULL;   //p将指向要删除结点
	f = root;    // f的初值指向虚根
	q = root->Rson;  //q搜索指针
	while (q != NULL)  //循环查找x
		if (x == q->data) { p = q;  q = NULL; } //找到x
		else//没找到x后，继续搜索
			if (x<q->data) { f = q; q = q->Lson; }  //向左搜索
			else { f = q; q = q->Rson; }    //向右搜索
			if (p == NULL) return  NOTFOUND; //没找到x

											 // 以下是找到x（p指向x）后的具体删除操作步骤
			   if (p->Rson == NULL)  // p无右儿子，用左儿子代替p
				    if (p == f->Lson) { f->Lson = p->Lson; delete p; }
			   else { f->Rson = p->Lson; delete p; }
			else  if (p->Lson == NULL)  //p无左儿子，用右儿子代替p
			       if (p == f->Lson) { f->Lson = p->Rson; delete p; }
		      else { f->Rson = p->Rson; delete p; }
			else  //以下是p有两个儿子情况的处理
				  //p有两个儿子
				 {  s = p->Lson;   //s是p的左儿子
			       if (s->Rson == NULL) //s没有右儿子，用s代替p
				        { p->data = s->data; //用s的值域代换p的值域
			           p->Lson = s->Lson;  //删去s
			          delete  s;     }
			else  //以下是s有右儿子的情况
				  //s有右儿子，找p的左儿子的最右子孙r
					     {  r = s->Rson;
				           while (r->Rson != NULL) { s = r; r = r->Rson; }
				           p->data = r->data;  //用r的值域代换p的值域
				          s->Rson = r->Lson; //删去r
				           delete r;
				   }
			}
			  return  SUCC; //返回删除成功信息


	
}//删除值为x的结点	
void inorder(Bptr p)
{
	if (p == NULL) return;
	inorder(p->Lson);
	cout << p->data;
	inorder(p->Rson);



}//中序遍历二叉检索树
								/*******************完成函数*****************************************/










								/**********************************************************************/
int main()
{
	cout << "******创建二叉检索树（带附加根结点）******" << endl;
	Bptr root = new  Bnode;		//创建附加根结点（虚根），root指向虚根
	root->data = MIN;				//附加根结点的值为无穷小值
	Bptr q = creat();				//创建二叉检索树，返回根结点指针q
	root->Rson = q;				//虚根右指针指向二叉检索树的根结点
	root->Lson = NULL;			//虚根左指针为空指针
	int n = 1, i = 1;
	cout << "1.添加2.查找3.删除4.中序遍历 其他：退出" << endl;
	while (i) {
		cout << "请输入操作：";
		cin >> n;
		int x;
		Bptr p;
		switch (n) {
		case 1:				//添加
			cout << "请输入要添加的数：";
			cin >> x;
			insert(x, root);
			cout << "添加成功" << endl;
			break;
		case 2:				//查找
			cout << "请输入要查找的值：";
			cin >> x;
			p = search(x, root);
			if (p == NULL) cout << "你查的值在二叉检索树中不存在!" << endl;
			else cout << "你查的值在二叉检索树中存在!" << endl;
			break;
		case 3:				//删除
			cout << "请输入要删除的值：";
			cin >> x;
			if (deleteT(x, root) == 1)
				cout << "删除成功" << endl;
			else
				cout << "删除失败" << endl;
			break;
		case 4:
			inorder(root);
			cout << "遍历完成" << endl;
			break;
		default:i = 0;
		}
	}
	return 0;
}
