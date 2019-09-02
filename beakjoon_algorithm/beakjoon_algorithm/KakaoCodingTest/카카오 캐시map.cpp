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

#include <map>
#include <list>

using namespace std;

int main(void){
    int cashesize = 3;
    vector<string> cities;
    map<string,int> m;
    
    int result = 0;
    cities = {"b","c","a","c","b","c","d","c"};
//    cities = {"Jeju","Pangyo","Seoul","NewYork","LA","Jeju","Pangyo","Seoul","NewYork", "LA"};
//

    for(int i=0; i<cities.size(); i++){
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        if(i < cashesize){
            
            m.insert({cities[i],i});
            result += 5;
            continue;
        }else {
            // not found
            if(m.find(cities[i]) == m.end()){
                if(cities[i-cashesize] == cities[i]){
                    m.erase(m.find(cities[i-cashesize]));
                    m.insert({cities[i-cashesize],i});
                    result += 5;
                }else {
                    m.erase(m.find(cities[i-cashesize]));
                    m.insert({cities[i],i});
                    result += 5;
                }
            }else {
                result += 1;
            }
        }
    }
    
    cout << result;
  
    
    
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


//
//
//cout << cities.size();
//
//
//for(int i=0; i<cities.size(); i++){
//    if(i < cashesize){
//        m.insert({cities[i],i});
//
//        result += 5;
//    }else {
//        for(int j=0; j<m.size(); j++){
//
//            // not found
//            if(m.find(cities[i]) != m.end()){
//
//                for(int k=0; k<cashesize; k++){
//                    // found
//                    if(m.find(cities[i-k]) != m.end()){
//                        continue;
//
//                    }else {
//                        result +=5;
//                        m.erase(m.find(cities[i-k]));
//                        m.insert({cities[i],i});
//                    }
//                }
//                // found
//            }else {
//                result +=1;
//                continue;
//            }
//        }
//        }
