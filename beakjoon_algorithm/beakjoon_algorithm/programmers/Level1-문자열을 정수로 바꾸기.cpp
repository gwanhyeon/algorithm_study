//
//  Level1-문자열을 정수로 바꾸기.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 04/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;
int main(void){
    string str= "-1234";
//    int str_to_int;
    
    int answer = stoi(str);
    //str_to_int = atoi(str.c_str());
    cout << answer;
    
    
    
    return 0;
}
