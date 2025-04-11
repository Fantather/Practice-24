#include "Header.h"

my_string::my_string() : size(0), capacity(81), str(new char[capacity]) {
	str[0] = '\0';
}

my_string::my_string(size_t user_size) : size(user_size), capacity(size + 1), str(new char[capacity])
{
	str[0] = '\0';
}

my_string::my_string(const char* user_str)
{
	if(user_str) {
		size = strlen(user_str);
		capacity = size + 1;
		str = new char[capacity];

		strcpy_s(str, capacity, user_str);
	}

	else {
		size = 0;
		capacity = size + 1;
		str = new char[capacity];

		str[0] = '\0';
	}
}

// if str is null, set it to empty string
my_string::my_string(const my_string& user_str) : size(user_str.size), capacity(user_str.capacity), str(new char[user_str.capacity])
{
	strcpy_s(str, capacity, user_str.str ? user_str.str : "");
}

my_string::~my_string()
{
	if (str) {
		delete[] str;
		str = nullptr;
	}
}

void my_string::set(const char* user_str)
{
	if (user_str == nullptr) {
		return;
	}

	// set size to the length of the new string
	size_t new_capacity = capacity;
	size = strlen(user_str);

	// if the new string is longer than the current capacity, double the capacity until it is large enough
	while (new_capacity < size + 1) {
		new_capacity *= 2;
	}

	// if the new capacity is more than twice the size, halve it until it is less than twice the size
	while (new_capacity > (size + 1) * 2) {
		new_capacity = max(size + 1, new_capacity / 2);
	}

	// set new string
	delete[] str;
	str = new char[new_capacity];
	strcpy_s(str, new_capacity, user_str);

	// set capacity
	capacity = new_capacity;
}

void my_string::get() const
{
	cout << str;
}