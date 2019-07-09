//
//  2-6 회문.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 08/07/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
typedef struct NODE{
    int data;
    struct NODE* next;
}node;
node* head = NULL;
node* tail = NULL;

void add_node(int data){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
        tail = temp;
    }else {
        tail->next = temp;
        tail = tail->next;
    }
    
}
node* partition(NODE* curr,int x){
    head = curr;
    node* tail = curr;
    
    while(curr != NULL){
        node* next = curr->next;
        
        if(curr->data < x){
            curr->next = head;
            head = curr;
        }else{
            tail->next = curr;
            tail = curr;
        }
        curr = next;
    }
    tail->next = NULL;
    return head;
}

void printLinkedList(){
    if(head == NULL){
        return;
    }
    
    node* currentNode = head;
    while(currentNode->next != NULL){
        cout << currentNode->data;
        currentNode = currentNode->next;
    }
    cout << currentNode->data;
}
int main(void){
    add_node(3);
    add_node(5);
    add_node(8); 
    add_node(5);
    add_node(10);
    add_node(2);
    add_node(1);
    partition(head,5);
    printLinkedList();

    return 0;
}
