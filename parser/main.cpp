#include <iostream>
#include "HTMLPage.h"

int main() {
	HTMLPage test;
	test.parseHTML("test.html");
	test.printPage();
	cout << "////////////////////////////////////////////////////////" << endl;
	HTMLPage test2;
	test2.parseHTML("test2.html");
	test2.printPage();
	return 0;
}