#ifndef VTREE_H
#define VTREE_H

#include <string>
#include <vector>
#include "node.h"

class validationTree{
public:
	validationTree();
	~validationTree();
	void grow(std::string);
	bool isValidQuery(std::string);
private:
	node* head;
	std::vector <node *> nodes;
	node* getNode(std::string) const;
	void addNode(node*);
	void reset();
};

#endif