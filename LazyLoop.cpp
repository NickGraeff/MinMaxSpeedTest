#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

long long COMPARISONS = 0;

void randFunc (int *arr, int size);
void lazyLoop (int *arr, int size, int &mymin, int &mymax);

int main() {
	/* Clock variables are used to time the result of the program */
    clock_t t1,t2;	

    int *arr;
    long long size;
    int mymin = INT_MAX;
    int mymax = INT_MIN;
    cout << "Enter size: ";
    cin >> size;
    
	/* 
	 * Allocates an array of length size, could use malloc() here 
	 * instead if you actually intend on using the randFunc() 
	*/
    arr = (int *) calloc(size, sizeof(int));
	//randFunc(arr, size);
    
	/* Run and time the function */
    t1 = clock();							
    lazyLoop(arr, size, mymin, mymax);
    t2 = clock();		
    
    cout << "Your min is " << mymin << " and your max is " << mymax << endl;
    cout << "The total time of this program is " << (float)t2-(float)t1 << "milliseconds" << endl;
    cout << "Comparisons are: " << COMPARISONS << endl;
    
    delete [] arr;
    
    return 0;
}

void randFunc (int *arr, int size) {

	/* Initialize the list with numbers 1 through n */
    for(int i = 0; i < size; i++){
        arr[i] = i+1;
    }
    
	/* Shuffle the numbers n times */
    for(int i = 0; i < size; i++){
        swap(arr[rand()%size], arr[rand()%size]);
    }
    
}

void lazyLoop (int *arr, int size, int &mymin, int &mymax) {

	/* Loop through comparing each element twice to the min and max */
	for (int i = 0; i < size; ++i) {
		mymax = (arr[i] > mymax) ? arr[i] : mymax;
		mymin = (arr[i] < mymin) ? arr[i] : mymin;
		COMPARISONS += 2;
	} 
} 

