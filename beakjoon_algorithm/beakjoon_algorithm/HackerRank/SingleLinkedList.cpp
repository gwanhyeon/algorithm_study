//
//  SingleLinkedList.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 08/07/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct NODE {
    int data;
    struct NODE* next;
}node;

void insert_node(node* head, int data);
void delete_node(node* head);
node* search_node(node*,int);
void print_node(node* head);
void Init(node*);
void insert_node(node* head, int data){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = head->next;
    head->next = new_node;
    cout << "insert data: " << data << '\n';
    
    
}
void delete_node(node* head){
    node* target = head->next;
    head->next = target->next;
    free(target);
    cout<< "Node delete" << '\n';
    
}
node* search_node(node* head,int data){
    node* curr = head->next;
    
    while(curr != NULL){
        if(curr->data == data){
            return curr;
        }
        curr = curr->next;
    }
    return 0;
}
void print_node(node* head){
    
    node* curr = head->next;
    cout << "Node List : ";
    while(curr != NULL){
        cout<< curr->data;
        curr = curr->next;
    }
    cout << '\n';
}
void Init(node* head){
    node* target = head;
    node* temp = target;
    
    while(target != NULL){
        temp = temp->next;
        free(target);
        target = temp;
    }
}
int main(void){
    node* head = (node*)malloc(sizeof(node));
    head->next = NULL;
    
    insert_node(head,10);
    insert_node(head,20);
    insert_node(head,30);
    delete_node(head);
    print_node(head);
    
    node* result = search_node(head,20);
    
    if(result != NULL){
        cout << "Found data: " << result->data;
    }else{
        cout << "Not Found data!" << '\n';
    }
    return 0;
}
