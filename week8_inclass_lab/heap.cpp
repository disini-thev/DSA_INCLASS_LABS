#include <iostream>
#include <cstdlib>

using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int i)
{
    //finding the largest out of parent and children
    int largest=i;
    int left=2*i +1;
    int right =2*i +2;

    if (left<n && arr[left]>arr[largest]) largest=left;
    if (right<n && arr[right]> arr[largest])  largest=right;

    if (largest!=i){
        swap(arr[largest], arr[i]);
        heapify(arr, n , largest); //recursively heapify largest
    }
}


void buildHeap( int arr[], int arrSize){
    //first non leaf node
    int index=arrSize/2 -1;

    for (int i=index; i>=0; i--){
        heapify (arr, arrSize, i);
    }
}
// implementing heap sort
void heapSort(int arr[], int arrSize)
{
    // build heap
    buildHeap(arr, arrSize);

   // extracting elements from heap one by one
   for (int i=arrSize -1; i>=0; i--){
        swap(arr[0], arr[i]);
        heapify (arr, i, 0);
    }

}

/* print contents of array */
void displayArray(int arr[], int arrSize)
{
   for (int i=0; i<arrSize; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}

// main program
int main()
{
    //to get user input for the array size
    int arrSize;
    cout<<"Enter the Size : "<<endl;
    cin>>arrSize;

    int heap_arr[arrSize];
    for (int i = 0; i < arrSize; i++)  heap_arr[i]= rand() % 100;

    cout<<"Input array"<<endl;
    displayArray(heap_arr,arrSize);

    heapSort(heap_arr, arrSize);

    cout << "Sorted array"<<endl;
    displayArray(heap_arr, arrSize);
}
