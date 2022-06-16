#pragma once
#include <iostream>
#include <list>
#include <cstring>
using namespace std;

class HashTable
{
private:
	static const int buckets = 10;
	list<pair<int, string>> table[buckets];

public:
	bool isEmpty() const; // check if table is empty
	int hashFunction(int key); // hash function
	void insert(int key, string value); // insert into hash table
	void remove(int key); // remove from hash table
	string search(int key); // search table 
	void print(); // print out the hash table
};