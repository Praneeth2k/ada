#include<iostream>
#include<stdbool.h>

using namespace std;
int k = 0, ans[20];

bool isPresent( int arr[], int pro){
    for(int i = 0; i < k; i++){
        if(arr[i] == pro){
            return true;
        }
    }
    return false;

}
bool isDependent(int p[], int pro, int c){
    for(int i =0; i < c; i++){
        if(p[i] == pro){
            return true;
        }
    }
    return false;
}
void remove_depends(int d[], int process, int c){
    for(int i = 0; i < c; i++){
        if(d[i] == process){
            d[i] = -1;
        }
    }
}

bool func(int p[], int d[], int n, int process, int c){
    int i;bool t;
    if(isPresent(ans, process)){
        t = func(p, d, n, process + 1, c);
        if(t == true){
            return true;
        }
        return false;
    }
    if(isDependent(p, process, c)){
        for(i = 0; i < n; i++){
            if(p[i] == process && d[i] != -1){
                t = func(p, d, n, d[i], c);
                if(t == false){return false;}
            }
        }
    }
    ans[k++] = process;
    remove_depends(d, process, c);
    return func(p, d, n, process+1, c);

}

int main(){
    int n, i, c;
    cout<<"How many tasks\n";
    cin>>n;
    
    cout<<"How many prerequisite pairs?"<<endl;
    cin>>c;
    int process[c],depends[c];
    cout<<"Enter the prerequisite pairs"<<endl;
    for(i = 0; i < c; i++){
        cin>>process[i]>>depends[i];
    }
    if(!func(process, depends, n, 0, i)){cout<<"Solution doesn't exist\n";}
    else{
        for(i = 0; i < n; i++){
            cout<<ans[i]<<" ";
        }
    }
}   