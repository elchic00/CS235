/****************************************************************************************************************************
Title          :   Sorter.cpp
Auhor          :   Nigel Ferrer
Modified By    :   Andrew Alagna
Description    :   implementation file of an integer array container class that
                   contains implementations of some sorting algorithms
Dependencies   :   Sorter.hpp
****************************************************************************************************************************/

#include "Sorter.hpp"
using namespace std;

//Default constructor
Sorter::Sorter(array_type type, size_t array_size, int *arr) : type_(type), SIZE_(array_size), values_(arr) {
}

/**************************** Selection Sort ****************************/
/**
 @post Gets the position of the min or max element in array arr.
 @param arr: the array
 @param from: the beginning arr
 @param to: the end of arr
 @param comparator to decide order of sorting
 @return the position of the min or max element in the range a[from]...a[to]
 */
template<typename Comparator>
int Sorter::getPosOfMinOrMax(int arr[], int from, int to, const Comparator &comp) {
    int min_or_max = from;
    for (int i = from + 1; i <= to; i++) {
        if (comp(arr[i], arr[min_or_max])) {
            min_or_max = i;
        }
    }
    return min_or_max;
}

/**
 @post Sorts an array in order (determined by comparator) using selection sort algorithm.
 @param arr - array to be sorted
 @param size is the size of array to be sorted
 @param comparator to decide order of sorting
 @return the number of swaps made by the algorithm
 */
template<typename Comparator>
int Sorter::selectionSort(int arr[], size_t size, const Comparator &comp) {
    for (int i = 0; i < size; i++) {
        // Find position of the min_or_max
        int min_or_max = getPosOfMinOrMax(arr, i, static_cast<int>(size - 1), comp);
        
        // Swap next element with min_or_max
        std::swap(arr[i], arr[min_or_max]);
        if (comp(arr[i], arr[min_or_max])) {
            selectionCount_++;
        }
    }
    return selectionCount_;
}


/************************************************************************/

/**************************** Insertion Sort ****************************/
/**
 @post Sorts an array in given order from comparator  using insertion sort.
 @param arr: the array to sort
 @param size: the size of arr
 @param comparator used to decide order of arrangment
 @return the number of swaps
 */
template<typename Comparator>
int Sorter::insertionSort(int arr[], size_t size, const Comparator &comp) {
    for (int i = 1; i < size; i++) {

        int key = arr[i];
        int j = i - 1;

        /* Move elements of arr that are greater than key forward by one pos. */
        while (j >= 0 && !comp(arr[j], key)) {
            arr[j + 1] = arr[j];
            insertionCount_++; //count # of swaps
            j--;
        }
        // Insert the element
        arr[j + 1] = key;
    }
    return insertionCount_;
}
/************************************************************************/

/****************************** Merge Sort ******************************/
/**
 @post Merges two subarrays.
 @param arr: the array to be sorted
 @param from: the beginning of arr
 @param mid: the end of the first half of arr
 @param to: the end of the second half of arr
 @param comparator to decide order of elements
 ** I used code from the geeksforgeeks website given to us in the project resources **
 */
template<typename Comparator>
void Sorter::merge(int arr[], int from, int mid, int to, const Comparator &comp) {
    int i = to - from + 1; // Size of the range to be merged
    // Merge both halves into arr temporary array temp_arr
    int *temp_arr = new int[i];

    int n1 = from;
    // Next element to consider in the first half
    int n2 = mid + 1;
    // Next element to consider in the second half
    int j = 0; // Next open position in temp_arr

    // Compare elements in subarray for merging then move the smaller element into temp_arr
    while (n1 <= mid && n2 <= to) {
        if (comp(arr[n1], arr[n2])) //less than
        {
            mergeCount_++;
            temp_arr[j] = arr[n1];
            n1++;

        } else {
            mergeCount_++;
            temp_arr[j] = arr[n2];
            n2++;

        }
        j++;
    }
    // Copy remaining entries of the first half of arr
    while (n1 <= mid) {
        mergeCount_++;
        temp_arr[j] = arr[n1];
        n1++;
        j++;
    }
    // Copy remaining entries of the second half of arr
    while (n2 <= to) {
        mergeCount_++;
        temp_arr[j] = arr[n2];
        n2++;
        j++;
    }
    // Copy back from temp_arr
    for (j = 0; j < i; j++) {
        arr[from + j] = temp_arr[j];
    }
    delete[] temp_arr;
}
/**
 @return the number of swaps made in mergesort
 @param arr: the array
 @param from: the beginning of arr
 @param to: the end of arr
 @param comparator to decide order of sorting


 of arr to be sorted */
template<typename Comparator>
int Sorter::mergeSort(int arr[], int from, int to, const Comparator &comp) {
    if (from >= to)
        return 0;
    int mid = (from + to) / 2;
    // Sort the first and the second half with recursion, then merge them together in order.
    mergeSort(arr, from, mid, comp);
    mergeSort(arr, mid + 1, to, comp);
    merge(arr, from, mid, to, comp);
    return mergeCount_;
}
// /************************************************************************/

/************************************************************************/

void Sorter::runSorts(sort_order order) {

    int selectionValues[SIZE_];
    int insertionValues[SIZE_];
    int mergeValues[SIZE_];
    int quickValues[SIZE_];

    if (type_ == RANDOM) {
        srand(static_cast<unsigned>(time(0)));
        for (int i = 0; i < SIZE_; i++) {
            selectionValues[i] = rand() % 100;
            insertionValues[i] = rand() % 100;
            mergeValues[i] = rand() % 100;
            quickValues[i] = rand() % 100;
        }
    } else {
        for (int i = 0; i < SIZE_; i++) {
            selectionValues[i] = values_[i];
            insertionValues[i] = values_[i];
            mergeValues[i] = values_[i];
            quickValues[i] = values_[i];
        }
    }

    // Selection Sort Display
    std::cout << "******** Selection Sort ********\nOriginal Array:\n";
    displayArr(selectionValues);
    if (order == INCREASING) {
        selectionSort(selectionValues, SIZE_, std::less<int>());
    } else {
        selectionSort(selectionValues, SIZE_, std::greater<int>());
    }
    std::cout << "\nSorted Array:\n";
    displayArr(selectionValues);
    std::cout << "\nNumber of swaps: " << selectionCount_ << "\n********************************\n\n";

    // Insertion Sort Display
    std::cout << "\n******** Insertion Sort ********\nOriginal Array:\n";
    displayArr(insertionValues);
    if (order == INCREASING) {
        insertionSort(insertionValues, SIZE_, std::less<int>());
    } else {
        insertionSort(insertionValues, SIZE_, std::greater<int>());
    }
    std::cout << "\nSorted Array:\n";
    displayArr(insertionValues);
    std::cout << "\nNumber of swaps: " << insertionCount_ << "\n********************************\n\n";

    // Merge Sort Display
    std::cout << "\n********** Merge Sort **********\nOriginal Array:\n";
    displayArr(mergeValues);
    if (order == INCREASING) {
        mergeSort(mergeValues, 0, SIZE_ - 1, std::less<int>());
    } else {
        mergeSort(mergeValues, 0, SIZE_ - 1, std::greater<int>());
    }
    std::cout << "\nSorted Array:\n";
    displayArr(mergeValues);
    std::cout << "\nNumber of comparisons: " << mergeCount_ << "\n********************************\n\n";

}

void Sorter::displayArr(const int array[]) const {
    for (size_t i = 0; i < SIZE_; i++) {
        std::cout << array[i];
        (i < SIZE_ - 1) ? (cout << " ") : (cout << "\n");
    }
}