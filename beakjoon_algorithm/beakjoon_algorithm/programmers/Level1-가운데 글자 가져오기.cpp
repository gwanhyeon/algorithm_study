//
//  Level1-가운데 글자 가져오기.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 01/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>


using namespace std;

int main(void){
    string str = "abcde";
    string answer = "";
    
    if(str.length() % 2 == 0){
        answer += str.substr(str.length()/2-1,2);
    }else{
        answer += str.substr(str.length()/2,1);
    }

    cout <<answer;
//     return s.length()&1 ? s.substr(s.length()*0.5,1) : s.substr(s.length()*0.5-1,2);
    
    
    
    
    
    
    return 0;
}
