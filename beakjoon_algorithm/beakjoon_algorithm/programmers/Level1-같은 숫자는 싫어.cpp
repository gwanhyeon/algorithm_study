//
//  Level1-같은 숫자는 싫어.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 01/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main(void){
    vector<int> answer;
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(3);
    v.push_back(3);
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    
    for(int i=0; i<v.size(); i++){
        for(int j=i; j<v.size(); j++){
     
            if(v[i] == v[j+1]){
                v.erase(v.begin()+(i));
                break;
            }
        }
        
    }
    for(int i=0; i<v.size(); i++){
        
        answer.push_back(v[i]);
    }
    for(int i=0; i<v.size(); i++){
        cout << answer[i];
    }
    
    return 0;
}
