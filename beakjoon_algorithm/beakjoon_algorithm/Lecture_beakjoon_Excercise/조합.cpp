//
//  조합.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 06/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int check[5];
int A[5];
void recursive(int n,int cnt){
    
    if(cnt == 3){
        for(int i=0; i<5; i++){
            if(check[i] == true){
                cout << A[i];
            }
        }
        cout << '\n';
        return;
        
    }
    for(int i=n; i<5; i++){
        if(check[i] == true){
            continue;
        }
        check[i] = true;
        cout<< "recursive(" << i << "," << cnt+1 << ")" <<'\n';
        recursive(i, cnt+1);
        check[i] = false;
    }
}


int main(void){
    
    A[0] = 1;
    A[1] = 2;
    A[2] = 3;
    A[3] = 4;
    A[4] = 5;
    
    recursive(0,0);
    
    
    
    
    
    
    
    
    return 0;
}
