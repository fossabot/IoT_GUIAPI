#ifndef LINKED_LIST
#define LINKED_LIST

template<typename L>
class List{
public:
    List();
    ~List();

    void push_back(L data);
    void pop_front();
    void clear();
    void push_front(L data);
    void insert(L data, int index);
    void removeAt(int index);
    void pop_back();
    inline int GetSize() { return Size; }

    L& operator[](const int index);
private:
    template<typename T>
    class Node{
        public:
            Node *pNext;
            T data;

            Node(T data=T(), Node *pNext=nullptr){
                this->data = data;
                this->pNext = pNext;
            }
    };
    int Size;
    Node<L> *head;

};

#endif