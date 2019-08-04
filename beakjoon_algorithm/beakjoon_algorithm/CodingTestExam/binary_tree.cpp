//
//  binary_tree.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 08/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int number = 15;
// 구조체를 사용할것이다
//하나의 노드정도를 선언
// node 구조체를 treepointer형식으로 사용하겠다.
typedef struct node *treePointer;
typedef struct node {
    int data;
    treePointer leftChild,rightChild;
} node; // 노드라는 이름으로 사용

//전위 순회
void preorder(treePointer ptr){
    if(ptr){
        cout << ptr->data << ' ';
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
    }
}
//전위 순회
void inorder(treePointer ptr){
    if(ptr){
        inorder(ptr->leftChild);
        cout << ptr->data << ' ';
        inorder(ptr->rightChild);
    }
}
//후위 순회
void postorder(treePointer ptr){
    if(ptr){
        postorder(ptr->leftChild);
        postorder(ptr->rightChild);
        cout << ptr->data << ' ';
    }
}

int main(void){
    node nodes[number+1];
    for(int i=1; i<=number; i++){
        nodes[i].data = i;
        nodes[i].leftChild = NULL;
        nodes[i].rightChild = NULL;
    }
    
    for(int i = 1; i<=number; i++){
        if( i % 2 == 0){
            nodes[i/2].leftChild = &nodes[i];
        }else{
            nodes[i/2].rightChild = &nodes[i];
        }
    }
    preorder(&nodes[1]);
    
}
