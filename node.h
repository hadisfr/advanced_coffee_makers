#ifndef NODE_H
#define NODE_H

#include "interface.h"
#include <string>

class node{
public:
	node(std::string);
	~node();
	void reset();
	void set();
	std::string getName() const;
	bool isValid() const;
	bool getValue() const;
	void makeSubTree(interface_type, std::vector <node*>, std::vector <bool>);
private:
	std::string name;
	bool value;
	interface* nodeInterface;
	void setVal(bool);
};

#endif