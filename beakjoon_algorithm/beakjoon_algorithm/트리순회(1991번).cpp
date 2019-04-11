//
//  트리순회(1991번).cpp
//  beakjoon_algorithm
//
//  Created by kgh on 11/04/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
int arr[50][2];
using namespace std;
// 전위 순회
void preorder(int start){
    if(start == -1){
        return;
    }
    cout << (char)(start + 'A');
    preorder(arr[start][0]);
    preorder(arr[start][1]);
}
// 중위 순회
void inorder(int start){
    if(start == -1){
        return;
    }
    inorder(arr[start][0]);
    cout << (char)(start + 'A');
    inorder(arr[start][1]);
                
    
}
// 후위 순회
void postorder(int start){
    if(start == -1){
        return;
    }
    postorder(arr[start][0]);
    postorder(arr[start][1]);
    
    cout << (char)(start + 'A');
    
}

int main(void){
    
    
    int t;
    cin >> t;
    
    while(t--){
        char x,y,z;         // root / left / right
        cin >> x >> y >> z;
        // . 값을 확인하기 위해서 알파벳 범위를 벗어나는지?
        x = x - 'A';
        if(y == '.'){
            arr[x][0] = -1;
        }else{
            arr[x][0] = y-'A';
        }
        if(z == '.'){
            arr[x][1] = -1;
        }else{
            arr[x][1] = z-'A';
        }
    }
    preorder(0);
    cout << "\n";
    inorder(0);
    cout << "\n";
    postorder(0);
    return 0;
}
