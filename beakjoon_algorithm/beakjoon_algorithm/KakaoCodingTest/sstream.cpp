//
//  sstream.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 04/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>

using namespace std;
int main(void){
    string input = "A B C D";
    stringstream ss(input);
    string item;
    vector<string> result;
    while(getline(ss,item,' ')){
        
        
        result.push_back(item);
    }
    for(int i=0; i<result.size(); i++){
        cout << result[i];
    }
    
    
    
    return 0;
    
}
