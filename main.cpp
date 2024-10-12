#include <iostream>
using namespace std;

#include "solo_linked_list.h"

int main()
{
	List<char*> list;
	list.push_front("Hello");
	list.push_front("Hi");
	list.pop_front();
	list.push_back("Bye");
	list.print();
	cout << endl;

	list.push_front("My name is Andrew");
	list.print();
	cout << endl;

	list.clear();
	list.print();

	return 0;
}