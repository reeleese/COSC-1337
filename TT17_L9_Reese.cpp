// Author:                      Lee Reese
// Assignment Number:           Lab 9
// File Name:                   TT17_L9_Reese.cpp
// Course/Section:              COSC 1337 Section 5      
// Due Date:                    Thu 4/10
// Instructor:                  Thayer

#include <iostream>
#include <iomanip>
#include <random> // needed for Orwell devcpp

using namespace std;

const int TARGET = 123456789;
// This target value will never be found, because it
// is larger than any random number generated by rand().
// Do not find the target to test for worst-case performance.

// helper functions
void showArray(int[], int);
bool verifySorted(int[], int);

// Each selection sort below does the same algorithm. The
// difference is in how well it documents its operation.
void selectionSort(int[], int);
void selectionSortDescribed(int[], int);
void selectionSortDescribedShowProgress(int[], int);
void selectionSortConcise(int[], int);

bool linearSearchArray(int [], int, int, int&);

// The stuff that I made
void radixSort(int[], int);
void heapSort(int[], int);
bool binarySearchArray(int[], int, int, int, int&);


const int testSizes[] = {1000, 5000, 10000, 20000, 30000, 40000, 50000, 0};

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

// Copy and/or reuse this code as desired to test your search algorithms.
float testLinearSearch(int array[], int arraySize) {
  bool found = false; // true if TARGET is found in array
  int foundAt = 0;    // index in array where TARGET was found
  int startTime = clock();
  for (int repeat = 0; repeat < 1000; repeat++) // repeat test 1000 times to increase duration
    found = linearSearchArray(array, arraySize, TARGET, foundAt); // ALGORITHM UNDER TEST
  int stopTime = clock();
  int duration = stopTime - startTime;
  return duration/1000.0; // divide duration by 1000 to get time for single search
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
    
// Copy and/or reuse this code as desired to test your algorithms.
  cout << endl << setw (AlgorithmNameWidth) << left << "selection sort";
  for (int testCount=0; (testSizes[testCount] && testSizes[testCount] <= arraySize); ++testCount)
    cout << setw(DurationWidth) << right << testSortAlgorithm(selectionSort, array, testSizes[testCount]);
    // In the line above, I am passing the name of the function selectionSort as a parameter into
    // the function testSortAlgorithm. You can do the same thing for your sort algorithms, as long
    // as your sort algorithms return a void and have parameters: (int array[], int size).

  cout << endl << setw (AlgorithmNameWidth) << left << "linear search";
  for (int testCount=0; (testSizes[testCount] && testSizes[testCount] <= arraySize); ++testCount)
    cout << setw(DurationWidth) << right << testLinearSearch(array, testSizes[testCount]);
  cout << endl;
  
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
  // the random number generator has to be "seeded" only once.
  unsigned int seed = time(0);
  srand(seed);

  // When first implementing your algorithm, you may want to test it
  // on a very small array. If so, uncomment the lines below.
  const int SMALLSIZE = 6;
  int smallArray[SMALLSIZE] = {5, 7, 2, 8, 9, 1}; // for testing purposes
 
  cout << "Optional testing of specific algorithms, prior to performance comparison table:\n\n";
  cout << "UNSORTED smallArray is: "; showArray(smallArray, SMALLSIZE);
  if (!verifySorted(smallArray, SMALLSIZE)) cout<< "Note: smallArray not sorted.\n";
  selectionSortDescribedShowProgress(smallArray, SMALLSIZE);
  cout << "SORTED   smallArray is: "; showArray(smallArray, SMALLSIZE);
  if (verifySorted(smallArray, SMALLSIZE)) cout<< "Note: smallArray is sorted.\n";

  // When first implementing your algorithm, you may want to test it
  // on a very small array. If so, try it on smallArray below.

  const int BIGSIZE = 50000;
  int bigArray[BIGSIZE];
  float duration = 0.0; // time in milliseconds

  // Do a single test run using the full size of bigArray
  duration = testSortAlgorithm(selectionSort, bigArray, BIGSIZE);
  cout << fixed << setprecision(2);
  cout << "\nSelection sort on bigArray took: "
       << setw(7) << duration << " milliseconds." << endl;

  duration = testLinearSearch(bigArray, BIGSIZE);
  cout << "Linear search  of bigArray took: "
       << setw(7) << duration << " milliseconds.\n\n";

  // Test the algorithms on ever longer list of numbers. Only one
  // array is needed.  Lengths of 1000, 5000, 10000, 20000, 30000,
  // 40000, 50000 are tested.
  testAlgorithms(bigArray, BIGSIZE);
  cout << endl;

  // system("pause");  // optional, commented out
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
//
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
    count[(array[i] / exp) % 10]++;

  // Change count[i] so that it will store the final position of the digit
  // in output. (+1)
  // e.g. If count[3] == 4, output[4-1] will contain the final occurence of
  // a '3' value in array[i]. This makes more sense when you see the next loop
  for (i = 1; i < size; i++)
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

// Turns a binary tree with a root of node into a max heap. End is the size
// of the heap. (Note: As a result, array[end] and elements beyond are not
// re-ordered or compared.)
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
  //  Then, recursively call heapify on the child.
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

void showArray(int array[], int size) {
  for (int count = 0; count < size; count++)
    cout << setw(2) << array[count] << ' ';
  cout << endl;
}

// Your new search algorithm cannot be linear search, because it is provided here.
bool linearSearchArray(int a[], int s, int t, int &p) {
  // This is very terse, short, cryptic - not recommended!
  for (int i = 0; i < s; i++) if (a[i] == t) {p=i; return true;}
  p = -1;
  return false;
}

// Your new sort algorithm cannot be selection sort, because it is provided here.
// This is the selection sort from our textbook
void selectionSort(int array[], int size) {
  int startScan, minIndex, minValue;
  for (startScan = 0; startScan < (size - 1); startScan++) {
    minIndex = startScan;
    minValue = array[startScan];
    for (int index = startScan + 1; index < size; index++) {
      if (array[index] < minValue) {
        minValue = array[index];
        minIndex = index;
      }
    }
    array[minIndex] = array[startScan];
    array[startScan] = minValue;
  }
}

// This is selection sort described in more detail
void selectionSortDescribed(int array[], int size) {
  int minIndexSoFar = 0, minValueSoFar;
  for (int unsortedIndex = 0; unsortedIndex < (size - 1); unsortedIndex++) {
    // The outer loop looks at unsorted data, which is initially the whole array.
    // Gradually, a smaller and smaller portion of the array remains unsorted.
    minIndexSoFar = unsortedIndex;
    minValueSoFar = array[unsortedIndex];
    for (int seekMinIndex = unsortedIndex + 1; seekMinIndex < size; seekMinIndex++) {
      // the inner loop seeks the smallest value possible in the
      // remaining unsorted portion of the array.
      if (array[seekMinIndex] < minValueSoFar) {
        // found a smaller value than I had before, save it for now
        minValueSoFar = array[seekMinIndex];
        minIndexSoFar = seekMinIndex;
      }
    }
    // The smallest value in the unsorted portion of the array has been found.
    // Replace the older minimum value, which wasn't really the actual minimum
    // value, with the new, real minimum value which was just found.
    array[minIndexSoFar] = array[unsortedIndex];
    array[unsortedIndex] = minValueSoFar;
    // ... continue seeking the minimum value in the smaller remaining portion.
  }
}

// This is selection sort described in great detail
// It also shows the result of each pass of the outer loop.
void selectionSortDescribedShowProgress(int array[], int size) {
  int minIndexSoFar = 0, minValueSoFar;
  for (int unsortedIndex = 0; unsortedIndex < (size - 1); unsortedIndex++) {
    // The outer loop looks at unsorted data, which is initially the whole array.
    // Gradually, a smaller and smaller portion of the array remains unsorted.
    minIndexSoFar = unsortedIndex;
    minValueSoFar = array[unsortedIndex];
    for (int seekMinIndex = unsortedIndex + 1; seekMinIndex < size; seekMinIndex++) {
      // the inner loop seeks the smallest value possible in the
      // remaining unsorted portion of the array.
      if (array[seekMinIndex] < minValueSoFar) {
        // found a smaller value than I had before, save it for now
        cout << "  previous min value: " << minValueSoFar << " at offset: " << minIndexSoFar;
        minValueSoFar = array[seekMinIndex];
        minIndexSoFar = seekMinIndex;
        cout << "; found smaller value: " << minValueSoFar << " at offset: " << minIndexSoFar << endl;
      }
    }
    // The smallest value in the unsorted portion of the array has been found.
    // Replace the older minimum value, which wasn't really the actual minimum
    // value, with the new, real minimum value which was just found.
    array[minIndexSoFar] = array[unsortedIndex];
    array[unsortedIndex] = minValueSoFar;
    cout << "  swapped the previous minimum value: " << array[minIndexSoFar]
         << " with with new minimum value: " << array[unsortedIndex] << endl;
    cout << "After pass " << unsortedIndex << " the array looks like this: ";
    showArray(array, size);
    cout << endl;
    // ... continue seeking the minimum value in the smaller remaining portion.
  }
}

// This is a selection sort from a concise algorithm encyclopedia.
// As is, it is VERY CRYPTIC!
void selectionSortConcise(int array[], int size) {
  int i, idx, val;
  for (i = 0; i < (size - 1); i++) {
    idx = i;
    val = array[i];
    for (int j = i + 1; j < size; j++) {
      if (array[j] < val) {
        val = array[j];
        idx = j;
      }
    }
    array[idx] = array[i];
    array[i] = val;
  }
}

/*
Optional testing of specific algorithms, prior to performance comparison table:

UNSORTED smallArray is:  5  7  2  8  9  1
Note: smallArray not sorted.
  previous min value: 5 at offset: 0; found smaller value: 2 at offset: 2
  previous min value: 2 at offset: 2; found smaller value: 1 at offset: 5
  swapped the previous minimum value: 5 with with new minimum value: 1
After pass 0 the array looks like this:  1  7  2  8  9  5

  previous min value: 7 at offset: 1; found smaller value: 2 at offset: 2
  swapped the previous minimum value: 7 with with new minimum value: 2
After pass 1 the array looks like this:  1  2  7  8  9  5

  previous min value: 7 at offset: 2; found smaller value: 5 at offset: 5
  swapped the previous minimum value: 7 with with new minimum value: 5
After pass 2 the array looks like this:  1  2  5  8  9  7

  previous min value: 8 at offset: 3; found smaller value: 7 at offset: 5
  swapped the previous minimum value: 8 with with new minimum value: 7
After pass 3 the array looks like this:  1  2  5  7  9  8

  previous min value: 9 at offset: 4; found smaller value: 8 at offset: 5
  swapped the previous minimum value: 9 with with new minimum value: 8
After pass 4 the array looks like this:  1  2  5  7  8  9

SORTED   smallArray is:  1  2  5  7  8  9
Note: smallArray is sorted.

Selection sort on bigArray took: 3264.00 milliseconds.
Linear search  of bigArray took:    0.13 milliseconds.

Algorithm             1000      5000     10000     20000     30000     40000     50000
================   =======   =======   =======   =======   =======   =======   =======
selection sort        2.00     33.00    131.00    523.00   1174.00   2088.00   3257.00
linear search         0.00      0.01      0.03      0.05      0.08      0.10      0.13
*/
