// Author:                      Lee Reese
// Assignment Number:           Lab 9
// File Name:                   TT17_L9_Reese.cpp
// Course/Section:              COSC 1337 Section 5      
// Due Date:                    Tue 4/10
// Instructor:                  Thayer

#include <iostream>
#include <iomanip>
#include <random> // needed for Orwell devcpp

using namespace std;

const int TARGET = 123456789;
// This target value will never be found.

// helper functions
bool verifySorted(int[], int);


// The stuff that I made
void radixSort(int[], int);
void heapSort(int[], int);
bool binarySearchArray(int[], int, int, int, int&);


const int testSizes[] = {5000, 10000, 20000, 30000, 40000, 50000, 100000, 0};

// This code helps to automate multiple test runs.

// Call this code as many times as desired to test your sort algorithms.
float testSortAlgorithm(void sortAlgorithm(int [], int), int array[], int arraySize) {
  // This is an interesting function. The first parameter is a "function pointer",
  // It accepts any function that returns a void and has parameters of type: (int [], int)
  // So, the first parameter (in the caller) can be the name of the sort function being tested.
  // This reduces redundant code, because the same sequence of tests are performed on each
  // sort function. (Our textbook does not mention function pointers.)
  
  // fill the array with random, unsorted numbers before sorting it
  for (int index = 0; index < arraySize; index++)
    array[index] = rand();  // initialize array with random values
  int startTime = clock(); // start the test clock
  sortAlgorithm(array, arraySize);  // ALGORITHM UNDER TEST
  int stopTime = clock();  // stop the test clock
  float duration = stopTime - startTime;
  if (!verifySorted(array, arraySize)) cout<< "Error! array not sorted!!!\n";
  return duration;
}

///////////////////////////////////////
//-------SEARCH ALGORITHM TEST-------//
///////////////////////////////////////

float testBinarySearch(int array[], int arraySize) {
  bool found = false; // true if TARGET is found in array
  int foundAt = 0;    // index in array where TARGET was found
  int startTime = clock();
  for (int repeat = 0; repeat < 1000; repeat++) // repeat test 1000 times to increase duration
    found = binarySearchArray(array, 0, arraySize-1, TARGET, foundAt); // ALGORITHM UNDER TEST
  int stopTime = clock();
  int duration = stopTime - startTime;
  return duration/1000.0; // divide duration by 1000 to get time for single search
}

void testAlgorithms(int array[], int arraySize) {
  // This draws a table of results for each algorithm tested.
  const int AlgorithmNameWidth=16;
  const int DurationWidth=10;
  cout << setw (AlgorithmNameWidth) << left << "Algorithm";
  for (int testCount=0; testSizes[testCount]; ++testCount)
    cout << setw(DurationWidth) << right << testSizes[testCount];
  cout << endl << string(AlgorithmNameWidth, '=');
  for (int testCount=0; testSizes[testCount]; ++testCount)
    cout << setw(DurationWidth) << right << " =======";
  
  // Add a loop to call and test your first sort algorithm here
  cout << endl << setw (AlgorithmNameWidth) << left << "radix sort (LSD)";
  for (int testCount=0; (testSizes[testCount] && testSizes[testCount] <= arraySize); ++testCount)
    cout << setw(DurationWidth) << right << testSortAlgorithm(radixSort, array, testSizes[testCount]);
    
  // Add a loop to call and test your second sort algorithm here
  cout << endl << setw (AlgorithmNameWidth) << left << "heap sort";
  for (int testCount=0; (testSizes[testCount] && testSizes[testCount] <= arraySize); ++testCount)
    cout << setw(DurationWidth) << right << testSortAlgorithm(heapSort, array, testSizes[testCount]);
    
  // Add a loop to call and test your search algorithm here
  cout << endl << setw (AlgorithmNameWidth) << left << "binary search";
  for (int testCount=0; (testSizes[testCount] && testSizes[testCount] <= arraySize); ++testCount)
    cout << setw(DurationWidth) << right << testBinarySearch(array, testSizes[testCount]);
  cout << endl;
}

// Useful test to verify that array is really sorted!
bool verifySorted(int array[], int size) {
  // returns true if array is in ascending sorted order, else false.
  for (int i=0; i<(size-1); ++i)
    if (array[i]>array[i+1]) return false;
  return true;
}

int main () {
  // Seed the RNG
  unsigned int seed = time(0);
  srand(seed);

  //A big array
  const int BIGSIZE = 100000;
  int bigArray[BIGSIZE];
  float duration = 0.0; // time in milliseconds

  // Test Radix sort on bigArray
  duration = testSortAlgorithm(radixSort, bigArray, BIGSIZE);
  cout << fixed << setprecision(2);
  cout << "Radix sort (LSD) on bigArray took: "
       << setw(7) << duration << " milliseconds." << endl;

  // Test Heap sort on bigArray
  duration = testSortAlgorithm(heapSort, bigArray, BIGSIZE);
  cout << fixed << setprecision(2);
  cout << "Heap sort on bigArray took: "
       << setw(7) << duration << " milliseconds." << endl;

  //Test Binary search on bigArray
  duration = testBinarySearch(bigArray, BIGSIZE);
  cout << "Binary search  of bigArray took: "
       << setw(7) << duration << " milliseconds.\n\n";

  // Test the algorithms on ever longer list of numbers.
  testAlgorithms(bigArray, BIGSIZE);
  cout << endl;

  return 0;
} // end of main

