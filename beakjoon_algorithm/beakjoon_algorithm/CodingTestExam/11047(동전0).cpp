//
//  11047(동전0).cpp
//  beakjoon_algorithm
//
//  Created by kgh on 20/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> a;
int main(void){
    int n,k = 0;        // n 테스트케이스
    int value;
    int result = 0;
    cin >> n >> k;
    
    for(int i=0; i<n; i++){
        cin >> value;
        a.push_back(value);
        
    }
    
    for(int i=a.size() -1; i >=0; i--){
        result += k /a[i];
        k %= a[i];
    }
    cout << result;
    
    
    
    
}
