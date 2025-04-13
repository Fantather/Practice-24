#pragma once
#include <random>
#include <algorithm>

template <typename T>
class my_array {
	size_t size;
	size_t capacity;
	T* arr;

	void increase_capacity(size_t& new_capacity);
	void decrease_capacity(size_t& new_capacity);

public:
	my_array();
	my_array(size_t user_size);
	my_array(const my_array& user_obj);
	~my_array();

	void set_size(size_t user_capacity);
	void sort_arr();

	void get_arr() const;
	T get_max() const;
	T get_min() const;

	void fill_rand(int START, int END);
	//void fill_rand(int START, int END, size_t first_index, size_t last_index);
};



template<typename T>
inline void my_array<T>::increase_capacity(size_t& new_capacity)
{
	new_capacity *= 2;
}

template<typename T>
inline void my_array<T>::decrease_capacity(size_t& new_capacity)
{
	while (new_capacity > size * 2) {
		new_capacity = std::max(size, new_capacity / 2);
	}
}

template<typename T>
inline my_array<T>::my_array() : size(0), capacity(size), arr(nullptr) {}

template<typename T>
inline my_array<T>::my_array(size_t user_size) : size(user_size), capacity(size), arr(new T[capacity]) {}

template<typename T>
inline my_array<T>::my_array(const my_array& user_obj) : size(user_obj.size), capacity(user_obj.capacity)
{
	arr = new T[capacity];
	for (size_t i = 0; i < size; i++) {
		arr[i] = user_obj.arr[i];
	}
}

template<typename T>
inline my_array<T>::~my_array()
{
	delete[] arr;
}


template<typename T>
inline void my_array<T>::set_size(size_t user_capacity)
{
	if (user_capacity < size) {
		std::cout << "The new size is too small";
		return;
	}

	if (user_capacity == capacity) {
		return;
	}


	T* new_arr = new T[user_capacity];

	for (size_t i = 0; i < size; i++) {
		new_arr[i] = arr[i];
	}

	delete[] arr;
	arr = new_arr;

	capacity = user_capacity;
}

template<typename T>
inline void my_array<T>::get_arr() const
{
	for (size_t i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
}

template<typename T>
inline T my_array<T>::get_max() const
{
	T max_value= arr[0];
	for (size_t i = 1; i < size; i++) {
		max_value = std::max(max_value, arr[i]);
	}

	return max_value;
}

template<typename T>
inline T my_array<T>::get_min() const
{
	T min_value = arr[0];
	for (size_t i = 1; i < size; i++) {
		min_value = std::min(min_value, arr[i]);
	}

	return min_value;
}

template<typename T>
inline void my_array<T>::sort_arr()
{
	for (size_t i = 0; i < size - 1; i++) {
		for (size_t j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
}

template<typename T>
inline void my_array<T>::fill_rand(int START, int END)
{
	if (START > END) {
		std::swap(START, END);
	}

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(START, END);

	for (size_t i = 0; i < capacity; i++) {
		arr[i] = dist(gen);
	}

	size = capacity;
}


//Даёт возможность заполнять не с первой ячейки, что может привести к нестабильной работе остальных методов, так что я его заккоментировал
//template<typename T>
//inline void my_array<T>::fill_rand(int START, int END, size_t first_index, size_t last_index)
//{
//	if (START > END) {
//		std::swap(START, END);
//	}
//
//	std::random_device rd;
//	std::mt19937 gen(rd());
//	std::uniform_int_distribution<> dist(START, END);
//
//	if (last_index > capacity) {
//		last_index = capacity;
//	}
//
//	for (size_t i = first_index; i < last_index; i++) {
//		arr[i] = dist(gen);
//	}
//
//	size = capacity;
//}
