#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{  //build heapify
  int largest; 
	int l = 2*root + 1; 
	int r = 2*root + 2; 

	if (l < n and  arr[l] > arr[root])
		largest = l;
  else{
    largest=root;
  }

	if (r < n and arr[r] > arr[largest])
		largest = r;

	if (largest != root)
	{
		swap(arr[root], arr[largest]);
		heapify(arr, n, largest);
	}
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	 // extracting elements from heap one by one
	for (int i=n-1; i>=0; i--)
    {	swap(arr[0], arr[i]);
		  heapify(arr, i, 0);
	}
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n"<<n;
}
  
// main program
int main()
{  int len; 
 cout<<"Enter number of elements in array:";
   cin>>len;
   int a[len];
  for (int j=0;j<len;j++){
    cin>>a[j];
  }
   //int heap_arr[] = {4,17,3,12,9,6};
   //int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Input array"<<endl;
   //displayArray(heap_arr,n);
  displayArray(a,len);
  heapSort(a,len);
  
  
  
  // heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   //displayArray(heap_arr, n);
   displayArray(a,len);
}
