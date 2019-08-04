//
//  GCD-4.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 12/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int gcd(int a,int b, int c){
    
    if(c == 0){
        return gcd(a,b);
    }else{
        return gcd(gcd(a,b),c)
    }
}
int main(void){
    
    int a = 24;
    int b = 16;
    int c = 16;
    
    int g = gcd(a,b,c);
    
    cout << g << endl;
    
}
