#ifndef NODE_H
#define NODE_H
#endif // !NODE_H
#include<fstream>
#include<sstream>
#include<string>
#include <utility> 
using namespace std;

class node
{
public:
	node();
	node(int key, pair<int, int>pos, bool type,string name);
	~node();
	int key;
	string name;
	pair<int, int> pos;
	pair<int, int>size;//w,h
	bool type;//is_terminal
	bool move_type;//is_FIXED
	int nearY();
	
	
	void print();
};
bool greaterX(node *a, node* b) ;
