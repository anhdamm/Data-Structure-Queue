// QueueArray.h

#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H

#include <stdexcept>
#include <iostream>

using namespace std;

#include "Queue.h"

template <typename DataType>
class QueueArray : public Queue<DataType> {
  public:
    /*Constructor
     Pre: none
     Post: Creates an empty queue.
     */
    QueueArray(int maxNumber = Queue<DataType>::MAX_QUEUE_SIZE);
    
    /* Copy Constructor
     Pre: none
     Post: Initializes the queue to be equivalent to the other Queue object parameter.
     */
    QueueArray(const QueueArray& other);
    
    /*Operator
     Pre: none
     Post: Overloaded assigment operator. Sets the queue to be equivalent to the other Queue object paramter and returns a reference to the modified queue.
     */
    QueueArray& operator=(const QueueArray& other);
    
    
    /*Destructor
     Pre: none
     Post: Deallocates the memory used to store the queue.
     */
    ~QueueArray();

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

    void putFront(const DataType& newDataItem) throw (logic_error);
    DataType getRear() throw (logic_error);
    int getLength() const;
    
    /*showStructure
     Pre: none
     Post: Outputs the data items in the queue.
     */
    void showStructure() const;

  private:
    int maxSize;
    int front;
    int back;
    DataType* dataItems;
};

/*Constructor
 Pre: none
 Post: Creates an empty queue.
 */
template <typename DataType>
QueueArray<DataType>::QueueArray(int maxNumber)
    :maxSize(maxNumber), front(-1), back(-1)
{
    dataItems = new DataType[maxSize];
}


/* Copy Constructor
 Pre: none
 Post: Initializes the queue to be equivalent to the other Queue object parameter.
 */
template <typename DataType>
QueueArray<DataType>::QueueArray(const QueueArray& other)
{
    operator= (other);
}



/*Operator
 Pre: none
 Post: Overloaded assigment operator. Sets the queue to be equivalent to the other Queue object paramter and returns a reference to the modified queue.
 */
template <typename DataType>
QueueArray<DataType>& QueueArray<DataType>::operator=(const QueueArray& other)
{
    if(this != other)
    {
        clear();
    }
    
    QueueArray(other.maxNumber);
    for(int i = 0; i < maxSize; i++)
    {
        for(int j = 0; j < maxSize; j++)
        {
            DataType temp = other.dequeue();
            enqueue(temp);
        }
    }
}



/*Destructor
 Pre: none
 Post: Deallocates the memory used to store the queue.
 */
template <typename DataType>
QueueArray<DataType>::~QueueArray()
{
    clear();
}



/*Enqueue
 Pre: Queue is not full.
 Post: Inserts newDataItem at the rear of the queue.
 */
template <typename DataType>
void QueueArray<DataType>::enqueue(const DataType& newDataItem) throw (logic_error)
{
    if(isFull())
    {
        throw logic_error ("Queue is full.");
    }
    else
    {
        back = (back+1) % maxSize ;//(++back) % maxSize;
        dataItems[back] = newDataItem;
        if(front == -1)
        {
            front = 0;
        }
    }
}



/*Dequeue
 Pre: Queue is not empty.
 Post: Removes the least recently added(front) data item from the queue and returns it.
 */
template <typename DataType>
DataType QueueArray<DataType>::dequeue() throw (logic_error)
{
    int index = front;
    if(isEmpty())
    {
        throw logic_error ("Queue is empty.");
    }
    else
    {
        if(front == back)
        {
            clear();
        }
        else
        {
            front = (front + 1) % maxSize; //(++front) % maxSize;
        }
        return dataItems[index];
    }
}



/*clear()
 Pre: none
 Post: Removes all the data items in the queue.
 */
template <typename DataType>
void QueueArray<DataType>::clear()
{
    front = -1;
    back = -1;
}


/*isEmpty
 Pre: none
 Post: Returns true if the queue is empty. Otherwise, returns false.
 */
template <typename DataType>
bool QueueArray<DataType>::isEmpty() const
{
    return (front == -1);
}



/*isFull
 Pre: none
 Post: Returns true if the queue is full. Otherwise, returns false.
 */
template <typename DataType>
bool QueueArray<DataType>::isFull() const
{
    return (front == (back +1) % maxSize);
}
    
    

//template <typename DataType>
//void QueueArray<DataType>::putFront(const DataType& newDataItem) throw (logic_error)



//template <typename DataType>
//DataType QueueArray<DataType>::getRear() throw (logic_error)



//template <typename DataType>
//int QueueArray<DataType>::getLength() const



/*showStructure
 Pre: none
 Post: Outputs the data items in the queue.
 */
template <typename DataType>
void QueueArray<DataType>::showStructure() const
{
    int j;    //Loop counter
    
    if ( front == -1 )
        cout << "Empty queue" << endl;
    else
    {
        cout << "Front = " << front << "  Back = " << back << endl;
        for ( j = 0 ; j < maxSize ; j++ )
            cout << j << "\t";
        cout << endl;
        if ( back >= front )
            for ( j = 0 ; j < maxSize ; j++ )
                if ( ( j >= front ) && ( j <= back ) )
                    cout << dataItems[j] << "\t";
                else
                    cout << " \t";
                else
                    for ( j = 0 ; j < maxSize ; j++ )
                        if ( ( j >= front ) || ( j <= back ) )
                            cout << dataItems[j] << "\t";
                        else
                            cout << " \t";
        cout << endl;
    }
}

#endif
