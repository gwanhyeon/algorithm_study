//
//  5543번 상근날드.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 03/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main(void){
    vector<int> v(5);
    
    for(int i=0; i<v.size(); i++){
        cin >> v[i];
    }
    int min = 999999;
    
    for(int i=0; i<v.size()-2; i++){
        for(int j=3; j<v.size(); j++){
            // 1+3 < 999999
            if(v[i] + v[j] < min){
                min = v[i] + v[j];
            }
        }
    }
    
    cout << min-50;
    
    
    
    return 0;
}
