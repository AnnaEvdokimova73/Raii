#include <iostream>

class  SmartArray {
public:
	SmartArray(int size)
	{
		_size = size;
		arr = new int[_size];
	}

	void addElement(int value)
	{
		// static int curIndex = 0;
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
		arr.addElement(14);
		arr.addElement(15);
		std::cout << arr.getElement(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}

