#include "parser.h"

#include <fstream>
#include <sstream>
#include <string>
#include <utility>
#include<iostream>
#include<iomanip>
#include<algorithm>//sort
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
	getline(file, s); getline(file, s);
	for(int i=0;i<numn;i++)
	{
		getline(file,s);
		stringstream ss(s);
		int j = 0;
		string nn;
		int x, y;
		string t;
		
		ss >> nn >> x >> y >> t;
		bool isT = (t.size()) ? true : false;
		node *tp;
		tp = new node(
			i, pair<int, int>(x, y), isT, nn
		);
		tp->size = pair<int, int>(x, y);
		n.push_back(tp);
		//if (i == 0) { n[0]->print(); }
	}
	
	file.close();
	ifstream filepl;
	filepl.open(filename + ".pl", ios::in);
	if (!filepl)cout << "fail";
	getline(filepl, s);
	for (int i = 0; i < numn; i++) {
		getline(filepl, s);
		stringstream ss(s);
		int j = 0;
		string nn;
		int x, y;
		bool isF=false;
		//cout << s << endl; system("pause");
		while (getline(ss>>ws, st,' ')) {
			//if (j == 0) { nn = st; }
			//cout << st << endl; system("pause");
			if (j == 1) { stringstream(st) >> x; }
			if (j == 2) { stringstream(st) >> y; }
			if (j == 6) { isF = true; }
			j++;
		}
		n[i]->pos = pair<int, int>(x, y);
		n[i]->move_type = isF;
	}
	filepl.close();
}
void parser::readRow() {
	ifstream file;

	file.open(filename + ".scl", ios::in);
	int nrows;
	string s,tmp;
	while (!file.eof()) {
		//cout << s << '\n';
		getline(file, s);
		if (s == "CoreRow Horizontal") {
			int c, h, su, n;
			getline(file, s);
			stringstream coor(s);
			coor >> tmp >> tmp >> c;
			getline(file, s);
			stringstream heig(s);
			heig >> tmp >> tmp >> h;
			getline(file, s); getline(file, s); getline(file, s); getline(file, s);
			getline(file, s);
			stringstream subo(s);
			subo >> tmp >> tmp >> su >> tmp >> tmp >> n;
			getline(file, s);

			row *tp = new row(c, h, su, n);
			r[c] = tp;
			//cout << "ins" << c << '\n'; system("pause");
			


		}
	}
}

void parser::legal()
{
	for(int i=0;i<n.size();i++)
	{
		r[n[i]->nearY()]->pl.push_back(n[i]);
	}
	map<int, row*>::iterator iter;
	for (iter = r.begin(); iter != r.end(); iter++)
	{
		sort(iter->second->pl.begin(), iter->second->pl.end(), greaterX);//sort with x pos
		for (int j = 0; j < iter->second->pl.size(); j++) 
		{
			pair<int, int> npos = iter->second->pl[j]->pos;
			pair<int, int> nsize = iter->second->pl[j]->size;
			if (iter->second->pl[j]->move_type==false&&iter->second->pl[j]->type==false) {
				if (npos.first >= iter->second->empty_x)//empty ok to place 
				{
					iter->second->pl[j]->pos =make_pair(iter->second->empty_x, iter->first);
					iter->second->empty_x += nsize.first;
				}
				else {
					map<int, row*>::iterator k =std::next(iter,1);
					k->second->pl.push_back(iter->second->pl[j]);
				}
			}
			
		}

	}

}
void parser::writePL() 
{
	string oname = this->filename + "_output";
	ofstream ofs;
	ofs.open(oname + ".pl", ios::out);
	for (int i = 0; i < this->n.size(); i++) {
		node* tmp = n[i];
		ofs << tmp->name<<setw(10)<<tmp->pos.first<<setw(6)<<tmp->pos.second<<" : N ";
		if (tmp->move_type) { ofs << "/ FIXED"; }ofs << '\n';


	}
	ofs.close();
	
}