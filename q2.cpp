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
    unsigned int tot_num_paintings = 0;
    unsigned int seq_size = 0;
    string painting_list = "";
    string pass_back = "";
    // string everything = "";
    // istringstream file;
    istringstream inSS; //string buffer to read in values...

    
    unsigned int pass_seq_size = 0;
    // unsigned int m_seq_size = 0;
    string painting = "";
    string sequence = "";
    // string m_seq = "";
    
    unsigned int tot_paintings_so_far = 0;
    

    //reading in the first two inputs...
    // getline(cin, everything);
    // file.str(everything);
    cin >> tot_num_paintings >> seq_size;

    cin >> painting;
    painting_list.append(painting);
    for (unsigned int i = 0; i < tot_num_paintings-1; i++)
    {
        cin >> painting;
        painting.insert(0, " ");
        // painting_list.insert(painting_list.end(), painting.size(), painting);
        painting_list.append(painting);
    }
    
    // getline(cin, painting_list);
    // cin >> n_seq;
    // getline(cin, n_seq);
    // cin >> m_seq;
    // getline(cin, m_seq);
    for (unsigned int i = 0; i < seq_size; i++)
    {
        cin >> pass_seq_size;
        tot_paintings_so_far += pass_seq_size;
        getline(cin, sequence);
        sequence.erase(0,1);
        pass_back.append(sequence);
        //removing the values from the sequence...
        inSS.str(sequence);
        for (unsigned int i = 0; i < pass_seq_size; i++)
        {

            inSS >> painting;
            painting_list.replace(painting_list.find(painting), painting.size(), "");
        }
        pass_back.append(" ");
        inSS.clear();
        
    }

    inSS.str(painting_list);
    for (unsigned int i = 0; i < tot_num_paintings-tot_paintings_so_far; i++)
    {

        inSS >> painting;
        if (i > 0)
        {
            painting.insert(0, " ");
        }
        

        pass_back.append(painting);
    }
    
    cout << pass_back << endl;

    return 0; 
}