#ifndef ROW_H
#define ROW_H

#endif // !ROW_H

#include "node.h"
#include <vector>
class row
{
public:
	row() {};
	~row();
	int cordinate;
	int height;
	int subOrigin;
	int numsite;
	std::vector<node*> pl;
};

