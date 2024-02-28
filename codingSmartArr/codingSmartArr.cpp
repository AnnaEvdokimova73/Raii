#include <iostream>

class SmartArray {
public:
	SmartArray(int size)
	{
		_size = size;
		arr = new int[_size];
	}

	SmartArray(const SmartArray& rightArr) // конструктор копирования
	{
		_size = rightArr._size;
		_curIndex = rightArr._curIndex;
		arr = new int[_size];

		for (int i = 0; i < _size; ++i)
		{
			arr[i] = rightArr.arr[i];
		}
	}

	void addElement(int value)
	{
		if (_curIndex >= _size)
		{
			throw std::runtime_error("Error! Array is full");
		}
		arr[_curIndex] = value;
		++_curIndex;
	}

	int getElement(int index)
	{
		if (index < 0 || index >= _curIndex)
		{
			// throw std::exception("Error! Index out of bounds"); // только для Windows
			throw std::runtime_error("Error! Index out of bounds");
		}
		return arr[index];
	}

	SmartArray& operator=(const SmartArray& rightArr)
	{
		if (this != &rightArr) // если указатели на объект не совпадают, тогда производим копирование
		{
			delete[] arr;
			_size = rightArr._size;
			_curIndex = rightArr._curIndex;
			arr = new int[_size];

			for (int i = 0; i < _size; ++i)
			{
				arr[i] = rightArr.arr[i];
			}
		}
		return *this;
	}

	~SmartArray()
	{
		delete[] arr;
	}

private:
	int* arr;
	int _size;
	int _curIndex = 0;
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
	catch (const std::runtime_error& ex) {
		std::cout << ex.what() << std::endl;
	}
}

