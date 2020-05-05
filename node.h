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
	~node();

private:
	pair<int, int> pos;
	pair<int, int>size;//w,h
	bool type;//is_terminal
	bool move_type;//is_FIXED
};

node::node()
{
}

node::~node()
{
}