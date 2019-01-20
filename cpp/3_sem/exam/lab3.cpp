#include <iostream>
#include <cstdlib>


class Node
{
public:
    Node *next;
    int data;
};

class LinkedList
{
public:
    int length;
    Node *head;

    LinkedList();
    ~LinkedList();
    void add(int data);
    void print();
    void selectionSort();
    void bubbleSort();
    void insertionSort();
};

LinkedList::LinkedList(){
    this->length = 0;
    this->head = NULL;
}

// LinkedList::~LinkedList(){
//     std::cout << "LIST DELETED";
// }

LinkedList::~LinkedList() {
    Node *next = head;
    Node *cur = NULL;
    while (next != NULL) {
        cur = next;
        next = next->next;
        delete cur;
    }
}

void LinkedList::add(int data){
    Node *node = new Node();
    node->data = data;
    node->next = this->head;
    this->head = node;
    this->length++;
}

void LinkedList::print(){
    Node *head = this->head;
    int i = 1;
    while(head){
        std::cout << i << ": " << head->data << std::endl;
        head = head->next;
        i++;
    }
}

void LinkedList::selectionSort()
{
    Node *i, *j;
    int temp;

    for(i = head; i != NULL; i = i->next)
    {
       for(j = i->next; j != NULL; j = j->next)
       {
            if(i->data > j->data)
            {
                std::cout << "i->data: " << i->data << " j->data: " << j->data << std::endl;
                temp = i->data;
                i->data = j->data;
                j->data = temp;
           }
       }
    }
    std::cout<<"\nThe numbers are Sorted\n";
}

void LinkedList::bubbleSort()
{
    int size = this->length;
    int i = 0;

    Node *lastSwapped = NULL;

    while(size--)
    {
        Node
            *current = this->head,
            *prev = NULL,
            *currentSwapped = NULL;

        while(current->next != lastSwapped) // We have at least one node (size > 0) so `current` itself is not NULL.
        {
            Node *after = current->next;
            if(current->data > after->data)
            {
                //swap the items
                current->next = after->next;
                after->next = current;
                if (prev == NULL) // we are at the beginning
                    this->head = after;
                else
                    prev->next = after;

                prev = after;
                currentSwapped = current;
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }

        if (currentSwapped == NULL)
            break; // No swapping occured. The items are sorted.
        else
            lastSwapped = currentSwapped;
    }
}

void LinkedList::insertionSort()
{
    if(this->head == NULL || this->head->next == NULL)
    {
       return;
    }
    Node *t1 = this->head->next;
    while(t1 != NULL)
    {
        int sec_data = t1->data;
        int found = 0;
        Node *t2 = this->head;
        while(t2 != t1)
        {
            if(t2->data > t1->data && found == 0)
            {
                sec_data = t2->data;
                t2->data = t1->data;
                found = 1;
                t2 = t2->next;
            } else {
                if(found == 1)
                {
                    int temp = sec_data;
                    sec_data = t2->data;
                    t2->data = temp;
                }
                t2 = t2->next;
            }
       }
       t2->data = sec_data;
       t1 = t1->next;
    }
}

int main()
{
    // Construct llist
    LinkedList* list = new LinkedList();
    for (int i = 0; i < 10; ++i)
    {
        list->add(rand() % 10);
    }
    list->print();
    std::cout << "List Length: " << list->length << std::endl;

    // Sort llist
    // list->selectionSort();
    // list->bubbleSort();
    list->insertionSort();
    list->print();
    delete list;
    return 0;
}
