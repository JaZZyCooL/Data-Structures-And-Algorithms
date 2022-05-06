#include <stdio.h>
#include <iostream>
class Node{
    
    public:
        int data;
        Node* next;
};

class LinkedList {
    private:
        Node* head = new Node();
        Node* tail = new Node();
    public:
        
        LinkedList(){
            head = NULL;
            tail = NULL;
        }

        void insert(int data){
            
            Node* temp = new Node();
            temp->next = NULL;
            temp->data = data;
            
            if(head == NULL){
                

                head = temp;
                tail = temp;

            }
            else{

                tail->next = temp;
                tail = temp;
            }


        }

        void removeLastNode(){
            
            if(head == NULL){
                std::cout << "Sorry cannot remove the list is already empty\n";
            }

            if (head->next == NULL){
                head = tail;
                delete head;
            }

            Node* temp = new Node();
            temp = head;

            while(temp->next != NULL){
                tail = temp;
                temp = temp->next;
            }

            delete temp;
            tail->next = NULL;
             
        }    

        void printHeadTail(){
            std::cout << "head : " << head->data << "\n";
            std::cout << "tail : " << tail->data << "\n";
        }


        void printList(){
            
            Node* newNode = new Node();
            newNode = head;

            while(newNode->next != NULL){
                std::cout << newNode->data << "\n";
                newNode = newNode->next;
            }
            std::cout << newNode->data << "\n";
        }
        
};

int main(){
    LinkedList* list = new LinkedList();
    list->insert(4);
    list->insert(5);
    list->insert(6);
    list->printHeadTail();
    list->removeLastNode();
    list->printHeadTail();
    list->removeLastNode();
    list->printHeadTail();
    list->removeLastNode();
    list->printHeadTail();
    list->insert(4);
    list->printHeadTail();
    list->insert(5);
    list->printHeadTail();
    list->insert(6);
    list->printHeadTail();
    return 0;

}