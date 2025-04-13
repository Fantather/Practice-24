#include "Header.h"
#include "array.hpp"
using namespace std;

int main()
{
	my_string str1;						// default constructor
	my_string str2(100);				// constructor with size
	my_string str3("Hello, World!");	// constructor with string
	my_string str4(str3);				// copy constructor
	str1.set("Hello");
	cout << "str1: ";
	str1.get();
	cout << "\nstr2: ";
	str2.get();
	cout << "\nstr3: ";
	str3.get();
	cout << "\nstr4: ";
	str4.get();
	
	// Task 2
	cout << "\n\n Task 2\n";
	my_array<int> arr1;
	my_array<int> arr2(6);
	
	

	cout<< "\narr1: ";
	arr1.get_arr();
	cout << "It is empty";

	cout << "\nAfter set_size(3) and fill_rand(-10, 10): ";
	arr1.set_size(3);
	arr1.fill_rand(-10, 10);
	arr1.get_arr();

	cout << "\n\narr2(6) after rand(-10, 10) and sort: ";
	arr2.fill_rand(-10, 10);
	arr2.sort_arr();
	arr2.get_arr();

	//arr3 = arr2;    Я недостаточно продвинутый для таких приколов
	my_array<int> arr3(arr2);
	cout << "\n\narr3(arr2): ";
	arr3.get_arr();
	cout << endl;
}


//Задание 1.
//Разработать класс String, который в дальнейшем будет использоваться для работы со строками.Класс должен содержать :
//
//Конструктор по умолчанию, позволяющий создать строку длиной 80 символов;
//Конструктор, позволяющий создавать строку произвольного размера;
//Конструктор, который создаёт строку и инициализирует её строкой, полученной от пользователя;
//Конструктор копирования.
//Класс должен содержать методы для ввода строк с клавиатуры и вывода строк на экран.
//
//Задание 2.
//Создайте класс Array(или используйте ранее созданный вами).Класс Array – это класс динамического массива.
//Размер массива может быть передан в качестве параметра или задан с помощью вызова функции - члена.
//
//Класс должен позволять заполнять массив значениями, отображать содержимое массива, изменять размер массива, сортировать массив, определять минимальное и максимальное значение.
//
//Класс должен содержать набор конструкторов(конструктор копирования обязателен), деструктор.