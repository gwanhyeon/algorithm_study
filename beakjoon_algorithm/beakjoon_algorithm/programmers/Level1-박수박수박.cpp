//
//  Level1-박수박수박.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 04/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
int main(void){
    string result = "";
    int n;
    cin >> n;
    
    for(int i=1; i<=n; i++){
        if(i % 2 == 0){
            result += "박";
        }else {
            result += "수";
        }
    }
    
    cout << result;
    return 0;
}
