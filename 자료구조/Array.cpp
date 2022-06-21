#include <iostream>

using namespace std;

typedef int T;
class Array {
private:
	T* arr;
	int arrSize;

public:
	Array(int size) : arrSize(size) {
		arr = new T[arrSize];
		for (int i = 0; i < size; i++) {
			arr[i] = 0;
		}
	}
	Array(int size, T elem) : arrSize(size) {
		arr = new T[arrSize];
		for (int i = 0; i < size; i++) {
			arr[i] = elem;
		}
	}
	~Array() {
		delete[] arr;
	}
	T at(int i) {
		return arr[i];
	}
	void set(int i, T elem) {
		arr[i] = elem;
	}
	void push_back(T elem) {
		int newSize = arrSize + 1;
		T* temp = new T[newSize];
		for (int i = 0; i < arrSize; i++) {
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;
		arrSize = newSize;
		arr[arrSize - 1] = elem;
	}
	void remove(int i) {
		for (int j = i + 1; j < arrSize; j++) { 
			arr[j - 1] = arr[j]; 
		}
		arrSize--;
	}
	void print() {  //모든 원소 출력
		for (int i = 0; i < arrSize; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
	}
};
