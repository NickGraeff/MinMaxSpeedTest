#include <iostream>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <queue>
#include <utility>

using namespace std;

long long COMPARISONS = 0;

void randFunc (int *arr, int size);
void divConqMinMax (int *arr, int size, int &mymin, int &mymax);

int main() {
    clock_t t1,t2;							//clock variables used to time results of the program
    
    int *arr;
    long long size;
    int mymin = INT_MAX;
    int mymax = INT_MIN;
    cout << "Enter size: ";
    cin >> size;
    
    arr = (int*)calloc(size, sizeof(int));	//allocates an "array" of length size
	//randFunc(arr, size);
    
    t1 = clock();							//clock time at start of the program

    divConqMinMax(arr, size, mymin, mymax);
           
    t2 = clock();							//clock time at end of the program

    
    cout << "Your min is " << mymin << " and your max is " << mymax << endl;
    cout << "The total time of this program is " << (float)t2-(float)t1 << "milliseconds" << endl;
    cout << "Comparisons are: " << COMPARISONS << endl;
    
    delete [] arr;
    
    return 0;
}

void randFunc (int *arr, int size) {
    int randNum1, randNum2;

    for(int i = 0; i < size; i++){	//initialize the list with numbers 1 through n
        arr[i] = i+1;
    }
    
    for(int i = 0; i < size; i++){	//"shuffle" the numbers in the list n times
	int temp;
        randNum1 = rand() % size;
        randNum2 = rand() % size;

        swap(arr[randNum1], arr[randNum2]);
    }
    
}

void divConqMinMax (int *arr, int size, int &mymin, int &mymax) {
    int i;
    
    if (size == 1) {
        mymin = arr[0];
        mymax = arr[0];
        return;
    }
    
    if ((size&1)) {
        mymin = arr[0];
        mymax = arr[0];
        i = 1;
    } else {
        if (arr[0] > arr[1]) {
            mymin = arr[1];
            mymax = arr[0];
        } else {
            mymin = arr[0];
            mymax = arr[1];
        }
        i = 2;
        ++COMPARISONS;
    }
 
    for (; i < size-1; i+=2) {
        if (arr[i] > arr[i+1]) {
            if (arr[i] > mymax) {
                mymax = arr[i];
            }
            if (arr[i+1] < mymin) {
                mymin = arr[i+1];
            }
        } else {
            if (arr[i] < mymin) {
                mymin = arr[i];
            }
            if (arr[i+1] > mymax) {
                mymax = arr[i+1];
            }
        }
        COMPARISONS+=3;
    }        
} 

