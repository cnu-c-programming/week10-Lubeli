#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
    char name[10];
    int score;
    struct Node *next;
};

struct Node *head = NULL;

void add(char* name, int score){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->score = score;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } 
    else {
        struct Node *curr = head;
        while (curr->next != NULL) 
            curr = curr->next;
        curr->next = newNode;
    }
}

void delete(char* name){
    struct Node *curr = head;
    struct Node *prev = NULL;

    while (curr != NULL && strcmp(curr->name, name) != 0) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != NULL) {
        if (prev == NULL) head = curr->next;
        else prev->next = curr->next;
        free(curr);
    }
}

void print(){
    struct Node *curr = head;
    while (curr != NULL) {
        printf("%s %d\n", curr->name, curr->score);
        curr = curr->next;
    }
}

void quit(){
    struct Node *curr = head;
    while (curr != NULL) {
        struct Node *temp = curr;
        curr = curr->next;
        free(temp);
    }
    head = NULL;
    exit(0);
}

int main(){
    char order[10];
    char name[10];
    int score;
    
    while (1) {
        scanf("%s", order);

        if (strcmp(order, "add") == 0) {
            scanf("%s %d", name, &score);
            add(name, score);
        }
        else if (strcmp(order, "delete") == 0) {
            scanf("%s", name);
            delete(name);
        }
        else if (strcmp(order, "print") == 0) {
            print();
        }
        else if (strcmp(order, "quit") == 0) {
            quit();
        }
    }
    return 0;
}
