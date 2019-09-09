//
//  9012 괄호.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 08/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(void){
    
    // 반례 ())(()
    
    int n;
    cin >> n;
    
    while(n--){
        string str;
        cin >> str;
        
        int cnt = 0;
        for(int i=0; i<str.size(); i++){
            if(str[i] == '('){
                cnt += 1;
            }
            else if(str[i] == ')'){
                cnt -= 1;
            }
            if(cnt < 0){
                cnt = -1;
                break;
            }
        }
        if(cnt == 0){
            cout << "YES" << '\n';
        }else{
            cout << "NO" << '\n';
        }
    }
    
    
    return 0;
}
