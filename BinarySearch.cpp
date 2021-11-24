#include <iostream>
#include <algorithm>
#include <omp.h>
using namespace std;

#define MAX1 5

int binary_search(int arr[], int x, int low, int high)
{
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if(arr[mid] == x)
            return mid;
        if(arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int array[MAX1];
    int loc1, loc2, loc3, loc4, k;
    omp_set_num_threads(4);
    
    cout<<"Enter "<<MAX1<<" Numbers: ";

    for(int i=0; i<MAX1; ++i)
        cin>>array[i];
	cout<<endl;
    sort(array, array+MAX1);

    cout<<"Enter number to search : ";
    cin>>k;
    int mid = MAX1/2;
   
    int one_quart = mid/2;
    int three_quart = 3*one_quart;
    #pragma omp parallel sections
    {
        #pragma omp section
        loc1 = binary_search(array, k, 0, one_quart);
        #pragma omp section
        loc2 = binary_search(array, k, one_quart+1, mid);
        #pragma omp section
        loc3 = binary_search(array, k, mid+1, three_quart);
        #pragma omp section
        loc4 = binary_search(array, k, three_quart+1, MAX1-1);
    }
    if(loc1+loc2+loc3+loc4==-4)
    {
    	cout<<"Not Found\n";
    	return 0;
	}
   
    cout<<"Number has found";
  	return 0;
}

