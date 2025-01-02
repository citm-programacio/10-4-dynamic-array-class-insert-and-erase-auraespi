#include <iostream>
#include <string>

using namespace std;

class DynamicArray {
private:
    int size, capacity;
    string* array;

    void resize() {
        capacity *= 2;
        string* newArray = new string[capacity];
        for (int i = 0; i < size; i++) {
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
    }

public:
    DynamicArray(int initialCapacity = 10) {
        size = 0;
        capacity = initialCapacity;
        array = new string[capacity];
    }

    ~DynamicArray() {
        delete[] array;
    }

    bool insert(string newElement, int position) {
        if (position < 0 || position > size) {
            return false; 
        }
        if (size == capacity) {
            resize();
        }
        for (int i = size; i > position; i--) {
            array[i] = array[i - 1];
        }
        array[position] = newElement;
        size++;
        return true;
    }

    bool remove(int position) {
        if (position < 0 || position >= size) {
            return false; 
        }
        for (int i = position; i < size - 1; i++) {
            array[i] = array[i + 1];
        }
        size--;
        return true;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    DynamicArray myArray;

    myArray.insert("zero", 0);
    myArray.insert("one", 1);
    myArray.insert("two", 2);
    myArray.insert("three", 3);
    myArray.insert("four", 4);

    cout << "Array after inserting elements: ";
    myArray.print();

    myArray.remove(2); 

    cout << "Array after removing element at index 2: ";
    myArray.print();

    myArray.insert("new", 2);

    cout << "Array after inserting 'new' at index 2: ";
    myArray.print();

    return 0;
}
