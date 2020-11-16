// C++ program for Merge Sort
#include<iostream>
#include "LinkedList.hpp"

using namespace std;

void insertSort( int arr[],int n) {
    for (int unsorted = 1; unsorted < n; unsorted++) {

        int nextItem = arr[unsorted];
        int loc = unsorted;

        while ((loc > 0) && (arr[loc - 1] > nextItem)) {
            arr[loc] = arr[loc - 1];
            loc--;
        }
            arr[loc] = nextItem;

        }
    }

void printArray(int A[], int size)
{
    for(int i = 0; i < size; i++)
        cout << A[i] << " ";
}

// Driver code
int main()
{
    LinkedList <int> a; // test obj

    a.insert(0,1);
    a.insert(1,2);
    a.insert(2,3);
    //std::cout<< a.getLength() << std::endl;
    std::cout<<a.getEntry(0) << std::endl;
    a.invert();
    std::cout<<a.getEntry(0) << std::endl;
    a.rotate(3);
    std::cout<<a.getEntry(0) << std::endl;


//list.rotate(2);
//std::cout << list.getHeadPtr();




//
//    int arr[] = { 12, 11, 13, 5, 6, 7 };
//    int arr_size = sizeof(arr) / sizeof(arr[0]);
//
//    cout << "Given array is \n";
//    printArray(arr, arr_size);
//
// insertSort(arr, arr_size);
//
//    cout << "\nSorted array is \n";
//    printArray(arr, arr_size);
//    return 0;
}

// This code is contributed by Mayank Tyagi
