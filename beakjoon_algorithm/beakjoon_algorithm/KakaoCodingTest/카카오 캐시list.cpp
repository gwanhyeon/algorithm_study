//
//  카카오 캐시list.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 02/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int main(void){
    int cashesize = 3;
    vector<string> cities;
    list<string> li;

    int result = 0;
//    cities = {"b","c","a","c","b","c","d","c"};
        cities = {"Jeju","Pangyo","Seoul","NewYork","LA","Jeju","Pangyo","Seoul","NewYork", "LA"};

  
    
    for(int i=0; i<cities.size(); i++){
        string s = cities[i];
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        auto it = find(li.begin(),li.end(), s);
        
        //found
        if(it != li.end()){
            li.remove(s);
            li.push_back(s);
            result +=1;
        }
        // not found
        else {
            li.push_back(s);
            if (li.size() > cashesize){
            li.pop_front();
            }
            result +=5;
        }
        
        
    }
    return 0;
}
