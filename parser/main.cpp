#include <iostream>
#include "HTMLPage.h"

int main() {
	cout << endl << "==========================================" << endl << "TEST 1" << endl << "==========================================" << endl << endl;
	HTMLPage test;
	test.parseHTML("test.html");
	test.printPage();
	cout << endl << "==========================================" << endl << "TEST 2" << endl << "==========================================" << endl << endl;
	HTMLPage test2;
	test2.parseHTML("test2.html");
	test2.printPage();
	cout << endl << "==========================================" << endl << "TEST 3" << endl << "==========================================" << endl << endl;
	HTMLPage test3;
	test3.parseHTML("test3.html");
	test3.printPage();
	cout << endl << "==========================================" << endl << "TEST 4" << endl << "==========================================" << endl << endl;
	HTMLPage test4;
	test4.parseHTML("test4.html");
	test4.printPage();
	return 0;
}