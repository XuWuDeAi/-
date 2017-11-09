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
	  if (p == NULL)       //��������
     {  p = new  Bnode;   //�����½��
	    p->data = x;   //���½���ֵ��
	    p->Lson = p->Rson = NULL;  //�½����Ҷ��
	        return;    //������ϣ�����
	} //������δ�ҵ�����㣬��������
	if (x <= p->data) insert(x, p->Lson);  //�ݹ�������Ҳ����
    else insert(x, p->Rson);   //�ݹ�������Ҳ����


}//���ֵΪx�Ľ��
Bptr creat()
{
	Bptr  root;   int x;
	     root = NULL;  	//��ʼʱ��Ϊ��
	     cin >> x;  	//��ʼ����Ԫ������
	      while (x != ZERO) 	//ZERO������������
	{
		       insert(x, root); 		 	//����x
				cin >> x;		//������һ��Ԫ��
	}
	     return  root;  //������ϣ����ظ����ָ��


}//������������

Bptr search(int x, Bptr p)
{
	if (p == NULL) return  NULL;   //��������
	   if (x == p->data) return p; //�ҵ�ֵ����x�Ľ��,���ظý���ָ��
	   if (x<p->data)
		return search(x, p->Lson); //�ݹ����������
	   else  return  search(x, p->Rson);  //�ݹ����������




}//����ֵΪx�Ľ�㣬���ظý���ָ��
int deleteT(int x, Bptr root)
{
	Bptr f, p, q, s, r;
	p = NULL;   //p��ָ��Ҫɾ�����
	f = root;    // f�ĳ�ֵָ�����
	q = root->Rson;  //q����ָ��
	while (q != NULL)  //ѭ������x
		if (x == q->data) { p = q;  q = NULL; } //�ҵ�x
		else//û�ҵ�x�󣬼�������
			if (x<q->data) { f = q; q = q->Lson; }  //��������
			else { f = q; q = q->Rson; }    //��������
			if (p == NULL) return  NOTFOUND; //û�ҵ�x

											 // �������ҵ�x��pָ��x����ľ���ɾ����������
			   if (p->Rson == NULL)  // p���Ҷ��ӣ�������Ӵ���p
				    if (p == f->Lson) { f->Lson = p->Lson; delete p; }
			   else { f->Rson = p->Lson; delete p; }
			else  if (p->Lson == NULL)  //p������ӣ����Ҷ��Ӵ���p
			       if (p == f->Lson) { f->Lson = p->Rson; delete p; }
		      else { f->Rson = p->Rson; delete p; }
			else  //������p��������������Ĵ���
				  //p����������
				 {  s = p->Lson;   //s��p�������
			       if (s->Rson == NULL) //sû���Ҷ��ӣ���s����p
				        { p->data = s->data; //��s��ֵ�����p��ֵ��
			           p->Lson = s->Lson;  //ɾȥs
			          delete  s;     }
			else  //������s���Ҷ��ӵ����
				  //s���Ҷ��ӣ���p������ӵ���������r
					     {  r = s->Rson;
				           while (r->Rson != NULL) { s = r; r = r->Rson; }
				           p->data = r->data;  //��r��ֵ�����p��ֵ��
				          s->Rson = r->Lson; //ɾȥr
				           delete r;
				   }
			}
			  return  SUCC; //����ɾ���ɹ���Ϣ


	
}//ɾ��ֵΪx�Ľ��	
void inorder(Bptr p)
{
	if (p == NULL) return;
	inorder(p->Lson);
	cout << p->data;
	inorder(p->Rson);



}//����������������
								/*******************��ɺ���*****************************************/










								/**********************************************************************/
int main()
{
	cout << "******��������������������Ӹ���㣩******" << endl;
	Bptr root = new  Bnode;		//�������Ӹ���㣨�������rootָ�����
	root->data = MIN;				//���Ӹ�����ֵΪ����Сֵ
	Bptr q = creat();				//������������������ظ����ָ��q
	root->Rson = q;				//�����ָ��ָ�����������ĸ����
	root->Lson = NULL;			//�����ָ��Ϊ��ָ��
	int n = 1, i = 1;
	cout << "1.���2.����3.ɾ��4.������� �������˳�" << endl;
	while (i) {
		cout << "�����������";
		cin >> n;
		int x;
		Bptr p;
		switch (n) {
		case 1:				//���
			cout << "������Ҫ��ӵ�����";
			cin >> x;
			insert(x, root);
			cout << "��ӳɹ�" << endl;
			break;
		case 2:				//����
			cout << "������Ҫ���ҵ�ֵ��";
			cin >> x;
			p = search(x, root);
			if (p == NULL) cout << "����ֵ�ڶ���������в�����!" << endl;
			else cout << "����ֵ�ڶ���������д���!" << endl;
			break;
		case 3:				//ɾ��
			cout << "������Ҫɾ����ֵ��";
			cin >> x;
			if (deleteT(x, root) == 1)
				cout << "ɾ���ɹ�" << endl;
			else
				cout << "ɾ��ʧ��" << endl;
			break;
		case 4:
			inorder(root);
			cout << "�������" << endl;
			break;
		default:i = 0;
		}
	}
	return 0;
}
