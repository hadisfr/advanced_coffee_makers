#include <iostream>
#include <string>
#include "validationtree.h"
#include "tools.h"

using namespace std;

void process(){
	string str;
	bool isMakingTree = true;
	validationTree vTree;
	while(getline(cin, str)){
		if(str == "##"){
			cout << "##" << endl;
			return;
		}
		if(str == "#"){
			isMakingTree = false;
			continue;
		}
		if(isMakingTree){
			vTree.grow(str);
		}
		else{
			cout << (vTree.isValidQuery(str) ? "Valid" : "Invalid") << endl;
		}
	}
}

int main(){
	while(!cin.eof()){
		process();
	}
	return 0;
}