#ifndef PARSER_H
#define PARSER_H
#endif

#include<string>
#include<map>
#include<vector>

#include "row.h"
//#include "node.h"

using namespace std;

class parser
{
public:
	parser() {};
	parser(string filename);
	~parser() {};
	map<int, row*> r;
	vector<node*>n ;
	void readNode();
	void readRow();
	void legal();
	void writePL();
private:
	string filename;
};



