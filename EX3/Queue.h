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
    Queue() {
        m_head = nullptr;
        m_tail = nullptr;
        m_length = 0;
    }

    /*
     * Destructor:
     * Cleans up resources used by the Queue.
     */
    ~Queue() {
        clear();
    }
    /*
     * Copy Constructor:
     * Creates a new Queue that is a copy of another Queue.
     *
     * @param queue - Another Queue object to copy.
     */
    Queue(const Queue& queue) {
        Node* temp0 = new Node(queue.m_head->data);
        Node* temp = queue.m_head;
        m_head = temp0;
        m_tail = m_head;
        while (temp->next != nullptr) {
            m_tail->next = new Node(temp->data);
            if (m_tail == nullptr) {
                throw std::bad_alloc();
            }
            m_tail = m_tail->next;
            temp = temp->next;
        }
        m_length = queue.m_length;
    }

    /*
     * Assignment Operator:
     * Assigns the contents of another Queue to this Queue.
     *
     * @param queue - Another Queue object to assign.
     * @return Reference to this Queue after assignment.
     */
    Queue& operator=(const Queue& queue) {
        if (this != &queue) { // Check for self-assignment
            if (queue.m_head == nullptr) { // Check if the queue is empty
                m_head = nullptr;
                m_tail = nullptr;
                m_length = 0;
                return *this;
            }
            m_head = new Node(queue.m_head->data);
            Node* temp = queue.m_head->next;
            Node* current = m_head;
            while (temp != nullptr) {
                current->next = new Node(temp->data);
                current = current->next;
                temp = temp->next;
            }
            m_tail = current;
            m_length = queue.m_length;
        }
        return *this;
    }

    /*
     * Assignment Operator:
     * Assigns a new value to the first element in the Queue.
     *
     * @param element - New value to assign to the first element in the Queue.
     * @return Reference to this Queue after assignment.
     */
    void pushBack(T element) {
        Node* newNode = new Node(element);
        if (newNode == nullptr) {
            throw std::bad_alloc();
        }
        if (m_head == nullptr) {
            m_head = newNode;
            m_tail = newNode;
        }
        else {
            m_tail->next = newNode;
            m_tail = m_tail->next;
        }
        m_length++;
    }

    /*
     * front:
     * Retrieves and returns the value of the first element in the Queue without removing it.
     * Throws a std::out_of_range exception if the Queue is empty.
     *
     * @return reference to the first element in the Queue. 
     */
    T& front() {
        if (m_head == nullptr) {
            throw EmptyQueue(); //queue is empty
        }
        return m_head->data;
    }


        /*
     * front:
     * Retrieves and returns the value of the first element in the Queue without removing it.
     * Throws a std::out_of_range exception if the Queue is empty.
     *
     * @return reference to the first element in the Queue. 
     */
    const T& front()const {
        if (m_head == nullptr) {
            throw EmptyQueue(); //queue is empty
        }
        return m_head->data;
    }


    /*
     * popFront:
     * Removes the first element from the Queue.
     * Throws a std::out_of_range exception if the Queue is empty.
     */
    void popFront() {
        if (m_head == nullptr) {
            throw EmptyQueue(); //queue is empty
        }
        Node* temp = m_head;
        m_head = m_head->next;
        delete temp;
        m_length--;
    }

    /*
     * size:
     * Returns the number of elements in the Queue.
     *
     * @return Number of elements in the Queue.
     */
    const int size()const {
        if (m_head == nullptr) {
            return 0;
        }
        return m_length;
    }


    // Iterator class forward declaration
    class Iterator;
    class ConstIterator;

    /*
     * Function to obtain an iterator pointing to the beginning of the Queue.
     *
     * @return ConstIterator pointing to the beginning of the Queue.
     */
    ConstIterator begin() const {
        return ConstIterator(m_head);
    }

    /*
     * Function to obtain an iterator pointing to the end of the Queue (nullptr).
     *
     * @return ConstIterator pointing to the end of the Queue (nullptr).
     */
    ConstIterator end() const {
        if (m_tail == nullptr) {
            return ConstIterator(nullptr);
        }
        return ConstIterator(m_tail->next);
    };
    class EmptyQueue {};
    class InvalidOperation{};


    void print () const {
        Node* temp = m_head;
            while (temp != nullptr) {
                std::cout << temp->data << " ";
                temp = temp->next;
    }       
        std::cout << std::endl;  
   }
