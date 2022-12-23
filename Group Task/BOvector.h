#ifndef MAIN_CPP_BOVECTOR_H
#define MAIN_CPP_BOVECTOR_H

#include<iostream>
#include<vector>
#include<exception>
using namespace std;

template <class T>
class BOVector {
private:

    int size{};
    int capacity{};
    T *data;

public:

    typedef T *iterator;
    BOVector(int cap = 2){
        capacity = cap ;
        size = 0;
        data = new T[capacity];
    }

    ~BOVector(){
        delete[] data;
    }

    T& operator[](int indx){
        try{
            if (indx > size - 1 || indx < 0) {
                throw out_of_range("out_of_range");
            }

            return data[indx];
        }
        catch(out_of_range &e)
        {
            cerr<<"("<<e.what()<<") Exception was thrown"<<endl;
            exit(-1);
        }
    }



    T& operator=(const BOVector& other){
        if(this != &other){
            delete[] data;
            size = other.size;
            capacity = other.capacity;
            data = new T[capacity];
            for(int i = 0; i < other.size; i++){
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    BOVector (const  BOVector& vec) //copy constructor
    {
        size = vec.size;
        this->data = new T[capacity];

        for (int i = 0; i < size; ++i) {

            this->data[i] = vec.data[i];
        }
    }


    T& operator=(const BOVector&& other_vec) noexcept //move assignment
    {
        if(this != &other_vec){
            delete [] data;
            data = other_vec.data;
            size = other_vec.size;
            capacity = other_vec.capacity;
            other_vec.data = nullptr;
            other_vec.size = 0;
            other_vec.capacity = 0;
        }
        return *this;
    }

    BOVector(T* arr, int n)
    {
        this->size = n;
        this->capacity = n;
        data = new T [capacity];
        for (int i = 0; i < n; ++i) {
            this->data[i] = arr[i];
        }
    }

    void push_back(T item){
        if(size < capacity){
            data[size++] = item;
        }

        else{
            if(capacity == 0)
            {
                capacity = 2;
            }

            capacity = capacity*2;
//            cout<<"Resizing-> "<<capacity<<endl;
            T* newdata = new T[capacity];

            for(int i = 0; i < size; i++){
                newdata[i] = data[i];
            }
            delete[] data;
            data = newdata;
            data[size++] = item;
        }

    }
    void pop_back()
    {
        if(size == 0)
        {
            cout<<"empty vector!"<<endl;
        }
        else {
            size--;
        }
    }
    iterator begin()
    {
        return data;
    }

    iterator end()
    {
        return data + this->size-1;
    }


    void erase(iterator itr)
    {
        try{
            if (itr < end() && itr >= begin()) {

                while (itr != end()) {
                    *itr = *(itr + 1);
                    itr++;
                }
                size--;
            }
            else{
                throw invalid_argument("Invalid iterator");
            }
        }
        catch(invalid_argument &e)
        {
            cerr<<"("<<e.what()<<") Exception was thrown"<<endl;
            exit(-1);
        }
    }

    void erase(iterator itr1, iterator itr2)
    {
        try
        {
            if(itr1<itr2) {
                while (itr1 < itr2) {
                    iterator temp = itr1;
                    erase(temp);
                    itr2--;
                }
            } else {
                throw invalid_argument("Invalid iterators");
            }
        }
        catch(invalid_argument &e)
        {
            cerr<<"("<<e.what()<<") Exception was thrown"<<endl;
            exit(-1);
        }
    }

    void insert(iterator itr, T a)
    {
        try {
            if (itr < end() && itr >= begin()) {
                this->push_back(0);
                iterator temp = end();
                while (temp != itr) {
                    *temp = *(temp - 1);
                    temp--;
                }
                *itr = a;
            }
            else if(itr == end())
                push_back(a);
            else {
                throw invalid_argument("Invalid insert");
            }
        }
            catch(invalid_argument &e)
            {
                cerr<<"("<<e.what()<<") Exception was thrown"<<endl;
                exit(-1);
            }


//        if(size == capacity)
//        {
//            int idx ;
//            idx =  itr - this->begin();
//
//            for (int j = this->size -1; j >=idx; --j) {
//                data[j + 1] = data[j];
//            }
//            data[idx]  = a;
//            size++;
//
//            capacity = capacity*2;
//            cout<<"Resizing-> "<<capacity<<endl;
//            T* newdata = new T[capacity];
//
//            for(int i = 0; i < size; i++) {
//                newdata[i] = data[i];
//            }
//            data = newdata;
//        }
//        else
//        {
//            int idx;
//            idx = itr - this->begin();
//
//            for (int j = this->size - 1; j >= idx; --j) {
//                data[j + 1] = data[j];
//            }
//            data[idx] = a;
//            size++;
//        }


    }

    int empty()
    {
        if(size == 0)
            return 1;
        else
            return 0;
    }

    int Size() const{
        return size;
    }

    int Capacity() const
    {
        return capacity;
    }
    void resize(int n)
    {
        if(n > this->capacity)
            this->capacity = n;

        this->size = n;

    }
    void clear()
    {
        size = 0;
        capacity = 0;
        this->data = nullptr;
        delete [] data;
    }
    bool operator==(const BOVector<T>& vec)
    {
        if(this->size != vec.size)
            return false;
        else{
            for (int i = 0; i < this->size; ++i) {
                if(vec.data[i] == data[i])
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
            return true;

        }
    }
    bool operator< (const BOVector<T>& v) {
        int min = this->size;
        if (v.size < min) {
            min = v.size;
        }

        for (int i = 0; i < min; i++) {
            if (this->data[i] < v.data[i])
                return true;

            else if (this->data[i] > v.data[i])
                return false;

        }
        if(this->size >= v.size)
            return false ;

        else
            return true;
    }



    bool operator> (const BOVector<T>& v) {
        int min = this->size;
        if (v.size > min) {
            min = v.size;
        }

        for (int i = 0; i < min; i++) {
            if (this->data[i] > v.data[i])
                return true;

            else if (this->data[i] < v.data[i])
                return false;
        }
        if(this->size <= v.size)
            return false ;

        else
            return true;
    }


    friend ostream& operator << (ostream& out, BOVector<T>&vec)
    {
        out<<"[";
        for (int i = 0; i < vec.size; ++i) {
            if(i == vec.size-1) {
                out << vec.data[i];
            }
            else {
                out << vec.data[i] << ", ";
            }
        }
        out<<"]";
        return out;

    }


};
#endif //MAIN_CPP_BOVECTOR_H
