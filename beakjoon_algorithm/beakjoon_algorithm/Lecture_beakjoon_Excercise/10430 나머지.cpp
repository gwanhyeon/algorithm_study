//
//  10430 나머지.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 06/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int gcd(int a,int b){
    if(b == 0){
        return a;
    }
    else{
        return gcd(b, a%b);
    }
}




int main(void){
//    int a,b,c;
//    cin >> a >> b >> c;
//    cout << (a+b)%c << endl;
//    cout << (a%c + b%c) % c << endl;
//    cout << (a*b) % c << endl;
//    cout << (a%c * b%c) % c << endl;
    
    
    int g = 0;
    int a = 6;
    int b = 10;
    
    g = gcd(a,b);
    
    int l = g * (a/g) * (b/g);
    cout << l;
    

}
