#include<iostream>

using namespace std;
int d;
int sum(int arr[], int l){
    int sum = 0, i;
    for(i = 0; i <= l; i++){
        sum += arr[i];
    }
    return sum;
}
void func(int arr[], int l, int n){
    
    int i, j = 0;
    int temp[n - 1];
    if(l>=n){
        return;
    }
    if(sum(arr, l) == d){
        cout<<"{";
        for(int i = 0; i < l; i++){cout<<arr[i]<<",";}
        cout<<arr[l]<<"}\n";
    }
    else{
        for(i = 0; i < n; i++){
            if(i != l)
                temp[j++] = arr[i];
        }
        func(arr, l + 1, n);
        func(temp, l, n - 1);

    }

}
int main(){
    int n, i;
    cout<<"Enter the size of the set\n";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements\n";
    for(i = 0;i < n; i++){
        cin>>arr[i];
    }
    cout<<"Enter required sum\n";
    cin>>d;
    cout<<"The required sum can be obtained from the following subsets\n";
    func(arr, 0, n);
}
/*
Enter the size of the set
5
Enter the elements
1 2 5 6 8
Enter required sum
9
The required sum can be obtained from the following subsets
{1,2,6}
{1,8}

Enter the size of the set
6
Enter the elements
3 1 9 2 7 8
Enter required sum
13
The required sum can be obtained from the following subsets
{3,1,9}
{3,2,8}
*/