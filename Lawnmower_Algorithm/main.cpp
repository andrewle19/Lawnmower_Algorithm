//  Author: Andrew Le
//  andrewle19@csu.fullerton.edu
//  Programming Assignment #1: Lawnmower_Algorithm
//  2/14/17

#include <iostream>
using namespace std;

int main() {
    int n,m = 0; // n- size of the input m-number of swaps
    char *disks; // char pointer to point to dynamica array that stores black and white disk
    
    cout << "Enter the number of single color disks(light or dark)" << endl;
    cin >> n;
    
    
    // dynamically allocate char array
    disks = new char[2*n];
    // set the initial configurations for the disks to alternate
    for(int i= 0; i < n; i++)
    {
        disks[2*i] = 'd';
        disks[2*i+1] = '1';
    }
    
    cout << "Intial configuration: ";
    // print out intial configurations of disks
    for(int i = 0; i < 2*n; i++)
    {
        cout << disks[i];
    }
    cout << endl;
    
    
    // Lawnmover traversal(Left to Right then Right to Left etc..)
    // the c loop is to make the traversal shorter everytime
    // length of traversal is cut everytime a for loop is executed
  
    for (int c = 0; c < n/2+1; c++)
    {
        
        
        // Left to Right Traversal
        for(int i = 2*c ; i < 2*n-2*c-1; i++)
        {
            if(disks[i] != disks[i+1]) // if the disk index i is not equal to the next index we swap
            {
                // swaps the disks array value
                char temp;
                temp = disks[i];
                disks[i] = disks[i+1];
                disks[i+1] = temp;
                m++; // increments the number of swaps
                
            }
            
        }
        // Right to Left Trarversal
        for(int k = 2*n-2*c-2; k > 2*c+1; k--)
        {
            if(disks[k] != disks[k-1]) // if the disk index i is not equal to the next index we swap
            {
                // swaps the disks array value
                char temp;
                temp = disks[k-1];
                disks[k-1] = disks[k];
                disks[k] = temp;
                m++;
            }
        }
    }
    
    
    // prints out sorted array
    cout << "Sorted configuration: ";
    for(int i = 0; i < 2*n; i++)
    {
        cout << disks[i];
    }
    cout << endl;
    
    // prints out number of swaps
    cout << "Number of swaps: " << m << endl;
    
    // delete pointer
    delete[] disks;
    return 0;
}
