#include "Queue.h"
#include <iostream>;

template <class T>
Queue<T>::Queue(){
    m_head = nullptr;
    m_tail = nullptr;
    m_length = 0;

}

template <class T>
Queue<T>::~Queue(){
    while(m_head!=nullptr){
        Node* temp = m_head->next;
        delete m_head;
        m_head = temp;
        
    }
}

template <class T>
Queue<T>::Queue(const Queue& queue) {
    Node* temp0 = new Node(queue.m_head->data);
    if(temp0 == nullptr){
        throw std::bad_alloc;
    }
    while(m_head!=nullptr){
        Node* temp = m_head->next;
        delete m_head;
        m_head = temp;
    }
    Node* temp = queue.m_head;
    m_head = temp0;
    m_tail = m_head;
    while (temp->next!=nullptr){
        m_tail->next = new Node(temp->data);
        if(m_tail == nullptr){
             throw std::bad_alloc;
        }
        m_tail = m_tail->next;
        temp=temp->next;
    }
    m_length = queue.m_length;
}


template <class T>
void Queue<T>::pushBack(T element){
    Node* newNode = new Node(element);
    if(newNode == nullptr){
        throw std::bad_alloc;
    }
    if(m_head == nullptr){
        m_head = newNode;
        m_tail = newNode;
    }
    else{
        m_tail->next = newNode;
        m_tail = m_tail->next;
    }
    m_length++;
}

template <class T>
T Queue<T>::front(){
    if(m_head == nullptr){
        throw EmptyQueue(); //queue is empty
    }
    return m_head->data;
}

template <class T>
void Queue<T>::popFront(){
    if(m_head == nullptr){
        throw EmptyQueue(); //queue is empty
    }
        Node* temp = m_head;
        m_head = m_head->next;
        delete temp;
        m_length--;
    }


template <class T>
int Queue<T>::size(){
    if(m_head == nullptr){
        return 0;
    }
    return m_length;
}


template <class T>
Queue<T> filter(const Queue<T>& q, bool (*predicate)(T)) {
    Queue<T> filteredQueue;
    typename Queue<T>::Node* temp = q.m_head;
    while (temp != nullptr) {
        if (predicate(temp->data)) {
            filteredQueue.pushBack(temp->data);
        }
        temp = temp->next;
    }
    return filteredQueue;
}

template <class T>
Queue<T> transform(const Queue<T>& q, T (*transformer)(T)) {
    Queue<T> transformedQueue = q; // Make a copy of the input queue
    typename Queue<T>::Node* temp = transformedQueue.m_head;
    while (temp != nullptr) {
        temp->data = transformer(temp->data);
        temp = temp->next;
    }
    return transformedQueue;
}

template <class T>
T reduce(const Queue<T>& q, T initial,T (*reducer)(T, T)) {
    if (q.m_head == nullptr) {
        throw EmptyQueue(); // Queue is empty
    }
    T accumulate = initial;
    typename Queue<T>::Node* temp = q.m_head;
    while (temp != nullptr) {
        accumulate = reducer(temp->data, accumulate);
        temp = temp->next;
    }
    return accumulate;
}


template <class T>
Queue<T>::Iterator::Iterator(typename Queue<T>::Node* ptr){
    m_current = ptr;
}


template <class T>
T& Queue<T>::Iterator::operator*() const {
    if(m_current == nullptr){
        throw InvalidOperation();
    }
    return m_current->data;
}

template <class T>
bool Queue<T>::Iterator::operator!=(const typename Queue<T>::Iterator& other) const {
    return m_current != other.m_current;
}


template <class T>
typename Queue<T>::Iterator Queue<T>::begin() const {
    return Iterator(m_head);
}

template <class T>
typename Queue<T>::Iterator Queue<T>::end() const {
    if(m_head == nullptr){
        return Iterator(nullptr);
    }
    return Iterator(m_tail->next);
}

template <class T>
typename Queue<T>::Iterator& Queue<T>::Iterator::operator++(){
        if(m_current == nullptr){
        throw InvalidOperation(); //queue is empty
    }
    m_current = m_current->next;
    return *this;
}
    
