//
// Created by joe on 11/21/18.
//

#ifndef PARSER_PARSER_H
#define PARSER_PARSER_H

#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <fstream>
#include <iostream>
using namespace std;

class HTMLPage{
public:
	explicit HTMLPage() = default;
	void parseHTML( string filename );
	void printPage();
private:

	class HTMLElement{
	public:
		HTMLElement( string s, HTMLElement *parent ) : key(s), container(parent) { }
		HTMLElement( string s ) : key(s), container(nullptr) {}

		string key;
		string content = "";
		HTMLElement *container;
		vector<HTMLElement*> children;
	};

	queue<string> tokenize( fstream &file );
	string getToken( fstream &file );
	void printElem( HTMLElement *elem, int level );
	bool match( string a, string b );
	bool singleBracket( string a );


	vector<HTMLElement*> tags;
	vector<HTMLElement*> comments;
	vector<HTMLElement*> rootelems;

};
#endif //PARSER_PARSER_H
