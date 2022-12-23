#include "Set.h"

int main() {
    cout << "----------< int Set >----------\n" ;
    Set<int> set1 = {1, 2, 3, 5, 6, 10} ;
    set1.add(5) ;
    set1.add(6) ;
    set1.add(4) ;
    set1.add(5) ;

    cout << set1 << endl ;

    set1.Remove(2) ;
    cout << "After removing 2 -> " << set1 << endl ;

    cout << "Size -> " << set1.size() << endl ;

    if (set1.find(10))
        cout << "Yes, 10 is an element :)" << endl ;
    else
        cout << "No" << endl ;

    if (set1.find(-100))
        cout << "Yes" << endl ;
    else
        cout << "No, -100 Not an element :(" << endl ;

    int* arr ;
    arr = set1.begin() ;

    for (int i = 0; i < set1.size(); ++i) {
        cout << *(arr++) << " " ;
    }

    cout << "\n----------< char Set >----------\n" ;

    Set<char> set2 = {'a', 'b', 'c'} ;
    set2.add('a') ;
    set2.add('z') ;
    set2.add('P') ;
    set2.add('b') ;

    cout << set2 << endl ;

    set2.Remove('a') ;
    cout << "After removing a -> " << set2 << endl ;
    cout << "Size -> " << set2.size() << endl ;

    if (set2.find('z'))
        cout << "Yes, z is an element :)" << endl ;
    else
        cout << "No" << endl ;

    if (set2.find('f'))
        cout << "Yes" << endl ;
    else
        cout << "No, f Not an element :(" << endl ;

    char* arr2 ;
    arr2 = set2.begin() ;

    for (int i = 0; i < set2.size(); ++i) {
        cout << *(arr2++) << " " ;
    }

    cout << "\n----------< String Set >----------\n" ;

    Set<string> set3 = {"Mohamed", "Amir", "Badr"} ;
    set3.add("Ali") ;
    set3.add("Mohamed") ;
    set3.add("Ahmed") ;
    set3.add("Ahmed") ;

    cout << set3 << endl ;

    set3.Remove("Ibrahim") ;
    cout << "After Trying to remove Ibrahim -> " << set3 << endl ;
    cout << "Size -> " << set3.size() << endl ;

    if (set3.find("Ahmed"))
        cout << "Yes, Ahmed is an element :)" << endl ;
    else
        cout << "No, Ahmed is not an element :(" << endl ;

    if (set3.find("Ragab"))
        cout << "Yes, Ragab is an element :)" << endl ;
    else
        cout << "No, Ragab Not an element :(" << endl ;

    string *arr3 ;
    arr3 = set3.begin() ;

    for (int i = 0; i < set3.size(); ++i) {
        cout << *(arr3++) << " " ;
    }

}
