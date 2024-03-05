#pragma once
#include <stdexcept> 
#include <iostream>

template <class T>
class Queue {
public:
    /*
     * Constructor:
     * Initializes an empty Queue.
     */
    Queue();

    /*
     * Destructor:
     * Cleans up resources used by the Queue.
     */
    ~Queue();

    /*
     * Copy Constructor:
     * Creates a new Queue that is a copy of another Queue.
     *
     * @param queue - Another Queue object to copy.
     */
    Queue(const Queue& queue);

    /*
     * Assignment Operator:
     * Assigns the contents of another Queue to this Queue.
     *
     * @param queue - Another Queue object to assign.
     * @return Reference to this Queue after assignment.
     */
    Queue& operator=(const Queue& queue);

    /*
     * Assignment Operator:
     * Assigns a new value to the first element in the Queue.
     *
     * @param element - New value to assign to the first element in the Queue.
     * @return Reference to this Queue after assignment.
     */
    void pushBack(T element);

    /*
     * front:
     * Retrieves and returns the value of the first element in the Queue without removing it.
     * Throws a std::out_of_range exception if the Queue is empty.
     *
     * @return reference to the first element in the Queue. 
     */
    T& front();

    /*
     * popFront:
     * Removes the first element from the Queue.
     * Throws a std::out_of_range exception if the Queue is empty.
     */
    void popFront();

    /*
     * size:
     * Returns the number of elements in the Queue.
     *
     * @return Number of elements in the Queue.
     */
    int size();

    // Iterator class forward declaration
    class Iterator;
    class ConstIterator;

    /*
    * Function to obtain an iterator pointing to the beginning of the Queue.
    *
    * @return ConstIterator pointing to the beginning of the Queue.
    */
    ConstIterator  begin() const;

    /*
    * Function to obtain an iterator pointing to the end of the Queue (nullptr).
    *
    * @return ConstIterator pointing to the end of the Queue (nullptr).
    */
    ConstIterator  end() const;
    
    class EmptyQueue {};
    class InvalidOperation{};

private:
    struct Node {
        T data;
        Node* next;
    };  
    Node* m_head;
    Node* m_tail;
    int m_length;

public:

    /*
     * filter:
     * Filters the elements of the Queue using a given predicate function.
     * The original Queue is not modified.
     * The given predicate function is applied to each element in the Queue.
     * The function should take a single argument of type T and return a boolean value.
     * A new Queue is created containing only the elements for which the predicate function returns true.
     * @param predicate - Predicate function to apply to each element in the Queue.
     * @return New Queue containing only the elements for which the predicate function returns true.
     */
    template <class U>
    friend Queue<T> filter(const Queue<T>& q, bool (*predicate)(U));

    /*
     * transform:
     * Transforms the elements of the Queue using a given function.
     * The original Queue is modified in place.
     * The given function is applied to each element in the Queue.
     * The function should take a single argument of type T and return a value of type T.
     * The original element is replaced with the result of the function.
     * @param transformer - Function to apply to each element in the Queue.
     * @return Reference to this Queue after transformation.
     */
    template <class U>
    friend Queue<T> transform(const Queue<T>& q, T (*transformer)(U));

    /*
     * reduce:
     * Reduces the elements of the Queue using a given reducer function.
     * The original Queue is not modified.
     * The given reducer function is applied to each element in the Queue.
     * The function should take two arguments of type T and return a value of type T.
     * The result of the function is used as the first argument in the next call to the function.
     * The initial value is used as the second argument in the first call to the function.
     * @param Queue - Queue to reduce.
     * @param initial - Initial value to use in the first call to the reducer function.
     * @param reducer - Reducer function to apply to each element in the Queue.
     * @return Result of the reduction.
     */ 
    template <class U>
    friend T reduce(const Queue<T>& q, U initial, U (*reducer)(U, U));
};

// Iterator class declaration
template <class T>
class Queue<T>::Iterator {
private:
    typename Queue<T>::Node* m_current; // Pointer to the current node
    friend class constIterator;


public: 


    /*
     * Constructor:
     * Initializes the iterator with a pointer to the given node.
     *
     * @param ptr - Pointer to a Node in the Queue.
     */

    Iterator(const typename Queue<T>::ConstIterator& other);

    /*
     * Constructor:
     * Initializes the iterator with a pointer to the given node.
     *
     * @param ptr - Pointer to a Node in the Queue.
     */
    Iterator(typename Queue<T>::Node* ptr);

    /*
     * Overloaded dereference operator:
     * Returns a reference to the data stored in the current node.
     *
     * @return Reference to the data of the current node.
     */
    T& operator*() const;

    /*
     * Overloaded pre-increment operator:
     * Moves the iterator to the next node in the Queue.
     *
     * @return Reference to the updated iterator.
     */
    Iterator& operator++();

    /*
     * Overloaded inequality operator:
     * Compares two iterators for inequality.
     *
     * @param other - Another Iterator object to compare with.
     * @return True if the iterators are not pointing to the same node, false otherwise.
     */
    bool operator!=(const Iterator& other) const;

    /*
    * Function to obtain an iterator pointing to the beginning of the Queue.
    *
    * @return Iterator pointing to the beginning of the Queue.
    */
    Iterator  begin() const;

    /*
    * Function to obtain an iterator pointing to the end of the Queue (nullptr).
    *
    * @return Iterator pointing to the end of the Queue (nullptr).
    */
    Iterator  end() const;

    class InvalidOperation{};
};





template <class T>
class Queue<T>::ConstIterator {
private:
    typename Queue<T>::Node* m_current; // Pointer to the current node

public:
    /*
     * Constructor:
     * Initializes the iterator with a pointer to the given node.
     *
     * @param ptr - Pointer to a Node in the Queue.
     */
    ConstIterator(typename Queue<T>::Node* ptr);

    /*
     * Overloaded dereference operator:
     * Returns a reference to the data stored in the current node.
     *
     * @return Reference to the data of the current node.
     */
    T& operator*() const;

    /*
     * Overloaded pre-increment operator:
     * Moves the iterator to the next node in the Queue.
     *
     * @return Reference to the updated iterator.
     */
    ConstIterator& operator++();

    /*
     * Overloaded inequality operator:
     * Compares two iterators for inequality.
     *
     * @param other - Another Iterator object to compare with.
     * @return True if the iterators are not pointing to the same node, false otherwise.
     */
    bool operator!=(const ConstIterator& other) const;
    class InvalidOperation{};
};

/*
 * Constructor implementation.
 */
template <class T>
Queue<T>::ConstIterator::ConstIterator(typename Queue<T>::Node* ptr) : m_current(ptr) {}

/*
 * Overloaded dereference operator implementation.
 */
template <class T>
T& Queue<T>::ConstIterator::operator*() const {
    return m_current->data; // Return reference to the data of the current node
}

/*
 * Overloaded pre-increment operator implementation.
 */
template <class T>
typename Queue<T>::ConstIterator& Queue<T>::ConstIterator::operator++() {
    m_current = m_current->next; // Move the iterator to the next node
    return *this; // Return reference to the updated iterator
}

/*
 * Overloaded inequality operator implementation.
 */
template <class T>
bool Queue<T>::ConstIterator::operator!=(const ConstIterator& other) const {
    return m_current != other.m_current; // Compare if the iterators are not pointing to the same node
}
