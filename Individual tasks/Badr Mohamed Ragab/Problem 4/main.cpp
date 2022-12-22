#include<iostream>
#include<vector>
using namespace std;
vector<string> lights= {"RED", "GREEN"};
vector<string> vec;
int counter = 1;
void traffic(int n, char check_yellow, int i = 0)
{
    if(i == n)
    {
        cout<<counter++<<" -> ";
        for (int j = 0, k = 1; j < vec.size(); ++j, k++) {
           cout<<k<<"-"<<vec[j]<<" ";
        }
        cout<<endl;
        return;
    }
    for (int j = 0; j < lights.size(); ++j) {
        vec.push_back(lights[j]);
        traffic(n, check_yellow, i + 1);
        vec.pop_back();
    }


}
int main()
{
    int num;
    char Yellow_Existence;
    cout<<"Enter the number of traffic lights-->";
    cin>>num;
    here:
    cout<<"Do you want a YELLOW light in countries(Y-yes - N-No )-->";
    cin>>Yellow_Existence;

    if(Yellow_Existence== 'Y') {
        lights.emplace_back("YELLOW");
    }
    if(Yellow_Existence== 'Y'|| Yellow_Existence== 'N')
        traffic(num,Yellow_Existence);
    else
    {
        cout<<"Error!"<<endl;
        goto here;
    }

}