//
//  Level1-나누어 떨어지는 숫자 배열.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 01/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
    vector<int> v;
    vector<int> answer;
    v.push_back(5); v.push_back(9); v.push_back(7); v.push_back(10);
    int divisor = 5;
    
    for(int i=0; i<v.size(); i++){
        if(v[i] % divisor == 0){
            answer.push_back(v[i]);
    
        }
    }
    if(answer.size() == 0){
        answer.push_back(-1);
    }
    sort(answer.begin(),answer.end());
    
    for(int i=0; i<answer.size(); i++){
        cout << answer[i];
    }
    
    
    return 0;
}

