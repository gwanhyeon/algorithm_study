//
//  10974모든순열.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 11/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main(void){
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0; i<n; i++){
        v.push_back(i+1);
    }
    
    do{
        for(int i=0; i<n; i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
    }while(next_permutation(v.begin(),v.end()));
    
        
    return 0;
}
