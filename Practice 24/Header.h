#pragma once
#include <iostream>
#include <algorithm>

class my_string {
	size_t size;		// size of string
	size_t capacity;	// capacity of string
	char* str;			// pointer to string

public:
	// default constructor
	my_string();

	// constructor with size
	my_string(size_t user_size);

	// constructor with string
	my_string(const char* user_str);

	// copy constructor
	my_string(const my_string& user_str);

	// destructor
	~my_string();

	// method to set string
	void set(const char* user_str);

	// method to get string
	void get() const;
};