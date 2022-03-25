#include<iostream>
#include<fstream>
using namespace std;

template<class T>
class myHeap {
protected:
    T *arr;
    int capacity;
    int length;

    void swap(int ind1, int ind2)
    {
        T temp = this->arr[ind1];
        this->arr[ind1] = this->arr[ind2];
        this->arr[ind2] = temp;
    }

    void expand()
    {
        T *temp = new T[2 * this->capacity];

        // copying old array elements to new array
        for (int i = 0; i < this->capacity; i++)
            temp[i] = this->arr[i];

        // deleting previous array
        delete[] arr;
        this->capacity *= 2;
        arr = temp;
    }

    void downHeapify(int pi)
    {
        int lci = 2 * pi + 1;
        int rci = 2 * pi + 2;

        int maxIdx = pi;

        if (lci<this->length &&this->arr[lci]> this->arr[maxIdx])
            maxIdx = lci;
        if (rci<this->length &&this->arr[rci]> this->arr[maxIdx])
            maxIdx = rci;

        if (maxIdx != pi)
        {
            this->swap(maxIdx, pi);
            this->downHeapify(maxIdx);
        }
    }

    void upHeapify(int ci)
    {
        int pi = (ci - 1) / 2;

        if (pi >= 0 && this->arr[pi] < this->arr[ci])
        {
            this->swap(pi, ci);
            this->upHeapify(pi);
        }
    }

public:
    myHeap()
    {
        this->capacity = 11;
        this->length = 0;
        this->arr = new T[this->capacity];
    }
    myHeap(T *data, int size)
    {
        this->capacity = size;
        this->length = this->capacity;
        this->arr = new T[this->capacity];

        for(int i = 0; i < this->capacity; i++)
            this->arr[i] = data[i];

        for (int i = this->length - 1; i >= 0; i--) 
            this->downHeapify(i);
    }

    ~myHeap() {
        delete[] this->arr;
    }

};

template<class T>
class my_priority_queue: public myHeap<T> {
public:
    my_priority_queue() {
        this->capacity = 11;
        this->length = 0;
        this->arr = new T[this->capacity];
    }

    my_priority_queue(T *data, int size) {
        this->capacity = size;
        this->length = this->capacity;
        this->arr = new T[this->capacity];

        for (int i = 0; i < this->capacity; i++)
            this->arr[i] = data[i];

        for (int i = this->length - 1; i >= 0; i--)
            this->downHeapify(i);
    }

    T top()
    {
        try
        {
            if (this->length == 0)
                throw "NullPointerException";
            return this->arr[0];
        }
        catch (string s)
        {
            cout << s << endl;
        }

        return NULL;
    }

    void push(T ele)
    {
        if (this->length + 1 == this->capacity)
            this->expand();

        this->arr[this->length] = ele;
        this->length++;
        this->upHeapify(this->length - 1);
    }

    void pop()
    {
        try
        {
            if (this->length == 0)
                throw "NullPointerException";
            else
            {
                // T top = this->arr[0];
                this->swap(0, this->length - 1);
                this->length--;
                this->downHeapify(0);

                // return top;
            }
        }
        catch (string s)
        {
            cout << s << endl;
        }
    }

    bool isEmpty()
    {
        return this->length == 0;
    }

    int size()
    {
        return this->length;
    }
};