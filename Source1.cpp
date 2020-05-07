#include "parser.h"
#include<string>
#include<iostream>
using namespace std;
int main() {
	std::string fn = "adaptec1";
	parser* a;a=new parser(fn);
	a->n[0]->print();
	a->n[210904]->print();
	a->n[211386]->print();
	cout<<a->r.size();
	system("pause");

}