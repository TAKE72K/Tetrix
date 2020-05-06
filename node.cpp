#include"node.h"
#include<string>
using namespace std;
node::node(int k, pair<int, int>p, bool t, string n) {
	key = k;
	pos = p;
	type = t;
	name = n;
}