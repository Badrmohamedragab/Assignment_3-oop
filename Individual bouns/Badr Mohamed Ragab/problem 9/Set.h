#ifndef PB9_SET_H
#define PB9_SET_H

#include<iostream>
#include<vector>
#include<set>
#include <algorithm>
using namespace std;

template<class T>
class Set {
private:
    vector <T> vec;
public:
    Set(initializer_list<T>NewSet) : vec(NewSet) {};
    void add(T item)
    {
        for (int i = 0; i < vec.size(); ++i) {
            if(item == vec[i])
            {
                return;
            }
        }
        vec.push_back(item);
    }

    void Remove(T item)
    {
        if(count(vec.begin(), vec.end(), item) !=0) {
            vec.erase(remove(vec.begin(), vec.end(), item));
        }
        else {
            cout << "The item not found!" << endl;
        }
    }
    int size()
    {
        return vec.size();
    }
    bool operator==(const Set &s)
    {
        for (int i = 0; i < s.vec.size(); ++i) {
            if(vec[i] == s.vec[i])
                continue;
            else
                return false;
        }
        return true;
    }
    bool operator!=(const Set &s)
    {
        for (int i = 0; i < s.vec.size(); ++i) {
            if(vec[i] != s.vec[i])
                return true;
        }
        return false;

    }
    bool find(T ele)
    {
        for (int i = 0; i < vec.size(); ++i) {
            if(vec[i] == ele)
                return true;
        }

    }

    T* begin()
    {
        T *arr = new T [vec.size()];
        for (int i = 0; i < vec.size(); ++i) {
            arr[i] = vec[i];
        }
        return arr;
    }
    friend ostream & operator <<(ostream & out, Set<T> & MySet){
        out << "[" ;
        for (int i = 0; i < MySet.size(); ++i) {
            if (i == MySet.size() - 1) {
                out << MySet.vec[i] ;
            }
            else{
                out << MySet.vec[i] << ", " ;
            }
        }
        out << "]" ;
        return out ;
    }

};


#endif //PB9_SET_H
