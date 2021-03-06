#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

long long COMPARISONS = 0;

void randFunc (int *arr, int size);
void divConqMinMax (int *arr, int size, int &mymin, int &mymax);

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
    divConqMinMax(arr, size, mymin, mymax);
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

void divConqMinMax (int *arr, int size, int &mymin, int &mymax) {

	/* Assume the array is even, start with the first pair */
    int i = 0;
    
	/* If the array is of size 1 just return that element */
    if (size == 1) {
        mymin = arr[0];
        mymax = arr[0];
        return;
    }
    
	/* If the array is odd make the first element min and max */
    if ((size&1)) {
        mymin = arr[0];
        mymax = arr[0];
        i = 1;
    } 
	
	/* While the last pair has not been compared */
    while (i < size-1) {

		/* Is arr[i] the max or the min */
        if (arr[i] > arr[i+1]) {
			mymax = (arr[i] > mymax) ? arr[i] : mymax;
            mymin = (arr[i+1] < mymin) ? arr[i+1] : mymin;
        } else {
            mymin = (arr[i] < mymin) ? arr[i] : mymin;
			mymax = (arr[i+1] > mymax) ? arr[i+1] : mymax;
        }

		/* Increase the number of comparisons for testing results */
        COMPARISONS += 3;
		i += 2;
    }        
} 

