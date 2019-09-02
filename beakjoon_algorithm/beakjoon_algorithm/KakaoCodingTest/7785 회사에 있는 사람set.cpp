
//
//  회사에 있는 사람 7785.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 02/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <set>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
    int n;
    cin >> n;
    set<string> s;
    
    
    while(n--){
        string str1,str2;
        cin >> str1 >> str2;
        if(str2 == "enter"){
            s.insert(str1);
        }else {
            s.erase(str1);
        }
    }
//    reverse(s.begin(),s.end());
    
    for(auto it = s.rbegin(); it!=s.rend();it++){
        cout << *it << '\n';
    }
    return 0;
}
