#include <iostream> 
using namespace std; 
  
void grid(int n){
    int arr[n][n]; 
    int p = 0, i, j, k, l; 
    for(i = 0; i < n / 4; i++){ 
        for(j = 0; j < n / 4; j++){ 
            for(k = 0; k < 4; k++){ 
                for (l = 0; l < 4; l++){ 
                    arr[i * 4 + k][j * 4 + l] = p; 
                    p++; 
                } 
            } 
        } 
    } 
  
    for(int i = 0; i < n; i++){ 
        for (int j = 0; j < n; j++){ 
            cout << arr[i][j] << " "; 
        } 
        cout << "\n"; 
    } 
} 
  

int main(){ 
    int n;
    while(true){
        cout<<"Enter the value of n (multiple of 4)"<<endl;
        cin>>n;
        if(n % 4 == 0){ 
            grid(n);
            break;
        } 
        else cout<<"Invalid input\n";
    }

    return 0; 
}
/*
Enter the value of n (multiple of 4)
12
0 1 2 3 16 17 18 19 32 33 34 35
4 5 6 7 20 21 22 23 36 37 38 39
8 9 10 11 24 25 26 27 40 41 42 43
12 13 14 15 28 29 30 31 44 45 46 47
48 49 50 51 64 65 66 67 80 81 82 83
52 53 54 55 68 69 70 71 84 85 86 87
56 57 58 59 72 73 74 75 88 89 90 91
60 61 62 63 76 77 78 79 92 93 94 95
96 97 98 99 112 113 114 115 128 129 130 131
100 101 102 103 116 117 118 119 132 133 134 135
104 105 106 107 120 121 122 123 136 137 138 139
108 109 110 111 124 125 126 127 140 141 142 143
*/
