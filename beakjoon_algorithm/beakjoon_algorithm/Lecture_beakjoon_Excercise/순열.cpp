//
//  순열.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 06/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
int A[5];
int check[5];
vector<int> v;

void recursive(int cnt){
    
    if(cnt == 3){
        for(int i=0; i<v.size(); i++){
            cout << v[i];
        }
        cout << '\n';
        return;
    }
    
    for(int i=0; i<5; i++){
        if(check[i] == true){
            continue;
        }
        check[i] = true;
        v.push_back(A[i]);
        recursive(cnt+1);
        v.pop_back();
        check[i] = false;
        
    }
    
    
}
int main(void){
    
    A[0] = 1;
    A[1] = 2;
    A[2] = 3;
    A[3] = 4;
    A[4] = 5;
    
    recursive(0);
    return 0;
}

