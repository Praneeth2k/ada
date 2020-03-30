//quick sort
#include<iostream>
#include<ctime>
using namespace std;

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printarray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int partition(int array[], int left, int right,int pivot){
    int j = right + 1;
    int i = left;
    do{
        do{
            i++;
        } while(array[i] < pivot);
        do{
            j--;
        }while(array[j] > pivot);
        swap(array[i], array[j]);
    }while(i <= j);

    swap(array[i], array[j]);
    swap(array[left], array[j]);
    
    return j;
}

void quicksort(int arr[], int left, int right, int n){
    if(left >= right){
        return;
    }
    int pivot = arr[left];
    int index = partition(arr, left, right, pivot);
    quicksort(arr, left, index - 1, n);
    quicksort(arr, index+1, right, n);
}


int main(){
    int n,*arr,i;
    clock_t t;
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    arr = new int[n];
    cout<<"Enter the elements"<<endl;
    for(i=0; i<n; i++){
        cin>>arr[i];
    }
    t = clock();
    quicksort(arr, 0, n-1, n);
    t = clock() - t;
    printarray(arr, n);
    cout<<"\nThe time taken to sort is : "<<t;
}
/*
Enter the number of elements
12
Enter the elements
-10 3 8 17 11 59 23 -4 0 79 67 12
-10 -4 0 3 8 11 12 17 23 59 67 79

The time taken to sort is : 0
 */
