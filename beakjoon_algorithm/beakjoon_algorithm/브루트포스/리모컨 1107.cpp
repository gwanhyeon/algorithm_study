//
//  리모컨 1107.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 01/10/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int broken[10];

int possible(int c){
    if(c == 0){
        if(broken[c] == 1){
            return 0;
        }else {
            return 1;
        }
    }
    int len = 0;
    while(c > 0){
        //고장난 경우
        if(broken[c%10] == 1){
            return 0;
        }else {
            // 앞의 자리부터 처리하기 위해서
            len +=1;
            c = c/10;
        }
    }
    return len;
}

int main(void){
    // 1. 1~500000까지의 경우의 수를 확인해야한다. 어디로 리모컨을 틀지 모르니까
    
    int chanel;
    cin >> chanel; // 5457
    int n; // 3
    cin >> n;
    
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        broken[a] = 1;
    }
    
    // 현재채널 - 100
    int ans = chanel - 100;
    // 현재 채널 음수 변경
    if(ans < 0){
        ans = -ans;
    }
    
    
    for(int i=0; i<1000000; i++){
        // 길이가 0 보다 클 경우
        int c = i;
        int len = possible(c);
        
        if(len > 0){
            // 리모컨 누른 숫
            int press = c-chanel;
            // 음수일경우
            
            if(press < 0){
                press = -press;
            }
            if(ans > len+press){
                ans = len + press;
            }
        }
    }
    cout << ans << '\n';
    
    return 0;
    
    
}
