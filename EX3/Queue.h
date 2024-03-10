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
    // Create a new node to store the data from the head of the copied queue
    Node* temp0 = new Node(queue.m_head->data);
    // Pointer to iterate through the original queue
    Node* temp = queue.m_head;
    // Set the head of the new queue to the newly created node
    m_head = temp0;
    // Set the tail of the new queue to the head initially
    m_tail = m_head;

    // Try block to handle potential memory allocation failures
    try {
        // Iterate through the original queue until the end is reached
        while (temp->next != nullptr) {
            // Create a new node with the data from the current node of the original queue
            m_tail->next = new Node(temp->data);
            // Check if memory allocation failed
            if (m_tail == nullptr) {
                // Throw a bad_alloc exception if memory allocation failed
                throw std::bad_alloc();
            }
            // Move the tail pointer to the newly created node
            m_tail = m_tail->next;
            // Move to the next node in the original queue
            temp = temp->next;
        }
    } catch (...) {
        // If an exception occurs during memory allocation, clean up allocated memory
        while (m_head != nullptr) {
            Node* toDelete = m_head;
            m_head = m_head->next;
            delete toDelete;
        }
        // Re-throw the caught exception to propagate it further
        throw;
    }
    // After successful copying, update the length of the new queue
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
    if (this != &queue) { // Check for self-assignment first
        // Temporary queue to hold the copied content
        Queue temp;

        if (queue.m_head != nullptr) { // Check if the source queue is not empty
            // Create the first node of the temporary queue
            Node* tempNode = new Node(queue.m_head->data);
            temp.m_head = tempNode;
            Node* current = queue.m_head->next;

            // Iterate through the source queue and copy nodes
            try {
                while (current != nullptr) {
                    Node* newNode = new Node(current->data); // Might throw std::bad_alloc
                    tempNode->next = newNode;
                    tempNode = newNode;

                    if (current->next == nullptr) { // If this is the last node
                        temp.m_tail = newNode; // Set the tail of the temporary queue
                    }

                    current = current->next; // Move to the next node in the source queue
                }
            } catch (...) {
                // Cleanup in case of an exception and rethrow to maintain exception neutrality
                while (temp.m_head != nullptr) {
                    Node* toDelete = temp.m_head;
                    temp.m_head = temp.m_head->next;
                    delete toDelete;
                }
                throw; // Rethrow the current exception
            }

            temp.m_length = queue.m_length; // Copy the length after successful node copying
        }
        clear(); // Clear the current queue
        // Swap the contents of the temporary queue with the current queue
        std::swap(m_head, temp.m_head);
        std::swap(m_tail, temp.m_tail);
        std::swap(m_length, temp.m_length);

        // The destructor of 'temp' will take care of deallocating the old nodes of 'this' queue
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
        while(m_length > 0){
            popFront();
        }
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
    template <class Predicate, class T>
    Queue<T> filter(const Queue<T>& q, Predicate predicate) {
        Queue<T> filteredQueue;
        for(typename Queue<T>::Iterator i = q.begin(); i!=nullptr; ++i){
            if (predicate(*i)) {
                filteredQueue.pushBack(*i);
            }
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
    template <class Transformer, class T>
    void transform(const Queue<T>& q, Transformer transformer) {
            for(typename Queue<T>::Iterator i = q.begin(); i!=q.end(); ++i){
                *i = transformer(*i);
            }
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
    template <class Reducer, class T>
    T reduce(const Queue<T>& q, T initial,Reducer (*reducer)(Reducer, Reducer)) {
        if (!(q.begin() != q.end())) {
            throw typename Queue<T>::EmptyQueue(); // Queue is empty
        }
        T accumulate = initial;
        for(typename Queue<T>::ConstIterator i = q.begin(); i!=q.end(); ++i){
            accumulate = reducer(accumulate,*i);
        }
        return accumulate;
    }