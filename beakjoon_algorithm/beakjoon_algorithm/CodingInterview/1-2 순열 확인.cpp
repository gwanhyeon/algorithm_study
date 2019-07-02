//
//  1-2 순열 확인.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 03/07/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main(void){
    string str1 = "Hello World!";
    string str2 = "Helol World!";
    
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    
    if(str1.compare(str2) == 0){
        cout << str1 << "과" << str2 << "는 순열 관계 입니다."<<'\n';
    }else {
        cout << str1 << "과" << str2 << "는 순열 관계가 아닙니다."<<'\n';
    }
    
    
    
    
    return 0;
}
