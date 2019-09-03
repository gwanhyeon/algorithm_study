//
//  윷놀이 2490.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 03/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main(void){
    vector<int> v(4);
    
    for(int i=0; i<3; i++){
        
        for(int j=0; j<4; j++){
            cin >> v[j];
        }
        // 0 배 1 등
        int cnt_a =0;
        int cnt_b = 0;
        for(int i=0; i<v.size(); i++){
            if(v[i] == 0){
                cnt_a +=1;
                
            }else {
                cnt_b +=1;
            }
        }
        
        if(cnt_a == 1 && cnt_b == 3){
            cout << "A" <<'\n';
        }else if(cnt_a == 2 && cnt_b ==2){
            cout << "B" << '\n';
        }else if(cnt_a == 3 && cnt_b == 1){
            cout << "C" << '\n';
        }else if(cnt_a == 4){
            cout << "D" << '\n';
        }else {
            cout << "E" << '\n';
        }
    }
}
