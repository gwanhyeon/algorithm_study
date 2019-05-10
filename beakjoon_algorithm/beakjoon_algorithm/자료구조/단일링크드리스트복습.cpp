//
//  단일링크드리스트복습.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 10/05/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

// structure created
typedef struct Node{
    int data;
    struct Node* next;      // 자기 자신을 구조체 참조하는 next
}node;

int main(void){
    
    node* head = (node *)malloc(sizeof(node));
    head->next = NULL;
    
    node* node1 = (node *)malloc(sizeof(node));
    node1->next = head->next;
    node1->data = 10;
    head->next = node1;
    
    node* node2 = (node *)malloc(sizeof(node));
    node2->next = node1->next;
    node2->data = 20;
    node1->next = node2;
    
    node* curr = head->next;        // 순회용 노드생성
    
    while(curr != NULL){
        cout << curr->data;
        curr = curr->next;
    }
    
    free(head);
    free(node1);
    free(node2);
    
    return 0;
}
