//
//  star_05.cpp
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
            
            if(i > j+1){
                cout << ' ';
            }else {
                for(int k=0; k<2; k++){
                        cout << '*';
                }
                
            }
        }
        cout << '\n';
        
    }
    
}
