//
//  서로 다른 부분 문자열의 개수.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 09/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(void){
    string str;
    set<string> s;
    
    cin >> str;
    for(int i=0; i<str.size(); i++){
        for(int j=i; j<str.size(); j++){
            string ans = str.substr(j-i,j);
            s.insert(ans);
            
        }
    }
    
    cout << s.size();
    
    return 0;
}
