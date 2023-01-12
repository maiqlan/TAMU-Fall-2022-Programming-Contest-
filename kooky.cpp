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
    // int n = 0;
    // int l = 0;
    // int r = 0;
    unsigned int number_of_trails = 0;
    // int trail_a = 0;
    // int trail_a0 = 0;    
    // int trail_b = 0;  
    // int trail_b0 = 0;  
    bool YES = true;
    int trail = 0 ;

    cin >> number_of_trails;
    if (number_of_trails % 2 == 1)
    {
        YES = false;
    }

//making dynamic array

    unsigned int* trail_list = new unsigned int[number_of_trails];  

    if (YES)
    {
        for (int i = 0; i < number_of_trails; i++)
        {
            cin >> trail;
            trail_list[i] = trail;
        }
        
        //then the comparision occurs...
        //trying to see if possible to arrange in palindrome sequence...

        int shift_val = 0;
        
        for (int i = 0; i < number_of_trails/2; i++)
        {
            if (trail_list[0] != trail_list[number_of_trails])
            {
                //doing a full shift...
                shift_val = trail_list[0];
                for (size_t i = 0; i < number_of_trails - 1; i++)
                {
                    trail_list[i] = trail_list[i+1];
                }
                trail_list[number_of_trails] = shift_val;

                
                // shift_val = trail_list[j]
            }
            
        }
        
        for (int i = 0; i < number_of_trails/2; i++)
        {
            /* code */
        }
        
        
    }
    
    
    delete[] trail_list;
    

    return 0;
}