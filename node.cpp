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

int node::nearX()
{
	int j = (this->pos.first - 10) % 12;
	if (j >= 6) { return pos.first + 12 - j };
	else { return pos.first - j; }
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