//////////////////////////////////////
//-------FIRST SORT ALGORITHM-------//
//////////////////////////////////////

// Returns the largest value in the array
int getMax(int array[], int size) {
  int max = array[0];

  for (int i = 1; i < size; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}

// A function to do a counting sort of the array.
// The elements of the array are sorted in ascending order based
// on the place value represented by exp.
// e.g. If exp = 10, the digits will be sorted by the value of the 10's
// place. (902 < 713 < 836 = 133)

void countSort(int array[], int size, int exp) {
  int output[size];
  int i, count[10] = {0};
  
  // Note: (array[i]/exp) % 10 returns the digit in the exp's place of array[i]

  // Store number of occurences for each digit [0-9] in count.
  // e.g. If array[3] == 4, then there are for numbers in array[] with a 3
  // in the exp's place
  for (i = 0; i < size; i++)
    count[ (array[i]/exp) % 10 ]++;

  // Change count[i] so that it will store the final position of the digit
  // in output. (+1)
  // e.g. If count[3] == 4, output[4-1] will contain the final occurence of
  // a '3' value in array[i]. This makes more sense when you see the next loop
  for (i = 1; i < 10; i++)
    count[i] += count[i-1];

  // Build the output array. We traverse array[] backwards to ensure the sort
  // is stable.
  for(i = size-1; i >= 0; i--) {

    // We go to the final position for array[i] specified by count 
    output[count[(array[i]/exp) % 10] -1] = array[i];

    // Decrement count so that future numbers with equal value will
    // go to the previous position
    count[(array[i]/exp) % 10]--;
  }

  // Copy output[] to array[]
  for (int i = 0; i < size; i++)
    array[i] = output[i];
}

// This is an LSD Radix Sort. LSD means "Least Significant Digit.
// That is, we begin our sort by focusing on the least significant
// digit and move towards the most significant digit with our repeating
// count sorts.
void radixSort(int array[], int size) {
  int max = getMax(array, size);

  // We stop at when m/xp = 0 because this is when our exp's place is
  // of a greater place value than the MSD of max.
  // exp *= 10 moves us from the 1's place to the 10's place to the
  // 100's place...
  for (int exp = 1; max/exp > 0; exp *= 10)
    countSort(array, size, exp);
}

///////////////////////////////////////
//-------SECOND SORT ALGORITHM-------//
///////////////////////////////////////

// Turns a binary tree (represented by array) with a root of node into a max heap.
// End is the size of the heap. (Note: As a result, array[end] and elements beyond
// are not re-ordered or compared.)
void heapify(int array[], int end, int node) {
  int largest = node;       // To begin, largest will be the root
  int left = node * 2 + 1;
  int right = node * 2 + 2;

  // Determine if node is less than either of it's children
  if (left < end && array[left] > array[largest])
    largest = left;
  if (right < end && array[right] > array[largest])
    largest = right;
  
  // If node is less than a child, swap node and child.
  // Then, recursively call heapify on this new node.
  //
  // The function ends when we have a valid max heap of size 'end' with
  // the original node as the parent
  if (largest != node) {
    swap(array[node], array[largest]);
    heapify(array, end, largest);
  }
}

void heapSort(int array[], int size) {

  // First, turn the array into a max heap. By starting with size /2 -1,
  // The resulting heapify will start at the least significant node. The
  // loop will work it's way up until the root is array[0].
  for (int i = size/2 -1; i >= 0; i--)
    heapify(array, size, i);

  // Create the final array. Sorted in ascending order
  for (int end = size -1; end >= 0; end--){
    // Move the current root to end. This builds our sorted
    // array from back to front
    swap(array[0], array[end]);

    // Create a max heap of the remaining elements.
    //After this function call, array[0] will be the second largest
    //element in array
    heapify(array, end, 0);
  }
}

//////////////////////////////////
//-------SEARCH ALGORITHM-------//
//////////////////////////////////

bool binarySearchArray(int array[], int left, int right, int searchTerm, int &index) {
  if (right >= left) {
    //The middle of the subsection bounded by left and right
    int mid = left + (right - left)/2;

    //If we found searchTerm at mid
    if (array[mid] == searchTerm) {
      index = mid;
      return true;
    }

    // If searchTerm < mid, it can only be in the left subsection...
    if (array[mid] > searchTerm)
      return binarySearchArray(array, left, mid-1, searchTerm, index);

    // Else, searchTerm can only be in the right subsection.
    return binarySearchArray(array, mid +1, right, searchTerm, index);
  }

  //This point is reached only when searchTerm is not present
  index = -1;
  return false;
}

/*
Program Output:
Radix sort (LSD) on bigArray took: 49815.00 milliseconds.
Heap sort on bigArray took: 59276.00 milliseconds.
Binary search  of bigArray took:    0.18 milliseconds.

Algorithm             5000     10000     20000     30000     40000     50000    100000
================   =======   =======   =======   =======   =======   =======   =======
radix sort (LSD)   1739.00   3473.00   6814.00   9948.00  12670.00  15267.00  29007.00
heap sort          1465.00   3177.00   6919.00  10475.00  13983.00  17205.00  35539.00
binary search         0.10      0.10      0.11      0.11      0.12      0.12      0.13

*/
