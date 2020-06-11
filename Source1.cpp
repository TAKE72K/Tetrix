#include "parser.h"
#include<string>
#include<iostream>

#define  endl '\n'
using namespace std;
int main(int argc, char *argv[]) {
	std::string fn = "adaptec1";
	if (argc > 1) { fn = argv[1]; }
	parser* a;a=new parser(fn);
	a->legal();
	a->n[0]->print();
	cout<<a->n[0]->nearY()<<endl;
	a->n[210904]->print();
	a->n[211386]->print();
	cout<<a->r.size();
	a->writePL();
	system("pause");

 }