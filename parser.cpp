#include "parser.h"

#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include<iostream>
using namespace std;
parser::parser(string filename)
{
	this->filename = filename;
	readNode();
	readRow();
}
void parser::readNode() 
{
	ifstream file;
	
	file.open(filename + ".nodes",ios::in);
	int tmp; string s,st;
	int numn,numt;
	if (!file) { cout << "fail"; }
	while (!file.eof())
	{
		file >> s;
		if (s == "NumNodes") { file >> s; file >> numn; }
		if (s == "NumTerminals") { file >> s; file >> numt; break; }
	}
	for(int i=0;i<numn;i++)
	{
		getline(file,s);
		stringstream ss(s);
		int j = 0;
		string nn;
		int x, y;
		bool isT=false;
		while (getline(ss, st, ' ')) {
			if (j == 0) { nn = st; }
			if (j == 1) { stringstream(st) >> x; }
			if (j == 2) { stringstream(st) >> y; }
			if (j == 3) { isT = true; }
			j++;
		}
		node *tp;
		tp = new node(
			i, pair<int, int>(x, y), isT, nn
		);
		n.push_back(tp);

	}
	
	file.close();
	ifstream filepl;
	filepl.open(filename + ".pl");
	getline(file, s);
	for (int i = 0; i < numn; i++) {
		getline(file, s);
		stringstream ss(s);
		int j = 0;
		string nn;
		int w, h;
		bool isF;
		while (getline(ss, st, ' ')) {
			//if (j == 0) { nn = st; }
			if (j == 1) { stringstream(st) >> w; }
			if (j == 2) { stringstream(st) >> h; }
			if (j == 6) { isF = true; }
			j++;
		}
		n[i]->size = pair<int, int>(w, h);
		n[i]->move_type = isF;
	}
	filepl.close();
}
void parser::readRow() {//nothing;
}