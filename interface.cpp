#include "interface.h"
#include "tools.h"
#include "node.h"

using namespace std;

interface_type str2interface_type(string str){
	if(str ==  "+")
		return AND;
	if(str ==  "|")
		return OR;
	if(str ==  "^")
		return XOR;
	return INVALID;
}

interface::interface(){}

bool interface::isAnyChildValuable(){
	for(int i = 0; i < childs.size(); i++)
		if(childs[i]->getValue())
			return true;
	return false;
}

bool interface::isValid(){
	for(int i = 0; i < childs.size(); i++)
		if(!childs[i]->isValid())
			return false;
	return true;
}

void interface::makeSubTree(vector <node*> n, vector <bool> isNec = vector <bool> ()){
	for(int i = 0; i < n.size(); i++){
		childs.push_back(n[i]);
	}
}

void interface_AND::makeSubTree(vector <node*> n, vector <bool> _isNec){
	interface::makeSubTree(n, _isNec);
	for(int i = 0; i < _isNec.size(); i++){
		isNec.push_back(_isNec[i]);
	}
}

bool interface_AND::isValid(){
	if(!interface::isValid())
		return false;
	for(int i = 0; i < childs.size(); i++)
		if(isNec[i] && !childs[i]->getValue())
			return false;
	return true;
}

bool interface_OR::isValid(){
	if(!interface::isValid())
		return false;
	for(int i = 0; i < childs.size(); i++)
		if(childs[i]->getValue())
			return true;
	return false;
}

bool interface_XOR::isValid(){
	if(!interface::isValid())
		return false;
	int j = 0;
	for(int i = 0; i < childs.size(); i++)
		if(childs[i]->getValue())
			j++;
	return j == 1;
}
