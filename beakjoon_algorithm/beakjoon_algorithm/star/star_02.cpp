//
//  star_02.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 09/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int main(void){
    
    int n;
    cin >> n;
    for(int i=n; i>0; i--){
        for(int j=0; j<n; j++){
            if(i-1 <= j){
                cout << "*";
            }else {
                cout << " ";
            }
        }
        cout << '\n';
    }
    
    
    return 0;
}
