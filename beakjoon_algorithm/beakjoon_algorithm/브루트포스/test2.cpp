//
//  test2.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 22/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
int main(void){
    
    
    vector<int> v;
    for(int i=0; i<=1000000; i++){
        v.push_back(i+1);
    }
    
    vector<long long> result;
    sort(v.begin(),v.end());
    do{
        
        long long sum = 0;
        for(int i=0; i<v.size(); i++){
            sum = v[i]*v[i+1];
    
                result.push_back(sum);
            
        }
//        string ans;
//        for(int i=0; i<v.size(); i++){
//            ans += to_string(v[i]);
//        }
        //        cout << ans << '\n';
        //        int num = stoi(ans);
//        result.push_back(ans);
//        for(int i=0; i<v.size(); i++){
//            cout <<v[i];
//        }
        
    }while(next_permutation(v.begin(),v.end()));
    
//    for(int i=0; result.size(); i++){
        cout << result[0] << ' ';
//    }
    
    return 0;
}
