//
//  1-1중복문제.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 03/07/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main(void){
    
    string str = "ABCBG";
    auto size = str.size();
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(str[i] == str[j]){
                cout << "중복 문자는 " << str[i] << "입니다" << '\n';
            }
        }
    }
    return 0;
}
