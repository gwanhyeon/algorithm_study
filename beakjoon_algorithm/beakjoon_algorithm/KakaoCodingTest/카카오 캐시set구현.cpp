//
//  카카오 캐시map구현.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 02/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <map>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>


using namespace std;

int main(void){
    int cashesize = 3;
    vector<string> cities;
    cities = {"Jeju","Pangyo","Seoul","NewYork","LA","Jeju","Pangyo","Seoul","NewYork", "LA"};
    int result = 0;
   
    unordered_set<string> m;
    
    
    for(int i=0; i<cities.size(); i++){
        string s = cities[i];
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        
      auto iter = find(m.begin(),m.end(),s);
        
        
//        auto iter = m.find(s);
        // found
        if(iter != m.end()){
            m.erase(s);
            m.insert(s);
            result += 1;
        }
        // not found
        else {
            m.insert(s);
            if(m.size() > cashesize){
            m.erase(s);
            }
            result += 5;
        }
    }
    cout << result;
    
    
    
    return 0;
}
