# include <iostream>
# include <fstream>
# include<vector>

using namespace std ;


bool find_word(string word)
{
    fstream file ;
    file.open("dictionary.txt" , ios :: in); 

    while(!file.eof())
    {
        string save = "" ;
        file >> save ;
        if (save == word)
        {
            file.close() ;
            return true ;
        }
    }

    file.close() ;
    return false ;
}




bool useful_string(string word , vector<string> target , int size = 0  ) 
{

    if (size   >=  word.size() )
    {
        for (auto i : target) 
        {
            cout << i << " " ;
        } 
        cout << endl ;

        
    }
    string initial = "" ;

    for ( ; size < word.size() ; size ++)
    {
        initial += word[size] ;
        

        if (find_word(initial))
        {
            target.push_back(initial) ;
            
           if(useful_string(word , target , size+1) ) // recursive case
           {
                return true ;
           }
           
          target.pop_back() ; // backtracking case
        
        } 
    }
    return false ;
}






int main()
{
    vector<string> target ;

    useful_string("Iwearmyshoes" , target) ;
}