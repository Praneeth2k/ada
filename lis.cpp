#include<iostream>
using namespace std;

int lis(int arr[], int n){
    int i = 0, ans = 1, j, min, count;
    if(n == 0){
        return 0;
    }
    while(i != n && n - i > ans ){
        min = arr[i];
        count = 1;
        for(j = i + 1; j < n; j++){
            if(arr[j] > min){
                count++;
                min = arr[j];
            }
            if(count > ans){
                ans = count;
            }
        }
        i++;
    }
    return ans;
}


int main(){
    int n, i;
    cout<<"Enter the length of the sequence"<<endl;
    cin>>n;
    if(n != 0){
    cout<<"Enter the elements\n";
    }
    int arr[n];
    for(i = 0; i < n; i++){
        cin>>arr[i];
    }
    cout<<"The length of the longest subsequence is: \n";
    cout<<lis(arr,n);

}

/*
Enter the length of the sequence
6
Enter the elements
3 9 2 4 7 10
The length of the longest subsequence is:
4

Enter the length of the sequence
7
Enter the elements
6 3 1 8 9 20 1
The length of the longest subsequence is:
4


*/