#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

class Set
{
public:
	Set() :size(0), data(new char[1]) { *data = '\0'; };
	explicit Set(size_t _size) : size(_size), data(new char[size + 1]) {};
	Set(const char* str) : size(strlen(str)), data(new char[size + 1]) { strcpy(data, str); };
	Set(const Set& set) : size(strlen(set.data)), data(new char[size + 1]) { strcpy(data, set.data); };

	~Set() { delete[]data; };

	Set& operator=(const Set& a);
	Set& operator=(const char*);
	const Set& operator*(const Set& a) const;
	const Set& operator+(const Set& a) const;
	const Set& operator-(const Set& a) const;
	bool operator<(const Set& a) const;

	friend std::istream& operator>>(std::istream& in, Set& set);
	friend std::ostream& operator<<(std::ostream& out, const Set& set);

private:
	size_t size;
	char* data;
};

Set& Set::operator=(const Set& a)
{
	if (this != &a)
	{
		delete[]data;
		size = a.size;
		data = new char[size + 1];
		strcpy(data, a.data);
	}
	return *this;
}
Set& Set::operator=(const char* str)
{
	delete[]data;
	size = strlen(str);
	data = new char[size + 1];
	strcpy(data, str);

	return *this;
}
const Set& Set::operator*(const Set& a) const
{
	static Set result;
	char str[255]{ '\0' };
	size_t size = 0;

	for (size_t i = 0; i < this->size; i++)
	{
		for (size_t j = 0; j < a.size; j++)
		{
			if (a.data[j] == this->data[i])
			{
				str[size++] = a.data[j];
				break;
			}
		}
	}

	result = new char[size];
	strcpy(result.data, str);

	return result;
}
const Set& Set::operator+(const Set& a) const
{
	static Set result;
	char str[255]{ '\0' };
	size_t size = 0;

	sizeof(this) > sizeof(a) ? size = this->size : size = a.size;
	sizeof(this) > sizeof(a) ? strcpy(str, this->data) : strcpy(str, a.data);

	for (size_t i = 0; i < this->size; i++)
	{
		bool flag = true;
		for (size_t j = 0; j < a.size; j++)
		{
			if (a.data[j] == this->data[i])
			{
				flag = false;
				break;
			}
		}
		if (flag)
			str[size++] = this->data[i];
	}

	result = new char[size];
	strcpy(result.data, str);

	return result;
}
const Set& Set::operator-(const Set& a) const
{
	static Set result;
	char str[255]{ '\0' };
	size_t size = 0;

	for (size_t i = 0; i < this->size; i++)
	{
		bool flag = true;
		for (size_t j = 0; j < a.size; j++)
		{
			if (a.data[j] == this->data[i])
			{
				flag = false;
				break;
			}
		}
		if (flag)
			str[size++] = this->data[i];
	}

	result = new char[size];
	strcpy(result.data, str);

	return result;
}
bool Set::operator<(const Set& a) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (!strchr(a.data, data[i]))
			return false;
	}
	return true;
}

std::istream& operator>>(std::istream& in, Set& set)
{
	char str[255];
	in >> str;

	set.size = strlen(str) + 1;
	delete[]set.data;
	set.data = new char[set.size];
	strcpy(set.data, str);

	return in;
}
std::ostream& operator<<(std::ostream& out, const Set& set)
{
	out << set.data;
	return out;
}

class Stack
{
public:
	Stack() : size(0), data(new int[0]), top(0) {};
	explicit Stack(int _size, int _top) : size(_size), data(new int[size]), top(_top) {};
	Stack(const Stack& st) : size(st.size), data(new int[size]), top(st.top) {};

	void push(int);
	void print();

	friend std::istream& operator>>(std::istream& in, Stack& st);
	friend std::ostream& operator<<(std::ostream& out, const Stack& st);

private:
	int size;
	int* data;
	int top;
};

void Stack::push(int key)
{
	this->size++;
	this->data[this->size] = key;
}
void Stack::print()
{
	for (size_t i = 0; i < this->size; i++)
		std::cout << this->data[i] << " ";
	std::cout << std::endl;
}

std::istream& operator>>(std::istream& in, Stack& st)
{
	in >> *st.data;
	return in;
}
std::ostream& operator<<(std::ostream& out, const Stack& st)
{
	out << st.data;
	return out;
}
