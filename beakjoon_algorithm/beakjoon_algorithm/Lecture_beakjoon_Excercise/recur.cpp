//
//  recur.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 08/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
void test(int a){
    if(a>0){
        test(a-1);
    }
}
int main(void){
    test(3500000);
    cout << "DONE";
    
    return 0;
}
