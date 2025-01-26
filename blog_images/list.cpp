#include <iostream>
using std::cout;
using std::endl;
class node
{
	private:
		int data;
		node *next;
	public:
		node():data(0),next(nullptr){};//成员初始化列表智能在构造函数中使用
		node(int val):data(val),next(nullptr){};
		void set_next(node *ne) {next = ne;};
		void set_data(int val) {data = val;};
		node * get_next() {return next;}
		int get_data() {return data;}
};

class list
{
	private:
		node *root;
		node *tail;
	public:
		list():root(new node),tail(root){}
		~list();
		void add(int val);
		bool isempty()	{return (root->get_next() == nullptr);}
		void print() const;
		int get_head()	{return root->get_next()->get_data();}
		int get_tail()	{return tail->get_data();}
		void reverse();
};

int main()
{
	list temp;
	//cout<<temp.isempty();
	temp.add(9);
	temp.add(10);
	temp.add(19);
	temp.add(5);
	temp.add(1);
	temp.add(8);
	temp.add(6);
	temp.print();
	temp.reverse();
	temp.print();
	cout<<temp.get_head()<<endl;
	cout<<temp.get_tail()<<endl;
	return 0;
}
void list::add(int val)
{
	node * temp = new node(val);
	temp->set_next(nullptr);
	tail->set_next(temp);
	tail = temp;
}
void list::print() const
{
	node *temp = root->get_next();
	while((bool)(temp != nullptr))
	{
		cout<<temp->get_data()<<" ";
		temp = temp->get_next();
	}
	cout<<endl;
}
list::~list()
{
	while(root != nullptr)
	{
		node *temp = root->get_next();
		delete root;
		root = temp;
	}
}
void list::reverse()
{
	node *temp1 = root->get_next();
	tail = temp1;
	node *temp = temp1->get_next();
	temp1->set_next(nullptr);
	while(temp != nullptr)
	{
		node *temp2 = temp->get_next();
		temp->set_next(temp1);
		temp1 = temp;
		temp = temp2;
	}
	root->set_next(temp1);

}
