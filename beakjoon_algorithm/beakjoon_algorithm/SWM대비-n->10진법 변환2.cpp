//
//  2745(진법변환1).cpp
//  beakjoon_algorithm
//
//  Created by kgh on 16/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int main(void){
    int b;
    string s;
    int ans =0;
    
    cin >> s >> b;
    
    for(int i=0; i<s.size(); i++){
        if(s[i] <= '9' && s[i] >= '0'){
            // 계속해서 더해간다고 생각하면 된다.
            // 숫자로 변환 시켜줘야하므로
            ans = ans * b + (s[i] - '0');
//            ans += pow(b,size-i-1) * (s[i] - '0');
            
            
        }else{
            ans = ans * b + (s[i] + 10 - 'A');
//            ans += pow(b,size-i-1) * (s[i] + 10 - 'A');
        }
    }
    cout << ans << "\n";
    return 0;
    
}
