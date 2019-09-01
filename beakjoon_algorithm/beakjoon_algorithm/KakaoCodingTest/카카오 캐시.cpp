//
//  카카오 캐시.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 01/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>
#include <fstream>
#include <map>


using namespace std;

int main(void){
    int cashesize = 3;
    vector<string> cities(cashesize);
    map<string,int> m;
    
    int result = 0;
    cities = {"Jeju","Pangyo","Seoul","NewYork","LA","Jeju","Pangyo","Seoul","NewYork", "LA"};
    
    for(int i=0; i<cashesize; i++){
     
    }
    for(int i=0; i<cities.size(); i++){
        if(i < cashesize){
            m.insert({cities[i],i});
            result += 5;
        }else {
            for(int i=0; i<m.size(); i++){
                if(m.find(cities[i]){
                    
                }
                                 
            }
            
        }
        
        
        
        
        
       
    }
    cout <<result;
    
    return 0;
}
//if(i < cashesize){
//    v.push_back(cities[i]);
//    result += 5;
//    continue;
//}else {
//    for(int j=0; j<v.size(); j++){
//        if(cities[i] ==v[j]){
//            result += 1;
//        }else {
//            if(cities[i] == v[2] ){
//                v.erase(v.end());
//                v.push_back(cities[i]);
//                result += 5;
//            }else if(cities[i-1] == v[j]){
//                v.erase(v.end()-j);
//                v.push_back(cities[j]);
//                result += 5;
//            }else if(cities[i-2] == v[2]){
//                v.erase(v.end()-2);
//                v.push_back(cities[i]);
//                result += 5;
//            }
//
//        }
//    }
//    }
