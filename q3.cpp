#include <string>
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::getline;
using std::setprecision;
#include <math.h>
// # define M_PI  3.14159265358979323846 

int main(){
    unsigned int cuts = 0; //number of total slices = cuts *2
    unsigned int slices = 0;
    double radius = 0;
    double cake_area_max = 0;
    double area_count = 0;


    double angle1 = 0;
    double angle2 = 0;
    double between = 0;
    // double angle_count = 0;

    cin >> cuts >> slices >> radius;
    if(cuts > pow(10,5)){
        return 1;
    }
    if (slices > 2*cuts)
    {
        return 1;
    }
    if (radius > 1000 || radius < 0)
    {
        return 1;
    }
    
    double circle_area = radius*radius*3.14159265358979323846; //pirsquared
    // double* angles = new double[cuts*2];

    double* slices_area =  new double[cuts*2];
    //so the angle can never exceed 
    //we will iterate through first half, and then we will have to take consequtive slices...
    unsigned int j = 0;
    // while (cin >> angle2)
    // {
    //     between = angle2 - angle1;
    //     if (between != 0)
    //     {
    //         slices_area[j] = (between/360) * circle_area; //assigning value to slices_area
    //         j++;
    //     }
    //     // angle_count += between;

    //     // if (i == cuts - 1 && angle_count < 180) //we have reached the end and it is not 180
    //     // {
    //     //     /* code */
    //     // }
        
    //     //reassigning values
    //     angle1 = angle2;
    //     // if (j >= cuts)
    //     // {
    //     //     break;
    //     //     return 1;
    //     // }
        
    // }
    // //doing last

    // between = angle2 - angle1;
    // if (between != 0)
    // {
    //     slices_area[j] = (between/360) * circle_area; //assigning value to slices_area
    //     j++;
    // }
    
    for (unsigned int i = 0; i <= cuts; i++)
    {
        if (i != cuts)
        {
            cin >> angle2;
        }
        else{
            angle2 = 180;
        }
        

        between = angle2 - angle1;
        if (between != 0)
        {
            slices_area[j] = (between/360) * circle_area; //assigning value to slices_area
            j++;
        }
        // angle_count += between;

        // if (i == cuts - 1 && angle_count < 180) //we have reached the end and it is not 180
        // {
        //     /* code */
        // }
        
        //reassigning values
        angle1 = angle2;
        
    }
    
    for (unsigned int i = cuts; i < cuts * 2; i++)
    {
        slices_area[i] = slices_area[i%cuts];
    }
    //initializing max cake val...
    for (unsigned i = 0; i < slices; i++)
    {
        area_count += slices_area[i];
    }
    
    cake_area_max = area_count;
    area_count = 0;

    for (unsigned int i = 1; i < (cuts*2) ; i++)
    {
        for (unsigned int j = i; j < i + slices; j++)
        {
            area_count += slices_area[i];
        }

        if (area_count > cake_area_max)
        {
            area_count = cake_area_max;
        }

        area_count = 0;
        
    }
    

    //maximize cake, calculate as ou iterate through the cake to find out the max area...
    cout << setprecision(10) << cake_area_max << endl;

    delete [] slices_area;
    return 0;
}