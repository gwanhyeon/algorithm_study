//
//  exam1.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 22/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;
int main(void){
    
    
    int mq_num;
    int consumer;
    cin >> mq_num >> consumer;
    vector<int> v(mq_num);
    for(int i=0; i<mq_num; i++){
        cin>>v[i];
    }
    vector<int> q[consumer];
    int check[100] = {0,};
    int first = 0;
    for(int i=0; i<mq_num; i++){
        
        for(int j=0; j<consumer; j++){
            // 컨슈머 1, 2
            
//            if(i == 0){
//                for(int k=0; k<v[i]; k++){
//                    q[j].push_back(1);
//                }
//                break;
//            }
//            if(q[j].size() == 0 && check){
//
//                check = false;
//                break;
//            }
            
            if(i == 0){
                for(int k=0; k<v[i]; k++){
                    q[j].push_back(1);
                }
                first = j+1;
                break;
            }
            
            
            if(q[first].size()+v[i] < 100){
                for(int k=0; k<v[i]; k++){
                    q[first].push_back(1);
                }
                
                break;
            }else {
                first = 0;
                continue;
            }
            
        }
    }
    vector<int> res;
    
    for(int i=0; i<consumer; i++){
        //        cout << q[i].size() << ' ';
        res.push_back(q[i].size());
    }
    
    auto &max_num = *max_element(res.begin(),res.end());
    auto &min_num = *min_element(res.begin(),res.end());
    
    cout << max_num - min_num << '\n';
    
    
    return 0;
}


/*
 
5 2
4
3
5
2
8
 */
