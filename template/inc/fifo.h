/**
* @file fifo.h
* @brief FIFO base class
* @details 
*/

#ifndef __FIFO_H__
#define __FIFO_H__

template <typename T, int Capacity>
class FIFO {
public:
    FIFO();
    virtual ~FIFO();
    bool Enqueue(const T& item);
    bool Dequeue(T* item);
    bool IsEmpty() const;
    bool IsFull() const;
    int GetSize() const;  // Changed back to int

protected:
    virtual void VLock();
    virtual void VUnlock(); 

private:
    T mBuffer[Capacity + 1];
    int mCapacity;
    int mHead;
    int mTail;
};

template <typename T, int Capacity>
FIFO<T, Capacity>::FIFO() : mCapacity(Capacity), mHead(0), mTail(0) {}

template <typename T, int Capacity>
FIFO<T, Capacity>::~FIFO() {}

/**
* @brief Enqueue
* @param const T& item - Item to enqueue
* @return bool - Returns true if enqueue succeeded, false if full.
* @details Adds an item to the FIFO queue.
*/
template <typename T, int Capacity>
bool FIFO<T, Capacity>::Enqueue(const T& item)
{
    VLock();
    if (IsFull()) {
        VUnlock();
        return false;  // Queue is full
    }
    mBuffer[mTail] = item;
    mTail = (mTail + 1) % (mCapacity + 1);  // Update tail index
    VUnlock();
    return true;  // Enqueue succeeded
}

/**
* @brief Dequeue
* @param T* item - Pointer to store the dequeued item
* @return bool - Returns true if dequeue succeeded, false if empty.
* @details Removes an item from the FIFO queue.
*/
template <typename T, int Capacity>
bool FIFO<T, Capacity>::Dequeue(T* item)
{
    VLock();
    if (IsEmpty()) {
        VUnlock();
        return false;  // Queue is empty
    }
    *item = mBuffer[mHead];  // Retrieve the head item
    mHead = (mHead + 1) % (mCapacity + 1);  // Update head index
    VUnlock();
    return true;  // Dequeue succeeded
}

/**
* @brief IsEmpty
* @param none
* @return bool - Returns true if FIFO is empty.
* @details Checks if the FIFO queue is empty.
*/
template <typename T, int Capacity>
bool FIFO<T, Capacity>::IsEmpty() const
{
    return mHead == mTail;  // Check if head and tail are the same
}

/**
* @brief IsFull
* @param none
* @return bool - Returns true if FIFO is full.
* @details Checks if the FIFO queue is full.
*/
template <typename T, int Capacity>
bool FIFO<T, Capacity>::IsFull() const
{
    return (mTail + 1) % (mCapacity + 1) == mHead;  // Check if next tail would overlap head
}

/**
* @brief GetSize
* @param none
* @return int - Current size of the FIFO.
* @details Gets the current number of items in the FIFO.
*/
template <typename T, int Capacity>
int FIFO<T, Capacity>::GetSize() const
{
    return (mTail + (mCapacity + 1) - mHead) % (mCapacity + 1);  // Get current size
}

/**
* @brief VLock
* @param none
* @return none
* @details FIFO Lock. Implement with Mutex or DisableIRQ.
*/
template <typename T, int Capacity>
void FIFO<T, Capacity>::VLock() {}

/**
* @brief VUnlock
* @param none
* @return none
* @details FIFO Unlock. Implement with Mutex or EnableIRQ.
*/
template <typename T, int Capacity>
void FIFO<T, Capacity>::VUnlock() {}

#endif  // __FIFO_H__
