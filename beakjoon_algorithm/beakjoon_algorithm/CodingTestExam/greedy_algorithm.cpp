//
//  greedy_algorithm.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 02/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int main(void){
    
    int money; // money input
    int coin[5] = {500,100,50,10,1};
    int coin_num = 0;
    cin >> money;
    
    for(int i=0; i<sizeof(coin) / sizeof(int); i++){
        while(money >= coin[i]){
            money -=coin[i];
            coin_num++;
        }
        
    }
    
    printf("%d",coin_num);
    
}
