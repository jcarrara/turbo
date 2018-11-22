#include "HTMLPage.h"

void HTMLPage::parseHTML( string filename ) {
	fstream file;
	file.open( filename );

	if ( file.fail()) {
		cout << "Fail.";
		return;
	}

	queue<string> tokens = tokenize( file );

	parseHTML( nullptr, tokens );


}

HTMLPage::HTMLElement *HTMLPage::parseHTML( HTMLElement *parent, queue<string> &tokens ) {

	if ( tokens.empty())
		return nullptr;

	string key = tokens.front().substr( 1, tokens.front().length() - 2 );
	string tag = tokens.front().substr( 1, tokens.front().length() - 2 );
	if( tag[0] != '!' ){
		bool tagging = true;
		for( int i = 0; i < key.length(); i++) {
			if ( tag[i] == ' ' ){
				tag = tag.substr( i+1, tag.length()-i-1 );
				tagging = false;
				break;
			}
		}
		if( tagging )
			tag = "";
	}
	else{
		for( int i = 0; i < key.length(); i++) {
			if ( tag[i] == ' ' ){
				tag = tag.substr( 1, i-1 ) + "=" + tag.substr( i+1, tag.length()-i-1);
				break;
			}
		}
	}


	HTMLElement *tagElem = new HTMLElement( tag, nullptr );
//	cout << key << endl;
	for( int i = 0; i < key.length(); i++) {
		if ( key[i] == ' ' ){
			key = key.substr( 0, i );
			break;
		}
	}
//	cout << key  << "()" << endl;

	HTMLElement *newElem = new HTMLElement( key, parent );

	if ( parent == nullptr ) {
		if ( tokens.front()[1] == '!' || tokens.front().substr( 1, 4 ) == "meta" ) {
			tokens.pop();
//			cout << "TAG PUSH: " << tag;
			tags.push_back( tagElem );
			parseHTML( nullptr, tokens );
			return nullptr;
		}
		else {
			tokens.pop();
			if( tag != "" ){
//				cout << "TAG PUSH: " << tag;
				tags.push_back( tagElem );
			}
			rootelems.push_back( newElem );
			while ( (( '/' + key ) != tokens.front().substr( 1, tokens.front().length() - 2 )) )
				parseHTML( newElem, tokens );
			return nullptr;
		}
	}
	if ( tokens.front()[0] == '<' ) {
		tokens.pop();
		if ( key.substr( 0, 4 ) == "meta" ) {
			tags.push_back( tagElem );
			return nullptr;
		}
		if ( key == ( '/' + parent->key ))
			return nullptr;
		else {
			parent->children.push_back( newElem );
			while (( '/' + key ) != tokens.front().substr( 1, tokens.front().length() - 2 ) ) {
				parseHTML( newElem, tokens );
			}
			tokens.pop();
			return nullptr;
		}
	}
	else {

		parent->content = tokens.front();
		tokens.pop();
		return nullptr;
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

	for ( int i = 0; i < element.length(); i++ ) {
		if ( isalpha( element[i] ) || ispunct( element[i] ) || isdigit( element[i] ))
			return element;
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