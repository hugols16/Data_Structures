#include "PriorityQueue.hpp"
#include <iostream>

using namespace std;

typedef PriorityQueue::DataType DataType;

PriorityQueue::PriorityQueue(unsigned int capacity)
{
   capacity_ = capacity;
   size_ = 0;
   heap_ = new DataType[capacity_+1]; 
}
    
PriorityQueue::~PriorityQueue() 
{
    delete [] heap_;
}
    
bool PriorityQueue::enqueue(DataType val) 
{
    if(full())
    {
    return false;
    std::cout << "FALSE!" << endl;
    }
    else
    {
        size_++;
        int index = size_;
        heap_[index] = val;
        while(index/2 > 0)
        {
         if(heap_[index] > heap_[index/2])
         {
                         heap_[index] = heap_[index/2];
                         heap_[index/2] = val;
                         index /= 2;
         }
         else
         break;
        }
        return true;
    }
}
    
bool PriorityQueue::dequeue()
{
    if(empty())
    return false;
    else
        {
                 int index = 1;
                 heap_[index] = heap_[size_];
                 while(index*2 <= size_ || (index*2 + 1) <= size_)
                 {
                 DataType temp = heap_[index];
                 int tempIndex = index;
                  if(heap_[index*2+1] > size_)
                  {
                   if(heap_[index] < heap_[index*2])
                   {
                    temp = heap_[index*2];
                    tempIndex = index*2;
                   }
                  }
                  else if(heap_[index*2] <= heap_[index*2 + 1])
                  {
                       temp = heap_[index*2+1];
                       tempIndex = index*2 +1;
                  }
                  heap_[tempIndex] =   heap_[index];
                  heap_[index] = temp;
                 }
        }
        size_--;
        return true;    
}
    
DataType PriorityQueue::max() const
{
    if(!empty())
    return heap_[1];
    else
    return -1;
}
    
bool PriorityQueue::empty() const
{
    if(size_ ==0)
     return true;
    else
    return false;
}
    
bool PriorityQueue::full() const
{
    if(size_ == capacity_)
    return true;
    else
    return false;
}
    
unsigned int PriorityQueue::size() const
{
    return size_;
}
    
void PriorityQueue::print() const 
{

    std::cout << "[ ";
    for (int i=1; i<size_+1; i++)
    {
        std::cout << heap_[i] << " ";
    }
    std::cout << "]";



}
