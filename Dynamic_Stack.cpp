#include "DynamicStack.hpp"
#include <stddef.h>
#include <iostream>

typedef DynamicStack::StackItem StackItem;  // for simplicity
const StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack()
{
                            capacity_  = 16;
                            init_capacity_ = 16;
                            size_ = 0;
                            items_ = new StackItem[16];
}

DynamicStack::DynamicStack(unsigned int capacity)
{
 if(capacity!=0)
 {
 init_capacity_ = capacity; 
 capacity_ = capacity;
 }
 else
 {
 capacity_  = 16;
 init_capacity_ = 16;
 }
 size_ = 0;
 items_ = new StackItem[init_capacity_];
}

DynamicStack::~DynamicStack()
{
                             delete [] items_;
}

bool DynamicStack::empty() const
{
     if(size_ == 0)
     return true;
     else
     return false;
}

int DynamicStack::size() const
{
    return size_;
}

void DynamicStack::push(StackItem value)
{
     if(size_ >= capacity_)
     {
         capacity_ = 2*capacity_;
         StackItem* temp = new StackItem[capacity_];
         for(int i = 0; i<size_; i++)
         {
                 temp[i] = items_[i];
         }
         delete [] items_;
         items_ = temp;
     }
     size_++;
     items_[size_-1] = value;
      
}

StackItem DynamicStack::pop()
{
          if (size_==0)
          return EMPTY_STACK;
         else if ((size_-1)*4 <= capacity_)
          {
          if(capacity_ >= 2*init_capacity_)
         {
         capacity_ /=2;
         StackItem* temp = new StackItem[capacity_];
         for(int i = 0; i<size_; i++)
         {
                 temp[i] = items_[i];
         }
         delete [] items_;
         items_ = temp;
         }
         }
         size_--;
         return items_[size_];
         
          
}

StackItem DynamicStack::peek() const
{
          if (size_>0)
          return items_[size_-1];
          else
          return EMPTY_STACK;
}

void DynamicStack::print() const
{
     std::cout << "[ ";
     if(!empty())
     {
     for (int i=0;i<size_;i++)
     {
                 std::cout << items_[i] << " ";
     }
     }
     std::cout << "]";           
}
