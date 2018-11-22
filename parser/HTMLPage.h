//
// Created by joe on 11/21/18.
//

#ifndef PARSER_PARSER_H
#define PARSER_PARSER_H

#include <string>
#include <vector>
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

	HTMLElement * parseHTML( HTMLElement *parent, queue<string> &tokens );
	queue<string> tokenize( fstream &file );
	string getToken( fstream &file );
	void printElem( HTMLElement *elem, int level );

	vector<HTMLElement*> tags;
	vector<HTMLElement*> rootelems;

};
#endif //PARSER_PARSER_H
