//#include <iostream>
//using namespace std;
////int add(int value)
////{
////    return value;
////}
////int add(int head, int arg1)
////{
////    return head + add(arg1);
////}
////int add(int head, int arg1, int arg2)
////{
////    return head + add(arg1 + arg2);
////}
////int add(int head, int arg1, int arg2, int arg3)
////{
////    return head + add(arg1 , arg2, arg3);
////}
////int add(int head, int arg1, int arg2, int arg3, int arg4)
////{
////    return head + add(arg1 , arg2, arg3, arg4);
////}
////template <class t>
////t add(t value)
////{
////    return value;
////}
////
////template <class t, class...t2>
////t add(t head , t2...arg)
////{
////    return head +add(arg...);
////}
//#include<iostream>
//#include<vector>
//using namespace std;
//template <class T>
//class myvector
//{
//private:
//    int size, capacity;
//    T* data;
//public:
//    myvector(int cap = 2)
//    {
//        capacity = cap;
//        size = 0;
//        data = new T [capacity];
//    }
//    ~myvector()
//    {
//        delete [] data;
//    }
//    T& operator[] (int idx)
//    {
//        if(idx > size-1 || idx<0)
//        {
//            cerr<<"out of range"<<endl;
//            exit(-1);
//        }
//        return data[idx];
//    }
//    void push_back(T item)
//    {
//        if(size < capacity)
//        {
//            data[size++] = item;
//
//        }
//        else
//        {
//            cout<<"resize to "<<capacity*2<<"\n";
//            T* new_data = new T[capacity * 2];
//            for (int i = 0; i < size; ++i) {
//                new_data[i] = data[i] ;
//            }
//            delete[] data;
//            data = new_data;
//            new_data = nullptr;
//            data[size++] = item;
//
//        }
//    }
//    int getSize()
//    {
//        return size;
//    }
//    T& operator=(const T& other)
//    {
//        for (int i = 0; i < size; ++i) {
//            if(this != &other){
//                delete[] data;
//                size = other.size;
//                capacity = other.capacity;
//                data = new T[capacity];
//                for(int i = 0; i < other.size; i++){
//                    data[i] = other.data[i];
//                }
//            }
//            else{
//                cout << "Cannot delete self" << endl;
//            }
//        }
//        }
//};
//
//
//
//
//int main() {
//    myvector <string> vec(1);
//    vec.push_back((string) "Hello");
//    vec.push_back((string) "Neehaw");
//    vec.push_back((string) "Bonjour");
//    vec.push_back((string) "Guten Tag");
//    vec.push_back((string) "Salam Alykum");
//    vec.push_back((string) "Hola");
//    vec[0] = "Hellooooo";
//
//    for(int i = 0; i < vec.getSize(); i++){
//        cout << vec[i] << endl;
//    }
//    cout << endl << endl;
//    myvector <string> vec2;
//    vec2 = vec;
//    vec2[0] = "Salam Alykum231";
//
//    for(int i = 0; i < vec2.getSize(); i++){
//        cout << vec2[i] << endl;
//    }
//
//    return 0;
//}
// A program to demo a template vector class
// Author: Yusef Elzayat
//// 13 Nov 2022
//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//template <class T>
//class BOVector{
//private:
//    int size, capacity;
//    T* data;
//public:
//    BOVector(int cap = 2){
//        capacity = cap;
//        size = 0;
//        data = new T[capacity];
//    }
//
//    T& operator[](int indx){
//        if(indx > size-1){
//            cout << "An error has occured, index out of range." << endl;
//            exit(-1);
//        }
//        return data[indx];
//    }
//    void push_back(T item){
//        if(size < capacity){
//            data[size++] = item;
//        }
//        else{
//            cout << "Resizing to " << capacity*2 << endl;
//            T* newdata = new T[capacity*2];
//            capacity *= 2;
//
//            for(int i = 0; i < size; i++){
//                newdata[i] = data[i];
//            }
//            delete[] data;
//            data = newdata;
//            newdata = nullptr;
//            data[size++] = item;
//        }
//    }
//    int getSize(){
//        return size;
//    }
//    T& operator=(const T& other){
//        if(this != &other){
//            delete[] data;
//            size = other.size;
//            capacity = other.capacity;
//            data = new T[capacity];
//            for(int i = 0; i < other.size; i++){
//                data[i] = other.data[i];
//            }
//        }w
//        else{
//            cout << "Cannot delete self" << endl;
//        }
//    }
//
//
//
//};
//
//int main(){
//    BOVector <string> vec(1);
//    vec.push_back((string) "Hello");
//    vec.push_back((string) "Neehaw");
//    vec.push_back((string) "Bonjour");
//    vec.push_back((string) "Guten Tag");
//    vec.push_back((string) "Salam Alykum");
//    vec.push_back((string) "Hola");
//    vec[0] = "Hellooooo";
//
//    for(int i = 0; i < vec.getSize(); i++){
//        cout << vec[i] << endl;
//    }
//    cout << endl << endl;
//    BOVector <string> vec2;
//    vec2 = vec;
//    vec2[0] = "Salam Alykum231";
//
//    for(int i = 0; i < vec2.getSize(); i++){
//        cout << vec2[i] << endl;
//    }
//}
//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//template<class t1>
//
//void sort_elements(vector<t1> vec) {
//    sort(vec.begin(), vec.end());
//    for (int i = 0; i < vec.size(); ++i) {
//            cout<<vec[i]<<" ";
//    }
//}
//template< >
//void sort_elements(vector<double> vec) {
//    sort(vec.begin(), vec.end());
//    cout << "double" << endl;
//    for (int i = 0; i < vec.size(); ++i) {
//        cout << vec[i]<<" ";
//    }
//}
//
//int main() {
//    vector<int> vec = {3, 4, 5};
//
//    vector<double> vec2 = {2.2, 3.2, 4.3};
//
//    vector<float> vec3 = {6.1, 2.2, 1.3, 7.2};
//    sort_elements(vec);
//    cout<<endl;
//    cout<<endl;
//    sort_elements(vec2);
//    cout<<endl;
//    cout<<endl;
//    sort_elements(vec3);
//
//
//
//    return 0;

#include <bits/stdc++.h>

using namespace std;

template <class T>
class BOVector{
private:

    int size{};
    int capacity{};
    T* data;

public:


    typedef T* iterator;

    BOVector(int cap = 2){
        capacity = cap ;
        size = 0;
        data = new T[capacity];
    }

    ~BOVector(){
        delete[] data;
    }

    T& operator[](int indx){

        if(indx > size-1){
            cout << "An error has occured, index out of range." << endl;
            exit(-1);

        }
        return data[indx];
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

    BOVector(T arr[], int n)
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
            cout<<"Resizing-> "<<capacity<<endl;
            T* newdata = new T[capacity];

            for(int i = 0; i < size; i++){
                newdata[i] = data[i];
            }
            delete[] data;
            data = newdata;
            data[size++] = item;
        }

    }
    iterator begin()
    {
        return data;
    }

    iterator end()
    {
        return data + size;
    }

    T pop_back()
    {
        if(size == 0)
        {
            cout<<"empty vector!"<<endl;
        }
        else {
            size--;
        }
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
        if(this->size > v.size)
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
        if(this->size < v.size)
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
        out<<"]\n";
        return out;

    }

};


int main() {
    BOVector<int> vec1;
    BOVector<int> vec2;


    vec1.push_back(10);
    vec1.push_back(11);

    vec2.push_back(10);
    vec2.push_back(9);

    if(vec1 > vec2)
        cout<<"bigger";
    else if(vec1 < vec2)
        cout<<"smaller";



    return 0;
}