private:
    /*  
    * clear:
    * Clears the Queue and frees the memory used by the elements.
    * The Queue is left in an empty state.
    * This function is called by the destructor and the assignment operator.
    * @return void
    */

    void clear() {
        while (m_head != nullptr&&m_length>0) {
            Node* temp = m_head;
            m_head = m_head->next;
            delete temp;
            m_length--; 
        }
        m_head = nullptr;
        m_tail = nullptr;
        m_length = 0;
    }


    struct Node {
        T data;
        Node* next;

        Node(T data) {
            this->data = data;
            this->next = nullptr;
        }

        ~Node() {
        }
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
    template <class Predicate>
    friend Queue<T> filter(const Queue<T>& q, Predicate predicate) {
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
    template <class Transformer>
    friend Queue<T> transform(const Queue<T>& q, Transformer transformer) {
        typename Queue<T>::Node* temp = q.m_head;
        while (temp != nullptr) {
            temp->data = transformer(temp->data);
            temp = temp->next;
        }
        return q;
    }

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
    template <class Reducer>
    friend T reduce(const Queue<T>& q, T initial,Reducer (*reducer)(Reducer, Reducer)) {
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

    // Iterator class declaration
    class Iterator {
    private:
        typename Queue<T>::Node* m_current; // Pointer to the current node
        friend class ConstIterator;

    public: 
        /*
         * Constructor:
         * Initializes the iterator with a pointer to the given node.
         *
         * @param ptr - Pointer to a Node in the Queue.
         */
        Iterator(typename Queue<T>::Node* ptr) : m_current(ptr) {}

        Iterator(const typename Queue<T>::ConstIterator& other) {
            m_current = const_cast<typename Queue<T>::Node*>(other.m_current);
        }

        /*
         * Overloaded dereference operator:
         * Returns a reference to the data stored in the current node.
         *
         * @return Reference to the data of the current node.
         */
        T& operator*() const {
            return m_current->data;
        }

        /*
         * Overloaded pre-increment operator:
         * Moves the iterator to the next node in the Queue.
         *
         * @return Reference to the updated iterator.
         */
        Iterator& operator++() {
            if(m_current == nullptr){
                throw typename  Iterator::InvalidOperation();
            }
            m_current = m_current->next;
            return *this;
        }

        /*
         * Overloaded inequality operator:
         * Compares two iterators for inequality.
         *
         * @param other - Another Iterator object to compare with.
         * @return True if the iterators are not pointing to the same node, false otherwise.
         */
        bool operator!=(const Iterator& other) const {
            return m_current != other.m_current;
        }

        class InvalidOperation{};
    };

    class ConstIterator {
    private:
        typename Queue<T>::Node* m_current; // Pointer to the current node
        friend class Iterator;
        

    public:
        /*
         * Constructor:
         * Initializes the iterator with a pointer to the given node.
         *
         * @param ptr - Pointer to a Node in the Queue.
         */
        ConstIterator(typename Queue<T>::Node* ptr) : m_current(ptr) {}

        /*
         * Overloaded dereference operator:
         * Returns a reference to the data stored in the current node.
         *
         * @return Reference to the data of the current node.
         */
        T& operator*() const {
            return m_current->data;
        }

        /*
         * Overloaded pre-increment operator:
         * Moves the iterator to the next node in the Queue.
         *
         * @return Reference to the updated iterator.
         */
        ConstIterator& operator++() {
            if(m_current == nullptr){
                throw typename ConstIterator::InvalidOperation();
            }
            m_current = m_current->next;
            return *this;
        }


        /*
         * Overloaded inequality operator:
         * Compares two iterators for inequality.
         *
         * @param other - Another Iterator object to compare with.
         * @return True if the iterators are not pointing to the same node, false otherwise.
         */
        bool operator!=(const ConstIterator& other) const {
            return m_current != other.m_current;
        }

        class InvalidOperation{};
    };







};