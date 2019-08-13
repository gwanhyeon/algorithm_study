
//
//  1182 부분수열의 합.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 13/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int arr[10];
int main(void){
    int n,s;
    int answer =0;
    cin >> n;
    cin >> s;
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    for(int i=1; i<(1<<n)-1; i++){
        
        int sum = 0;
        for(int j=0; j<n; j++){
            if(i & (1<<j)){
                sum += arr[j];
            }
        }
        if(s == sum){
            answer +=1;
        }
    }
    cout << answer << '\n';
    
    return 0;
    
}
