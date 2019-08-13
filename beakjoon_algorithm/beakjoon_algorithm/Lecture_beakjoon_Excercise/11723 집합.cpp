//
//  11723 집합.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 13/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int m,x;    // cmd, number
int n; // 공집합
char cmd[100];
int main(void){
    scanf("%d",&m);
    for(int i=0; i < m; i++){
        scanf("%s",cmd);
        if(!strcmp(cmd,"add")){
            scanf("%d",&x);
            if(n & (1 << x)){
                continue;
            }else {
                n |= (1 << x);
            }
        }else if(!strcmp(cmd,"remove")){
            scanf("%d",&x);
            if( ( n & (1 << x)) == 0){
                continue;
            }else {
                n &= ~(1 << x);
            }
            
        }else if(!strcmp(cmd,"check")){
            scanf("%d",&x);
            if(n & (1 << x)){
                cout << "1" << '\n';
            }else {
                cout << "0" << '\n';
            }
        }else if(!strcmp(cmd,"toggle")){
            scanf("%d",&x);
            n ^= (1<<x);
        }else if(!strcmp(cmd,"all")){
            n = (1 << 21) - 1;
            
        }else if(!strcmp(cmd,"empty")){
            n = 0;
        }
    }
    return 0;
}
