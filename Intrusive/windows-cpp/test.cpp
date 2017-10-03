#include <iostream>
#include <string>
#include "intrusive_list.h"

using namespace std;

int main()
{
	struct Person {
		Person(const char* name) : m_name(name) {}

		string m_name;
		int m_age;
	};

	intrusive_list<Person> lst;

	Person* p0 = lst.add("11");
	lst.add("2");
	lst.add("3");
	lst.add("4");
	lst.add("5");
	Person* p1 = lst.add("6");

	lst.remove(p0);
	lst.remove(p1);

	for (auto iter = lst.begin(); iter != lst.end(); ++iter) {
		cout << iter->m_name << endl;
	}

	return 0;
}