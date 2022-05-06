#include <iostream>
#include <stdio.h>
#include <string>

class Node{

    public:

        int data;
        Node* next;
        Node* previous;
};

class DoubleLinkedList{
    
    private:

        Node* head = new Node();
        Node* tail = new Node();
    
    public:

        DoubleLinkedList(){
            head = NULL;
            tail = NULL;
        }

        void insert(int data){

            if(head == NULL){
                Node* temp = new Node();
                temp->data = data;
                temp->next = NULL;
                temp->previous = NULL;
                head = temp;
                tail = temp;
            }
            else{

                Node* temp = new Node();
                temp->data = data;
                temp->previous = tail;
                temp->next = NULL;
                tail->next = temp;
                tail = temp;

            }

        }

        void printReverseList(){

            Node* temp = new Node();
            temp = tail;

            while(temp->previous != NULL){
                std::cout << temp->data << "\n";
                temp = temp->previous;
            }

            std::cout << temp->data << "\n";

        }

        void printForwardList(){

            Node* temp = new Node();
            temp = head;

            while(temp->next != NULL){
                std::cout << temp->data << "\n";
                temp = temp->next;
            }
            
            std::cout << temp->data << "\n";
        }

}; 

int main(){

    DoubleLinkedList* list = new DoubleLinkedList();
    list->insert(4);
    list->insert(5);
    list->insert(6);
    list->printReverseList();
    list->printForwardList();
    return 0;

}