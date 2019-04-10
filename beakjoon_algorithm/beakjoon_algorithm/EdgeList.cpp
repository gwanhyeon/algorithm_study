//
//  EdgeList.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 10/04/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int main(void){
    
    
    int E[6][6];
    int cnt[6];
    int n,m;
    
    cin >> n >> m;
    
    for(int i=0; i<m; i++){
        cout << cnt[E[i][0]] << " ";
        
    }
    for(int i=0; i<m; i++){
        cout << cnt[i] << " ";
    }
    
    return 0;
}
