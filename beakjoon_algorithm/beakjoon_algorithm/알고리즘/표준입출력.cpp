//
//  표준입출력.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 10/05/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main(void){
    // string value to do not printf/scanf
    string str;
    str = "Hello World! ";
    //printf("%s",str);
    
    // how to you using string? => str.c_str() 함수를 사용하면 처리 할 수 있음.
    
    printf("%s",str.c_str());
    
    
    
    
    
    return 0;
}
