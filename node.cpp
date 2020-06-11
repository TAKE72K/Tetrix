#include"node.h"
#include<string>
#include<iostream>
using namespace std;
node::node(int k, pair<int, int>p, bool t, string n) {
	key = k;
	pos = p;
	type = t;
	name = n;
}

int node::nearY()
{
	int j = (this->pos.second - 10) % 12;
	if (j >= 6) { return pos.second + 12 - j; }
	else { return pos.second - j; }
}

void node::print()
{
	cout << name<<":\n";
	cout << "size: " << size.first << " * " << size.second << '\n';
	cout << "pos: " << pos.first << " , " << pos.second << '\n';
	cout << "is it fixed: " << move_type << " is it terminal: " << type << '\n';
}

bool greaterX(node *a,node *b)
{
	return(a->pos.first < b->pos.first);
}
string node::out() {
	string output;
	return output;
}