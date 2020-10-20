#include <libs/List.h>

template<typename L>
List<L>::List(){
    Size = 0;
    head = nullptr;
}

template<typename L>
List<L>::~List(){
    clear();
}

template<typename L>
void List<L>::push_back(L data){
    if(head == nullptr){
        head = new Node<L>(data);
    }else{
        Node<L> *current = this->head;
        while (current->pNext != nullptr){
            current = current->pNext;
        }

        current->pNext = new Node<L>(data);
        
    }
    Size++;
}

template<typename L>
L& List<L>::operator[](const int index){
    int counter = 0;
    Node<L> *current = this->head;
    while (current != nullptr){
        if(counter == index) return current->data;
        current = current->pNext;
        counter++;
    }
}

template<typename L>
void List<L>::pop_front(){
    Node<L> *temp = head;
    head = head->pNext;
    delete temp;
    Size--;
}

template<typename L>
void List<L>::clear(){
    while (Size){
        pop_front();
    }
}

template<typename L>
void List<L>::push_front(L data){
    head = new Node<L>(data, head);
    Size++;
}

template<typename L>
void List<L>::insert(L data, int index){
    if(index == 0){
        push_front(data);
    }else{
        Node<L> *previous = this->head;
        for(int i = 0; i < index - 1; i++){
            previous = previous->pNext;
        }

        Node<L> *newNode = new Node<L>(data, previous->pNext);
        previous->pNext = newNode;

        Size++;
    }
}

template<typename L>
void List<L>::removeAt(int index){
    if(index == 0){
        pop_front();
    }else{
        Node<L> *previous = this->head;
        for(int i = 0; i < index - 1; i++){
            previous = previous->pNext;
        }

        Node<L> *toDelete = previous->pNext;
        previous->pNext = toDelete->pNext;

        delete toDelete;
        Size--;
    }
}

template<typename L>
void List<L>::pop_back(){
    removeAt(Size-1);
}