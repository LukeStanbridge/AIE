#include <iostream>
#include "HashFunction.h"

int main()
{
	HashTable ht;

	if (ht.isEmpty())
	{
		cout << "Correct answer. Good job." << endl;
	}
	else
	{
		cout << "There is an issue, call john" << endl;
	}

	ht.insert(23, "MJ");
	ht.insert(24, "KB");
	ht.insert(21, "TD");
	ht.insert(22, "RG");
	ht.insert(12, "JM");
	ht.insert(15, "VC");
	ht.insert(21, "KG");
	ht.insert(48, "LS");

	ht.print();

	ht.remove(22);
	ht.remove(17);
	ht.remove(24);

	if (ht.isEmpty())
	{
		cout << "There is an issue, call john" << endl;
	}
	else
	{
		cout << "Correct answer. Good job." << endl;
	}

	ht.print();

	return 0;
}