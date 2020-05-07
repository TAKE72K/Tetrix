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