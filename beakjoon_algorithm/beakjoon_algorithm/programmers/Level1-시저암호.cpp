//
//  Level1-시저암호.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 07/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main(void){
    
    
    string str = "a B z";
    string answer = "";
    
    int n = 4;
    
    for(int i=0; i<str.size(); i++){
        if(str[i] == ' '){
            answer += ' ';
        }else if(str[i] >= 'a' || str[i] <= 'z'){  // 알파벳은 26개
            if(str[i] == 'z'){
                answer += (str[i] + n) - ('a');
                continue;
            }else {
                answer += (str[i] + n);
            }
        }else if(str[i] >= 'A' || str[i] <= 'Z'){
            if(str[i] == 'Z'){
                answer += (str[i] + n) - ('A');
                continue;
            }else {
                answer += (str[i] + n);
            }
        }
        
    }
    cout << answer << endl;
    return 0;
}

