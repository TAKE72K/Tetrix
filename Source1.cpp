#include "parser.h"
#include<string>
#include<iostream>

#define  endl '\n'
using namespace std;
int main() {
	std::string fn = "adaptec1";
	parser* a;a=new parser(fn);
	a->legal();
	a->n[0]->print();
	cout<<a->n[0]->nearY()<<endl;
	a->n[210904]->print();
	a->n[211386]->print();
	cout<<a->r.size();

	system("pause");

}