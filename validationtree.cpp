#include "validationtree.h"
#include "tools.h"

using namespace std;

validationTree::validationTree(): head(NULL){}

validationTree::~validationTree(){
	while(nodes.size()){
		delete nodes.back();
		nodes.pop_back();
	}
}

void validationTree::grow(string str){
	/*
		this function and functions we'll use in it from node and interface classes strongly needed to be made bulletproof
		using throw and catch statements.
	*/
	vector <string> expr = parseExpr(str);
	vector <node*> n;
	vector <bool> isNec;
	node* h = getNode(expr[0]);
	if(!h){
		h = new node(expr[0]);
		addNode(h);
	}
	interface_type type = str2interface_type(expr[1]);
	for(int i = 2; i < expr.size(); i++){
		if(type == AND){
			if(expr[i] == "?"){
				isNec.push_back(false);
				i++;
				// if(i >= expr.size()) throw err;
			}
			else{
				isNec.push_back(true);
			}
		}
		node * p = getNode(expr[i]);
		if(!p){
			p = new node(expr[i]);
			addNode(p);
		}
		n.push_back(p);
	}
	h->makeSubTree(type, n, isNec);
}

bool validationTree::isValidQuery(string query){
	if(!head)
		return false;
	reset();
	vector <string> queryNodes = parseSet(query);
	for(int i = 0; i < queryNodes.size(); i++){
		node* p = getNode(queryNodes[i]);
		if(!p)
			return false;
		p->set();
	}
	return head->getValue() && head->isValid();
}

node* validationTree::getNode(string name) const{
	for(int i = 0; i < nodes.size(); i++)
		if(nodes[i]->getName() == name)
			return nodes[i];
	return NULL;
}

void validationTree::addNode(node* n){
	if(!nodes.size())
		head = n;
	nodes.push_back(n);
}

void validationTree::reset(){
	for(int i = 0; i < nodes.size(); i++)
		nodes[i]->reset();
}