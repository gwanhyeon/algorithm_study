//
//  11478 서로 다른 부분 문자열의 개수.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 08/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;
int main(void){
    
    string str = "ababc";
    
    for(int i=1; i<=str.size(); i++){
        string a = "";
        for(int j=0; j<str.size(); j++){
            cout << str.substr(j,i) << ' ';

        }
        cout << '\n';
    }
    
    
    return 0;
}
