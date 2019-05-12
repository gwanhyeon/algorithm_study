//
//  9012괄호.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 12/05/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    
    while(n--){
        string str;
        cin >> str;
        stack<int> S;
        for(auto c : str){
            // open
            if(c == '('){
                S.push(c);
            }else{ // close
                if(S.empty()){
                    S.push('x');
                    break;
                }
                if(c == ')'){
                    if(S.top() != '('){
                        break;
                        
                    }else{
                        S.pop();
                    }
                }
            }
        }
        if(S.empty()){
            cout << "YES" << '\n';
        }else{
            cout << "NO" << '\n';
        }
    }
    
    return 0;
}
