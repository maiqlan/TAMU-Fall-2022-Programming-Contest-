#include <string>
// #include 
#include <iostream>
using std::cout;
using std::endl;
// using std::string;
using std::string;
using std::cin;

int main(){
    string L_input;

    cin >> L_input;
    //checking to see if L consists entirely of alpha characters
    // bool alpha = true;
    for (unsigned int i = 0; i < L_input.size(); i++)
    {
        if (!(isalpha(L_input.at(i))))
        {
            // alpha = false;
            return -1;
        }
        

    }

    cout<< "Let's go to " << L_input << "!"<< endl;
    
    return 0;
}