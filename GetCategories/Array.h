#ifndef _ARRAYHEADER_
#define _ARRAYHEADER_
#ifndef _IOSTREAM_
#include <iostream>
#endif // !_IOSTREAM_
template <typename Type> class Array {
private:
	Type *_elements = nullptr;
	size_t _length = 0;
public:
	Array() {
		Type *_elements = new Type[0];
		_length = 0;
	}

	Type append() {
		Type *temp = new Type[_length + 1]();
		for (size_t i = 0; i < _length; i++)
			temp[i] = _elements[i];

		if (_length > 0) {
			delete[] _elements;
		}
		_elements = temp;
		return _elements[_length++];
	}

	Type append(Type val) {
		Type *temp = new Type[_length + 1]();
		for (size_t i = 0; i < _length; i++)
			temp[i] = _elements[i];

		if (_length > 0) {
			delete[] _elements;
		}
		_elements = temp;
		_elements[_length] = val;
		return _elements[_length++];
	}

	Type pop() {
		if (_length == 0) {
			std::cout << "Nothing to pop" << std::endl;
			exit(-2);
		}
		_length--;

		Type *temp = new Type[_length]();
		memcpy(temp, _elements, sizeof(Type) * _length);
		Type buffer = _elements[_length];
		delete[] _elements;
		_elements = temp;
		return buffer;
	}

	Type &last() {
		return _elements[_length - 1];
	}

	Type &operator[](int index) {
		if (index >= _length) {
			std::cout << "Index out of range" << std::endl;
			exit(-1);
		}
		return _elements[index];
	}

	~Array() {
		if(_length > 0)
			delete[] _elements;
	}

	size_t length() { return _length; }
};
#endif // !_ARRAYHEADER_
