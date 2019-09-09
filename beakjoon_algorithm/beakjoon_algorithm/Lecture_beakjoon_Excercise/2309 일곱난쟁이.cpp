
//
//  2309 일곱난쟁이.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 06/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    
    int n = 9;
    int arr[9];
    int sum = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    
    sort(arr,arr+n);
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(sum - arr[i] - arr[j] == 100){
                for(int k=0; k<n; k++){
                    if(i == k || j == k){
                        continue;
                    }
                    cout << arr[k] << '\n';
                }
                return 0;
            }
        }
        
    }
    
    
    return 0;
    
}



//
//int a[9];
//int n = 9;
//int sum = 0;
//for(int i=0; i<n; i++){
//    cin >> a[i];
//    sum += a[i];
//}
//
//for(int i=0; i<n; i++){
//    for(int j=i; j<n; j++){
//        if(sum - a[i] - a[j]){
//            for(int k=0; k<n; k++){
//                if(i == k || j == k){
//                    continue;
//                }
//                cout << a[k];
//                return 0;
//                }
//                }
//                }
//
//                }
