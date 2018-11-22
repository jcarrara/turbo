#include "HTMLPage.h"
#include <functional>
#include <algorithm>


void HTMLPage::parseHTML( string filename ) {
	fstream file( filename );
	queue<string> token = tokenize( file );

	fstream fileoutput( filename );

	cout << "------------------" << endl << "Original File:" << endl << "------------------" << endl;
	string s;
	while ( !fileoutput.eof()) {
		getline( fileoutput, s );
		cout << s << endl;
	}

	cout << "------------------" << endl << "Tokens:" << endl << "------------------" << endl;
	queue<string> token2 = token;
	while ( !token2.empty()) {
		cout << "(" << token2.front() << ")" << endl;
		token2.pop();
	}
	stack<HTMLElement *> elements;

	while ( !token.empty()) {
		if ( token.front()[0] != '<' ) {
			//nonelement code
			elements.top()->content += token.front();
			token.pop();
		}
		else if ( token.front()[1] == '/' ) {
			//end elem code
			while ( !match( elements.top()->key, token.front()) && !elements.empty()) {
				HTMLElement *hold = elements.top();
				elements.pop();
				elements.top()->children.push_back( hold );
				cout << hold->key << endl;
				hold->container = elements.top();
				elements.pop();
			}
			HTMLElement *hold = elements.top();
			elements.pop();
			if ( !elements.empty()) {
				elements.top()->children.push_back( hold );
				cout << hold->key << endl;
				hold->container = elements.top();
			}
			else
				rootelems.push_back( hold );

			token.pop();
		}
		else if ( singleBracket( token.front())) {
			HTMLElement *singlebrak = new HTMLElement( token.front(), elements.top() );
			elements.top()->children.push_back( singlebrak );
			cout << singlebrak->key << endl;
			token.pop();
		}
		else {
			if ( token.front()[1] == '!' || token.front().substr( 1, 4 ) == "meta" ) {
				if( token.front().substr(1,3) == "!--" ){
					//comments
					comments.push_back( new HTMLElement( token.front() ) );
					token.pop();
				}
				else {
					//doctype, etc code
					tags.push_back( new HTMLElement( token.front()));
					token.pop();
				}
			}
				//normal element code
			else {
				elements.push( new HTMLElement( token.front()));
				token.pop();
			}
		}
	}
}


queue<string> HTMLPage::tokenize( fstream &file ) {
	queue<string> strings;
	string s = getToken( file );
	while ( s != "" ) {
		strings.push( s );
		s = getToken( file );
	}

	return strings;
}

string HTMLPage::getToken( fstream &file ) {
	if ( file.eof())
		return "";

	char it;
	file >> it;

	while ( !file.eof() && ( it == ' ' || it == '\t' || it == '\n' ))
		file >> it;

	string element;
	element += it;
	if ( file.peek() == ' ' )
		element += ' ';

	if ( it == '<' ) {
		while ( !file.eof() && it != '>' ) {
			file >> it;
			element += it;
			if ( file.peek() == ' ' )
				element += ' ';
		}
	}
	else {
		while ( !file.eof()) {
			file >> it;
			if ( it == '<' )
				break;
			element += it;
			if ( file.peek() == ' ' )
				element += ' ';
		}
		file.putback( '<' );
	}

	function<string( string )> rtrim = [&]( string s ) -> string {
		while ( s[s.length() - 1] == ' ' ) {
			s = s.substr( 0, s.length() - 1 );
		}
		return s;
	};

	for ( int i = 0; i < element.length(); i++ ) {
		if ( isalpha( element[i] ) || ispunct( element[i] ) || isdigit( element[i] ))
			return rtrim( element );
	}

	return "";
}

void HTMLPage::printPage() {
	cout << "------------------" << endl << "Tags:" << endl << "------------------" << endl << endl;
	for ( HTMLElement *a : tags ) {
		printElem( a, 0 );
	}
	cout << endl << "------------------" << endl << "Elems:" << endl << "------------------" << endl << endl;
	for ( HTMLElement *a : rootelems ) {
		printElem( a, 0 );
	}

		cout << endl << "------------------" << endl << "Comments:" << endl << "------------------" << endl << endl;
		for ( HTMLElement *a : comments ) {
			printElem( a, 0 );
		}
}

void HTMLPage::printElem( HTMLElement *elem, int level ) {

	for ( int i = 0; i < level; i++ )
		cout << '\t';
	cout << elem->key << endl;

	if ( elem->content != "" ) {
		for ( int i = 0; i < level + 1; i++ )
			cout << '\t';

		cout << "\"" << elem->content << "\"" << endl;
	}

	for ( HTMLElement *a : elem->children )
		printElem( a, ( level + 1 ));
}

bool HTMLPage::match( string a, string b ) {
	a = a.substr( 1, a.length() - 2 );
	b = b.substr( 2, b.length() - 3 );

	for ( int i = 0; i < ( a.length() - b.length() + 1 ); i++ ) {
		if ( b == a.substr( i, b.length()))
			return true;
	}
	return false;
}

bool HTMLPage::singleBracket( string a ) {

	a = a.substr( 1, a.length() - 2 );


	while ( a[a.length() - 1] == ' ' )
		a = a.substr( 0, a.length() - 1 );
	while ( a[0] == ' ' )
		a = a.substr( 1, a.length() - 1 );


	transform(a.begin(), a.end(), a.begin(), ::tolower);

	if ( a == "hr" || a == "/br" || a == "br" ) {
		return true;
	}
	if ( a.length() >= 3 )
		if ( a.substr( 0, 3 ) == "img" ){
			return true;
		}
	return false;
}