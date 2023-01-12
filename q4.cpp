#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::getline;
using std::istringstream;


int main(){
    int n = 0;
    int m = 0;
    string pass = "";
    string pass_comparison = "";
    bool YES = true;
    

    cin >> n >> m;
    // checking if first iteration is valid...
    cin >> pass;
    int hash_count = 0;
    int hash_position = -1;
    // int before_hash_water = 0;
    // int compare_water = 0;


    for (int i = 0; i < m; i++)
    {
        if (pass.at(i) == '#' && hash_position == -1)
        {
            hash_count++;
            hash_position = i;
        }
        if (hash_count > 1)
        {
            YES = false;
            break;
        }
    }
    //then check hash position...
    if (YES && hash_position != m/2)
    {
        YES = false;
    }
    
    
    if (YES)
    {
        for (int i = 1; i < n; i++) //then iterate through to see if hash matches up!!
        {
            cin >> pass_comparison;
            if(pass != pass_comparison){
                YES = false;
                break;
            }
        }
    }

    if (YES)
    {
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    
    

    



    return 0;
}