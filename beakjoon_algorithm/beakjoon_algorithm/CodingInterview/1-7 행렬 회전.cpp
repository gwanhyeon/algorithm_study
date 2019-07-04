//
//  1-7 행렬 회전.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 03/07/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int main(void){
    int arr[100][100];
    int n = 10;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            arr[i][j] = i;
            cout << arr[i][j];
        }
        cout << "\n";
    }
    for(int i=0; i<n; i++){
        for(int j=n-1; j>=0; j--){
            cout << arr[j][i];
        }
        cout << '\n';
    }
    return 0;
}
