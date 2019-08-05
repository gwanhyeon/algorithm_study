//
//  Level1-문자열다루기기본.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 05/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main(void){
    string str ="1234";
    bool tf = true;
    if(str.size() != 4 && str.size() != 6){
        tf = false;
        
    }else {
        for(int i=0; i<str.size(); i++){
            // str[i] 정수로 만들기
            // solution 01
            if(!isdigit(str[i])){
                tf = false;
            }
            // solution 02
//            if(str[i] < '0' || str[i] > '9'){
//                return false;
//            }
        }
    }
    cout << tf;
    
    return 0;
    
}
