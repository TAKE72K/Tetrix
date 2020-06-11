#ifndef ROW_H
#define ROW_H

#endif // !ROW_H

#include "node.h"
#include <vector>
class row
{
public:
	row() {};
	row(int c, int h, int s, int n) :cordinate(c), height(h), subOrigin(s), numsite(n) {};
	~row();
	int cordinate;
	int height;
	int subOrigin;
	int numsite;
	std::vector<node*> pl;
	int empty_x = 0;
};

