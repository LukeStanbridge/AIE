#include <iostream>
#include<list>
#include<cstring>
#include "HashFunction.h"
using namespace std;

bool HashTable::isEmpty() const
{
	int sum{};
	for (int i{}; i < buckets; i++)
	{
		sum += table[i].size();
	}

	// checking if sum is zero
	if (!sum)
	{
		return true;
	}
	return false;
}

int HashTable::hashFunction(int key)
{
	return key % buckets; // check modulus(remainder) for buckets
}

void HashTable::insert(int key, string value)
{
	int hashValue = hashFunction(key); // need hashed value to correspond to the key
	auto& cell = table[hashValue]; // create list that we will put in the key value to
	auto bItr = begin(cell); // iterator to the beginning of this list
	bool keyExists = false; // assuming key doesnt exist

	// replace value with same key
	for (; bItr != end(cell); bItr++)
	{
		if (bItr->first == key)
		{
			keyExists = true;
			bItr->second = value;
			cout << "[WARNING] Key exists. Value replaced." << endl;
			break;
		}
	}

	if (!keyExists)
	{
		cell.emplace_back(key, value);
	}
	return;
}

void HashTable::remove(int key)
{
	int hashValue = hashFunction(key); // need hashed value to correspond to the key
	auto& cell = table[hashValue]; // create list that we will put in the key value to
	auto bItr = begin(cell); // iterator to the beginning of this list
	bool keyExists = false; // assuming key doesnt exist

	// iterates through list and removes pair if it's in table
	for (; bItr != end(cell); bItr++)
	{
		if (bItr->first == key)
		{
			keyExists = true;
			bItr = cell.erase(bItr);
			cout << "[INFO] Pair removed." << endl;
			break;
		}
	}

	if (!keyExists)
	{
		cout << "[WARNING] Key not found. Pair not removed." << endl;
	}
	return;
}

void HashTable::print()
{
	for (int i{}; i < buckets; i++)
	{
		if (table[i].size() == 0) continue; // stop looking

		auto bItr = table[i].begin();
		for (; bItr != table[i].end(); bItr++)
		{
			cout << "[INFO] Key: " << bItr->first << " Value: " << bItr->second << endl;
		}
	}
	return;
}
