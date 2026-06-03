class DynamicArray {
private:
    int size = 0;
    int cap = 0;
    int* arr;
public:
    DynamicArray(int capacity) {
        cap = capacity;
        arr = new int[capacity];
        size = 0;
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if (cap == size)
        {
            resize();
        }
        arr[size] = n;
        size++;
    }

    int popback() {
        if (size > 0)
        {
        size--;
        }
        return arr[size];
    }

    void resize() {
        cap *= 2;
        int* newArr = new int[cap];
        for (int i = 0 ; i < size; i++)
        {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return cap;
    }
};
