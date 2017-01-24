#include "node.h"
#include "tools.h"

using namespace	std;

node::node(string _name): name(_name), value(false), nodeInterface(NULL){}

node::~node(){
	delete nodeInterface;
}

void node::reset(){
	setVal(false);
}

void node::set(){
	setVal(true);
}

void node::setVal(bool val){
	value = val;
}

string node::getName() const{
	return name;
}

bool node::isValid() const{
	if(nodeInterface){
		if(!nodeInterface->isValid())
			return false;
		if(nodeInterface->isAnyChildValuable() && !getValue())
			return false;
	}
	return true;
}

bool node::getValue() const{
	return value;
}

void node::makeSubTree(interface_type type, vector <node*> n, vector <bool> isNec){
	switch(type){
		case AND:
		nodeInterface = new interface_AND();
		break;
		case OR:
		nodeInterface = new interface_OR();
		break;
		case XOR:
		nodeInterface = new interface_XOR();
		break;
		default:
		return;
	}
	nodeInterface->makeSubTree(n, isNec);
}
