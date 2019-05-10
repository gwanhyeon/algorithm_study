//
//  표준입출력문자열.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 11/05/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

// cin scanf 는 공백을 포함한 문자열을 제대로 입력 받지 못한다.
// 어떻게 사용할 수 있을까?

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main(void){
    
    // getline(cin, s) 명령어로 깔끔하게 해결 가능
    string str;
    getline(cin,str);
    cout << str << "\n";
    const char* t = str.c_str();
    printf("%s", t);
    
    
}
