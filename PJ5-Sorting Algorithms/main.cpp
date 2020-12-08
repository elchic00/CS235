#include <iostream>
#include "Sorter.hpp"

using namespace std;

int main() {


    int arr[10] = {0 ,3, 8, 10, 15, 25, 55, 61, 79, 82};
    Sorter sorter_obj(PREDETERMINED, 10, arr);
    //sorter_obj.selectionSort(arr, 5, std::less<int>()); //comparator is less
    //sorter_obj.insertionSort(arr,5,std::less_equal<int>());
    //sorter_obj.mergeSort(arr,0,4,std::less_equal<int>());
    //sorter_obj.quickSort(arr,0,4,std::greater_equal<int>());
    sorter_obj.runSorts(DECREASING);

    int arr1[10] = {3, 61, 82, 79, 15, 0, 10, 8, 25, 55};
    Sorter sorter_obj1(PREDETERMINED, 10, arr1);
    sorter_obj1.runSorts(INCREASING);

//    abc.runSorts(INCREASING);
//    abc
//
//
//
//    Sorter sorter_obj2(RANDOM, size);

}