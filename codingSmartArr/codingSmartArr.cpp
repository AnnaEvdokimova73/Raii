#include <iostream>

class SmartArray {
public:
	SmartArray(int size)
	{
		_size = size;
		arr = new int[_size];
	}

	void addElement(int value)
	{
		if (curIndex >= _size)
		{
			throw std::exception("Error! Array is full");
		}
		arr[curIndex] = value;
		++curIndex;
	}

	int getElement(int index)
	{
		if (index >= _size)
		{
			throw std::exception("Error! Index out of bounds");
		}
		return arr[index];
	}

	void operator=(SmartArray& rightArr)
	{
		delete[] arr;
		_size = rightArr._size;
		arr = new int[_size];

		for (int i = 0; i < _size; ++i)
		{
			arr[i] = rightArr.getElement(i);
		}
	}

	/*void operator=(SmartArray& rightArr)
	{
		int size = 0;
		if (_size <= rightArr._size)
		{
			size = _size;
		}
		else
		{
			size = rightArr._size;
		}
		for (int i = 0; i < size; ++i)
		{
			arr[i] = rightArr.getElement(i);
		}
	}*/

	~SmartArray()
	{
		delete[] arr;
	}

private:
	int* arr;
	int _size;
	int curIndex = 0;
};

int main()
{
	try {
		SmartArray arr(5);
		arr.addElement(1);
		arr.addElement(4);
		arr.addElement(155);

		SmartArray new_array(2);
		new_array.addElement(44);
		new_array.addElement(34);

		arr = new_array;

		// Проверка
		std::cout << arr.getElement(0) << std::endl;
		std::cout << arr.getElement(1) << std::endl;
		std::cout << arr.getElement(2) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}

