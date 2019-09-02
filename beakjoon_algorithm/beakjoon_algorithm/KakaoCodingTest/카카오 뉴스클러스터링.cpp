//
//  카카오 뉴스클러스터링.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 02/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int main(void){
    string str1 = "E=M*C^2";
    string str2 = "french";
    
    vector<string> A;
    vector<string> B;
    
    int element_intersection;
    int element_union;
    // 모든 str1,str2원소를 대문자로 변경한다.
    transform(str1.begin(),str1.end(),::toupper);
    transform(str2.begin(),str2.end(),::toupper);
    
    
    
    
    
    
    
    
    
    
//    int in = 0;
//    int all = 0;
//
//    transform(str1.begin(),str1.end(), str1.begin(),::tolower);
//    transform(str2.begin(),str2.end(), str2.begin(),::tolower);
//    for(int i=0; i<str1.size(); i++){
//        if(str1[i]>='a'&&str1[i]<='z' && str1[i+1] >='a' && str1[i+1] <='z'){
//                A.push_back(str1.substr(i,2));
//        }else {
//            continue;
//        }
//
//    }
//    for(int i=0; i<str2.size(); i++){
//        B.push_back(str2.substr(i,2));
//    }
//
//    for(int i=0; i<A.size(); i++){
//        for(int j=0; j<B.size(); j++){
//            if(A[i] == B[j]){
//                string a = A[i];
//                string b = B[i];
//
//                int a_n = count(A.begin(),A.end(),a);
//                int b_n = count(B.begin(),B.end(),b);
//                if(a_n == b_n){
//                    all += a_n;
//                    in += a_n;
//                }
//                else if(a_n > b_n){
//                    all += a_n;
//                    in += b_n;
//                }else {
//                    all += b_n;
//                    in += a_n;
//                }
//            }else{
//                all += 1;
//                in += 1;
//            }
//        }
//    }
//
//    cout << all << in;

    
    return 0;
}
