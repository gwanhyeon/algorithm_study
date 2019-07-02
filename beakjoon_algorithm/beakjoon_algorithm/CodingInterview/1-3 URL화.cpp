//
//  URL화.cpp
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
    string str1 = "H E L L O W O R L D";
    str1.capacity();
    
    for(int i=0; i<str1.size(); i++){
        if(str1[i] == ' '){
            str1.replace(i,1,"%20");
        }
    }
    cout << str1;
    
    return 0;
}
