
//mary jabro
#include "ListLinked.h"

template <typename DataType>

List<DataType>::ListNode::ListNode(const DataType& nodeData, ListNode* nextPtr) {

dataItem = nodeData;
next = nextPtr;

}
template <typename DataType>

List<DataType>::List(int ignored) {

head = nullptr; //empty
cursor = nullptr;

}

template <typename DataType>

List<DataType>::List(const List& other) {

    ListNode* temp = other.head; //our temp node so we can traverse though other list
    while (temp != nullptr) {
        this->dataItem = temp->dataItem;
        this->next = temp->next;
        gotoNext();
        temp = temp->next;
    }

}

template <typename DataType>

List<DataType>& List<DataType>::operator=(const List& other) {
    if (this != &other) {
        ListNode* temp = other.head; //our temp node so we can traverse though other list
        while (temp != nullptr) {
            insert(temp->dataItem); //insert other data items to this
            gotoNext(); //move next
            temp = temp->next;
        }
    }
    return *this; //return this list

}

template <typename DataType>

List<DataType>::~List() {
    ListNode* remove;
    ListNode* temp = head;
    while (temp != NULL) {
        remove = temp;
        temp = temp->next;
        delete remove;
    }
    head = NULL;

}

template <typename DataType>

void List<DataType>::insert(const DataType& newDataItem) throw (logic_error) {

    if (isEmpty()) {
        head = new ListNode(newDataItem,nullptr); //make a head if its empty
        cursor = head; //cursor starts = to head
    }
    else{
        ListNode* temp = cursor; //create a temporary node = to cursor
        cursor = new ListNode(newDataItem, temp->next); //cursor is where we store the new data and have it point to the next node
        temp->next = cursor; //temporary points to cursor, so the prior node will point to the node we just inserted

    }

}

template <typename DataType>

void List<DataType>::remove() throw (logic_error) {
    
    ListNode* remove;

    if (isEmpty()) {
        throw logic_error("Cannot remove from an empty list");
    }

    else if (cursor == head) { //if we are at the beginning we need to make the head the next node
        remove = head; //our remove is at head
        head = head->next;
        gotoNext(); //cursor is the next node , so at the new head
        delete remove; //remove node
    }
    
    else {
        ListNode* past;//mark the node behind the node we want to remove
        remove = cursor; //remove node is at the cursor
        past = head; //start past at the beginning
        
        //we have to traverse the linked list to find the past node
        while( past->next != cursor ) {
            past = past->next;
        }
        //if theres a node after next
        if(cursor->next != nullptr)
            cursor = cursor->next;

        else //otherwise we can set the cursor to the head
            cursor = head;
        
        past->next = remove->next;// re arrange pointers to skip the remove node
        delete remove;
        //lostNode = NULL;

    }

    }

template <typename DataType>

void List<DataType>::replace(const DataType& newDataItem) throw (logic_error) {
    
    if(isEmpty()){
        throw logic_error("Cannot replace from an empty list");
        
    }
    else{
        cursor->dataItem = newDataItem; //change the data Item
    }
}


template <typename DataType>

void List<DataType>::clear() {

    if (isEmpty()) {

        throw logic_error("Cannot clear an empty list");
    }
    else {
        gotoBeginning(); //this sets cursor = head
        ListNode *removed;
        while(cursor != nullptr){ //while theres a node to remove
            removed = head;
            head = head->next;
            cursor = cursor->next;
            delete removed;
        }

       head = NULL;//head and cursor are nothing
        cursor = NULL;

    }

}

template <typename DataType>

bool List<DataType>::isEmpty() const {

    if (head == NULL && cursor == NULL) {
        return true;
    }
    else {
        return false;
    }

}


template <typename DataType>

bool List<DataType>::isFull() const {
    //Dynamic data, assume never full
    return false;

}

template <typename DataType>

void List<DataType>::gotoBeginning() throw (logic_error) {
    if(isEmpty()){
        throw logic_error("Cannot go to beginning from an empty list");
        
    }
    else
        cursor = head; //beginning is where the head is

}

template <typename DataType>

void List<DataType>::gotoEnd() throw (logic_error) {
    
    if(isEmpty()){
        throw logic_error("Cannot go to end from an empty list");
        
    }
    else{
        while(cursor->next != nullptr){
            cursor = cursor->next;
            
        }
    }

}

template <typename DataType>

bool List<DataType>::gotoNext() throw (logic_error) {
    if(isEmpty()){
        throw logic_error("Cannot go to next from an empty list");
        return false;
        
    }
    else {

        if (cursor->next != NULL) {
            cursor = cursor->next;
            return true;
        }
        else {
            return false;
        }
    }


}

template <typename DataType>

bool List<DataType>::gotoPrior() throw (logic_error) {

    if(isEmpty()){
        throw logic_error("Cannot go to prior from an empty list");
        
    }

    else if(cursor != head ){ //are we not at the beginning?
        ListNode *prior = head;
        while(prior->next != cursor) //traverse to go to element behind cursor
            prior = prior->next;
        cursor = prior;
        return true;
    }
    else //otherwise false
        return false;

}

template <typename DataType>

DataType List<DataType>::getCursor() const throw (logic_error) {
    if(isEmpty()){
        throw logic_error("Cannot get cursor from an empty list");
        
    }
    else {
        return cursor->dataItem;

    }


}


template <typename DataType>

void List<DataType>::moveToBeginning () throw (logic_error) {
    if(isEmpty()){
        throw logic_error("Cannot move to beginning from an empty list");
        
    }
    else if(cursor == head){ //if we are already at the beginning, we dont need to move anything
        throw logic_error("Cannot move to beginning if we are at the beginning");

        }
    else{ //otherwise rearrange pointers
            ListNode* prior = head;
            while(prior->next != cursor) {
                prior = prior->next;
            }
            prior->next = cursor->next;
            cursor->next = head;
            head = cursor;
            
            
        }
    
}

// Programming exercise 3

template <typename DataType>

void List<DataType>::insertBefore(const DataType& newDataItem) throw (logic_error) {

    if (isEmpty()) { //if list is empty just insert
        insert(newDataItem);
    }
    //otherwise
    else {
        if (cursor == head) { //if we are at the beginning, we have to rearrange the head
            ListNode * newNode = new ListNode(newDataItem, head);
            head = newNode;
            cursor = newNode;
        }
        else {// if we are not at the begining, go to the previous element and insert
            gotoPrior();
            insert(newDataItem);

        }

    }

}

  
#include "show5.cpp"

