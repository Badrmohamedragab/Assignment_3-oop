# include <iostream>
# include <fstream>
# include <map>
# include <iomanip>

using namespace std ;

void Edit(string & Word){
    transform(Word.begin(), Word.end(), Word.begin(), ::tolower) ;
    Word.erase(remove_if(Word.begin(), Word.end(), ::isdigit), Word.end()) ;
    Word.erase(remove_if(Word.begin(), Word.end(), ::ispunct), Word.end()) ;
}

void Fill_Map(map <string, int> & MyMap, string & Name)
{
    fstream File(Name) ;
    string line ;

    while (getline(File, line)){
        Edit(line) ;

        if (MyMap.find(line) == MyMap.end()){
            MyMap.insert({line, 1}) ;
        }
        else{
            auto Itr = MyMap.begin() ;
            while (Itr++ != MyMap.end()){
                if (Itr->first == line){
                    Itr->second++ ;
                }
            }
        }
    }
    File.close() ;
}

int main() {
    map<string, int> MyMap ;
    string Name ;

    cout << "Hello User " << char(2) << "\nPlease Enter the Name of file\n====>" ;
    getline(cin, Name) ;
    Fill_Map(MyMap, Name) ;

    cout << "\n" << setw(31) << setfill('-') << "-" ;
    cout << "\n" << left << setw(13) << setfill(' ') << "Word" << "|" ;
    cout << right << setw(17) << setfill(' ') << "Frequency" ;
    cout << "\n" << setw(31) << setfill('-') << "-" << "\n" ;

    for (auto & i : MyMap) {
        cout << left << setw(13) << setfill(' ') << i.first << "|" ;
        cout << right << setw(17) << setfill(' ') << i.second ;
        cout << "\n" ;
    }

    cout << setw(31) << setfill('-') << "-" << "\n" ;
    cout << "If you want to get the frequency of a word Enter (Y)\n===>" ;
    string Word ;
    cin >> Word ;

    if (Word != "Y"){
        exit(0) ;
    }

    cout << "Enter the Word\n===>" ;
    cin >> Word ;
    Edit(Word) ;

    auto Place = MyMap.find(Word) ;
    cout << "The Word -> " << Place->first << ", and its Frequency -> " << Place->second << endl ;

    return 0;
}