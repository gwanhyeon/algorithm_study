//
//  10974 모든 순열.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 06/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main(void){
    
    int n = 3;
    vector<int> v(3);
    for(int i=0; i<n; i++){
        v[i] = i+1;
        
    }
    
    do {
        for(int i=0; i<n; i++){
            cout << v[i];
        }
        cout << '\n';
    } while (next_permutation(v.begin(), v.end()));
    
    
    return 0;
    
}
