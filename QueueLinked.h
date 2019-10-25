// QueueLinked.h

#ifndef QUEUELINKED_H
#define QUEUELINKED_H

#include <stdexcept>
#include <iostream>

using namespace std;

#include "Queue.h"

template <typename DataType>
class QueueLinked : public Queue<DataType> {
  public:
    /*Constructor
     Pre: none
     Post: Creates an empty queue.
     */
    QueueLinked(int maxNumber = Queue<DataType>::MAX_QUEUE_SIZE);
    
    /* Copy Constructor
     Pre: none
     Post: Initializes the queue to be equivalent to the other Queue object parameter.
     */
    QueueLinked(const QueueLinked& other);
    
    /*Operator
     Pre: none
     Post: Overloaded assigment operator. Sets the queue to be equivalent to the other Queue object paramter and returns a reference to the modified queue.
     */
    QueueLinked& operator=(const QueueLinked& other);
    
    /*Destructor
     Pre: none
     Post: Deallocates the memory used to store the queue.
     */
    ~QueueLinked();
    
    /*Enqueue
     Pre: Queue is not full.
     Post: Inserts newDataItem at the rear of the queue.
     */
    void enqueue(const DataType& newDataItem) throw (logic_error);
    
    /*Dequeue
     Pre: Queue is not empty.
     Post: Removes the least recently added(front) data item from the queue and returns it.
     */
    DataType dequeue() throw (logic_error);
    
    /*clear()
     Pre: none
     Post: Removes all the data items in the queue.
     */
    void clear();

    /*isEmpty
     Pre: none
     Post: Returns true if the queue is empty. Otherwise, returns false.
     */
    bool isEmpty() const;
    
    /*isFull
     Pre: none
     Post: Returns true if the queue is full. Otherwise, returns false.
     */
    bool isFull() const;

    // Programming Exercise 2
    void putFront(const DataType& newDataItem) throw (logic_error);
    DataType getRear() throw (logic_error);
    // Programming Exercise 3
    int getLength() const;

    /*showStructure
     Pre: none
     Post: Outputs the data items in the queue.
     */
    void showStructure() const;

  private:
    class QueueNode {
      public:
        
    /*Constructor
    Pre: none.
    Post: Creates an initialized QueueNode.
    */
	QueueNode(const DataType& nodeData, QueueNode* nextPtr);

	DataType dataItem;
	QueueNode* next;
    };

    QueueNode* front;
    QueueNode* back;
};

/*Constructor
 Pre: none
 Post: Creates an initialized QueueNode.
 */
template <typename DataType>
QueueLinked<DataType>::QueueNode::QueueNode(const DataType& nodeData, QueueNode* nextPtr)
{
    dataItem = nodeData;
    next = nextPtr;
}


/*Constructor
 Pre: none
 Post: Creates an empty queue.
 */
template <typename DataType>
QueueLinked<DataType>::QueueLinked(int maxNumber)
    :front(NULL), back(NULL)
{
    
}


/* Copy Constructor
 Pre: none
 Post: Initializes the queue to be equivalent to the other Queue object parameter.
 */
template <typename DataType>
QueueLinked<DataType>::QueueLinked(const QueueLinked& other)
//    :front(NULL), back(NULL)
{
    operator= (other);
}



/*Operator
 Pre: none
 Post: Overloaded assigment operator. Sets the queue to be equivalent to the other Queue object paramter and returns a reference to the modified queue.
 */
template <typename DataType>
QueueLinked<DataType>& QueueLinked<DataType>::operator=(const QueueLinked& other)
{
  if(*this != other)
  {
      clear();
  }

  while(other.front->next != NULL)
  {
      DataType temp = other.dequeue();
      enqueue(temp);
  }
}



/*Destructor
 Pre: none
 Post: Deallocates the memory used to store the queue.
 */
template <typename DataType>
QueueLinked<DataType>:: ~QueueLinked()
{
    clear();
}



/*Enqueue
 Pre: Queue is not full.
 Post: Inserts newDataItem at the rear of the queue.
 */
template <typename DataType>
void QueueLinked<DataType>::enqueue(const DataType& newDataItem) throw (logic_error)
{
    if(isFull())
    {
        throw logic_error ("The queue is full.");
    }
    QueueNode* temp = new QueueNode(newDataItem, 0);
    
    if(isEmpty())
    {
        front = temp;
    }
    else
    {
        back->next = temp;
    }
    back = temp;
}



/*Dequeue
 Pre: Queue is not empty.
 Post: Removes the least recently added(front) data item from the queue and returns it.
 */
template <typename DataType>
DataType QueueLinked<DataType>::dequeue() throw (logic_error)
{
    if(isEmpty())
    {
        throw logic_error ("The queue is empty.");
    }
    
    DataType temp = front->dataItem;
    QueueNode* ptr = front;
    front = front->next;
    delete ptr;
    
    return temp;
}



/*clear()
 Pre: none
 Post: Removes all the data items in the queue.
 */
template <typename DataType>
void QueueLinked<DataType>::clear()
{
    while(!isEmpty())
    {
        dequeue();
    }
}



/*isEmpty
 Pre: none
 Post: Returns true if the queue is empty. Otherwise, returns false.
 */
template <typename DataType>
bool QueueLinked<DataType>::isEmpty() const
{
    return (front == NULL);
}



/*isFull
 Pre: none
 Post: Returns true if the queue is full. Otherwise, returns false.
 */
template <typename DataType>
bool QueueLinked<DataType>::isFull() const
{
    return false;
}


/*showStructure
 Pre: none
 Post: Outputs the data items in the queue.
 */

// Linked list implementation. Outputs the elements in a queue. If
// the queue is empty, outputs "Empty queue". This operation is
// intended for testing and debugging purposes only.

template <typename DataType>
void QueueLinked<DataType>:: showStructure () const
{
    QueueNode *p;   // Iterates through the queue
    
    if ( isEmpty() )
        cout << "Empty queue" << endl;
    else
    {
        cout << "Front\t";
        for ( p = front ; p != 0 ; p = p->next )
        {
            if( p == front )
            {
                cout << '[' << p->dataItem << "] ";
            }
            else
            {
                cout << p->dataItem << " ";
            }
        }
        cout << "\trear" << endl;
    }
}

#endif
