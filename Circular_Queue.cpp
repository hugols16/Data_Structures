#include "CircularQueue.hpp"
#include <stddef.h>
#include <iostream>

typedef CircularQueue::QueueItem QueueItem;  // for simplicity
const QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue()
{
          items_ = new QueueItem[16];
          head_ = 0;
          tail_ = 0;
          size_ = 0;
          capacity_ = 16;                    
}

CircularQueue::~CircularQueue()
{
 delete [] items_;
}

bool CircularQueue::empty() const
{
     if (size_ == 0)
     return true;
     else
     return false; 
}

bool CircularQueue::full() const
{ 
     if(head_ == tail_ && size_ != 0)
     return true;
     else
     return false;
}

int CircularQueue::size() const
{ 
    return size_;
}

bool CircularQueue::enqueue(QueueItem value)
{
     if(!full())
     {
                items_[tail_] = value;
                size_++;
                tail_ = (tail_+1)%capacity_;
                return true;
     }
     else
     return false;
}

QueueItem CircularQueue::dequeue()
{
          if(!empty())
          {
                      QueueItem temp = items_[head_];
                      head_= (head_+1)%capacity_;
                      size_--;
                      return temp ;
          }
          return EMPTY_QUEUE;
}

QueueItem CircularQueue::peek() const
{
         if(!empty())
         return items_[head_];
         else
         return EMPTY_QUEUE;
}

void CircularQueue::print() const
{
     if (!empty())
     {
     std::cout << "[";
     for(int i = 0; i<size_ ; i++)
     {
             std::cout << items_[(i+head_)%capacity_] << " ";
     }
     std::cout << "]";
     }
     else
     std::cout << "EMPTY";
     
}
