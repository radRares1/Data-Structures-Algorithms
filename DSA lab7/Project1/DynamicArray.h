#pragma once
#include <iterator>

template <typename T>
class DynamicArray
{
private:
	T* elements;
	int size;
	int capacity;

public:
	DynamicArray(int capacity = 10);
	DynamicArray(const DynamicArray& v);
	~DynamicArray();

	DynamicArray& operator=(const DynamicArray& v);
	T& operator[] (int position);

	void add(const T& element);
	void add(int index, const T& element);
	bool remove(const T& element);

	bool remove(const int index);

	int getSize() const;
	void setSize(int s) { size = s; }

private:
	void resize(int factor = 2);

public:
	class iterator
	{
	private:
		T* ptr;
	public:
		iterator() {
		}

		iterator(T* ptr) {
			this->ptr = ptr;
		}

		iterator operator++() {
			this->ptr++;
			return iterator{ this->ptr };
		}

		iterator operator++(int) {
			iterator currentIT = *this;
			this->ptr++;
			return currentIT;
		}

		T operator* () {
			return *this->ptr;
		}

		bool operator!= (const iterator& it) {
			return (this->ptr != it.ptr);
		}

		T value() {
			return *this->ptr;
		}
	};

	iterator begin() const
	{
		return iterator{ this->elements };
	}

	iterator end() const
	{
		return iterator{ this->elements + this->size };
	}
};

template <typename T>
DynamicArray<T>::DynamicArray(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elements = new T[capacity];
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& v)
{
	this->size = v.size;
	this->capacity = v.capacity;
	this->elements = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elements[i] = v.elements[i];
}

template <typename T>
DynamicArray<T>::~DynamicArray()
{
	delete[] this->elements;
}

template <typename T>
T& DynamicArray<T>::operator[] (int position) {
	return this->elements[position];
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& v)
{
	if (this == &v)
		return *this;

	this->size = v.size;
	this->capacity = v.capacity;

	delete[] this->elements;
	this->elements = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elements[i] = v.elements[i];

	return *this;

}

template <typename T>
void DynamicArray<T>::add(const T& element)
{
	if (this->size == this->capacity) {
		this->resize();
	}
		
	this->elements[this->size] = element;
	this->size++;
}

template <typename T>
void DynamicArray<T>::add(int index, const T& element)
{
	if (this->size == this->capacity) {
		this->resize();
	}
		
	int length = this->size;
	for (int i = length; i > index; i--) {
		this->elements[i] = this->elements[i-1];
	}
	this->elements[index] = element;
	this->size++;
}

template<typename T>
bool DynamicArray<T>::remove(const T & element)
{
	int i = 0;
	while (this->elements[i] != element && i < this->getSize()) {
		i++;
	}
	if (i == this->getSize()) {
		return false;
	}

	T elementToBeRemoved = this->elements[i];
	for (int j = i; j < this->getSize(); j++) {
		   this->elements[j] = this->elements[j + 1];
		}
	this->size--;

	return true;
}

template<typename T>
bool DynamicArray<T>::remove(const int index)
{

	if (index >= this->getSize()) {
		return false;
	}

	T elementToBeRemoved = this->elements[index];
	for (int j = index; j < this->getSize(); j++) {
		this->elements[j] = this->elements[j + 1];
	}
	this->size--;

	return true;
}

template <typename T>
void DynamicArray<T>::resize(int factor)
{
	this->capacity *= factor;

	T* currentElements = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		currentElements[i] = this->elements[i];

	delete[] this->elements;
	this->elements = currentElements;
}

template <typename T>
int DynamicArray<T>::getSize() const
{
	return this->size;
}

