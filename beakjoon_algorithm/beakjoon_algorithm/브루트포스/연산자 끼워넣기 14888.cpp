//
//  연산자 끼워넣기 14888.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 25/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(void){
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> cal;
    vector<int> res;
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    //덧셈(+), 뺄셈(-), 곱셈(×), 나눗셈(÷)
    for(int i=0; i<4; i++){
        int cnt;
        cin >> cnt;
   
        for(int j=0; j<cnt; j++){
            cal.push_back(i+1);
        }
        
    }
    
    sort(cal.begin(), cal.end());
    do{
        int ans = 0;
        int len = cal.size();
        ans = v[0];
        for(int i=1; i<v.size(); i++){
            for(int j=i-1; j<cal.size(); j++){
                if(cal[j] == 1){
                    ans = ans + v[i];
                    break;
                }else if(cal[j] == 2){
                    ans = ans - v[i];
                    break;
                }else if(cal[j] == 3){
                    ans = ans * v[i];
                    break;
                }else if(cal[j] == 4){
                    if(ans < 0){
                        ans = -ans;
                        ans = ans/v[i];
                        ans = -ans;
                    }else {
                        ans = ans/v[i];
                    }
                    break;
                }
            }
        }
        
//        for(int i=0; i<len; i++){
//            if(i == 0 && cal[i] == 1){
//                ans = 0;
//            }else if(i == 0 && cal[i] == 2){
//                ans = 0;
//            }
//            for(int j=0; j<v.size(); j++){
//                if(cal[i] == 1){
//                    ans = ans + v[j];
//                }else if(cal[i] == 2){
//                    ans = ans - v[j];
//                }else if(cal[i] == 3){
//                    ans = ans * v[j];
//                }else if(cal[i] == 4){
//                    if(ans < 0){
//                        ans = -ans;
//                        ans = ans/v[j];
//                        ans = -ans;
//                    }else {
//                        ans = ans/v[j];
//                    }
//                }
//            }
//        }
        res.push_back(ans);
    }while(next_permutation(cal.begin(),cal.end()));
    auto result = minmax_element(res.begin(),res.end());
//    cout << *result.second << *result.first << '\n';
    
    cout << *max_element(res.begin(), res.end()) << ' '<< '\n';
    cout << *min_element(res.begin(), res.end()) << '\n';
    return 0;
}
