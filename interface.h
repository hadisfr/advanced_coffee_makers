#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>
#include <vector>
class node;

enum interface_type{AND, OR, XOR, INVALID};

interface_type str2interface_type(std::string);

class interface{
public:
	interface();
	virtual bool isValid();
	bool isAnyChildValuable();
	virtual void makeSubTree(std::vector <node*>, std::vector <bool>);
protected:
	std::vector<node*> childs;
};

class interface_AND: public interface{
public:
	bool isValid();
	void makeSubTree(std::vector <node*>, std::vector <bool>);
private:
	std::vector <bool> isNec; // Child is necessary or not. It was better to implement this somehow with a struct of {node*, isNec}.
};

class interface_OR: public interface{
public:
	bool isValid();
};

class interface_XOR: public interface{
public:
	bool isValid();
};

#endif