//
//  6064카잉달력.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 06/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int main(void){
    
    int n;
    cin >> n;
//    int x_copy, y_copy;
    
    //TC
    while(n--){
        int m,n,x,y;
        cin >> m >> n >> x >> y;
        x -= 1;
        y -= 1;
        bool check = false;
        for(int k=x; k<(n*m); k+=m){
            if(k%n == y){
                cout << k+1 << '\n';
                check =true;
                break;
            }
        }
        if(!check){
            cout << -1 << '\n';
        }
//            if(x < m){
//                x_copy = x + 1;
//            }else if(x > m){
//                x_copy = 1;
//            }
//            if(y < m){
//                y_copy = y + 1;
//            }else if(y > m){
//                y_copy = 1;
//            }
//
//        x_copy = x_copy % m;
//        y_copy = y_copy % n;
//        cout << x_copy << y_copy;
        
    }
    
    
    return 0;
    
}
