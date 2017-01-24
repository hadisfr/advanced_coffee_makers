#include "tools.h"

using namespace std;

/*
	It is strongly necessary to make parser functions bulletproof with throw and catch blocks.
*/

string trimStr(string str){
	int i;
	for(i = 0; i < str.size(); i++)
		if(str[i] != ' ')
			break;
	str = str.substr(i, str.size() - i + 1);
	for(i = str.size(); i; i--)
		if(str[i - 1] != ' ')
			break;
	str = str.substr(0, i);
	return str;
}

vector <string> parseExpr(string str){
	vector <string> expr;
	size_t start = 0, end = str.find("=");
	expr.push_back(trimStr(str.substr(start, end - start)));
	str = str.substr(end + 1);
	start = str.find("+") != string::npos ? str.find("+") : str.find("|") != string::npos ? str.find("|") : str.find("^");
	expr.push_back(start == string::npos ? "+" : str.substr(start, 1));
	start = 0;
	string tstr;
	do{
		end = str.find(expr[1], start);
		if(end == string::npos)
			tstr = str.substr(start);
		else
			tstr = str.substr(start, end - start);
		tstr = trimStr(tstr);
		if(tstr[0] == '?'){
			expr.push_back("?");
			tstr = tstr.substr(1);
			tstr = trimStr(tstr);
		}
		expr.push_back(tstr);
		start = end + 1;
	}while(end != string::npos);
	return expr;
}

vector <string> parseSet(string str){
	vector <string> set;
	str = str.substr(1, str.size() - 2);
	size_t start = 0, end;
	string tstr;
	do{
		end = str.find(",", start);
		if(end == string::npos)
			tstr = str.substr(start);
		else
			tstr = str.substr(start, end - start);
		set.push_back(trimStr(tstr));
		start = end + 1;
	}while(end != string::npos);
	return set;
}
