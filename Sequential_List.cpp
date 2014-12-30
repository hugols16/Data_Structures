#include "SequentialList.hpp"
#include <stddef.h>
#include <iostream>

SequentialList::SequentialList(unsigned int cap) //Creates list
{
                                        if (cap > 0)
                                        {                            
                                                data_ = new DataType[cap]; 
                                                size_ = 0;
                                                capacity_ = cap;
                                        }
}

SequentialList::~SequentialList() //Deletes list
{
                                  if (!empty()) //Check to see if there is something to delete
                                  {
                                   delete []data_;
                                   size_ = 0;
                                   capacity_ = 0;
                                  }
}

bool SequentialList::empty() const
{
     if (size_ == 0)
        return true;
        
     return false;
}

unsigned int SequentialList::size() const
{
         return size_;
}

unsigned int SequentialList::capacity() const
{
         return capacity_;
}

bool SequentialList::full() const
{
     if (size_ == capacity_)
        return true;
        
     return false;
}

void SequentialList::print() const
{
     if (empty())
     std::cout << "[]";
     else
     {
      for (int i=0; i<size_; i++)
      {
          std::cout << "[" <<data_[i] << "] ";
      }
     }
}

bool SequentialList::insert_front(DataType val)
{
     if (empty()) //Empty list case
     {
                   data_[0] = val;
                   size_ += 1;
                   return true;
     }          
     else if (!full()) //Check if list has space
     {
      for (int i=0; i<size_; i++)
      {
          data_[size_-i]=data_[size_-i-1];
      }
      data_[0] = val;
      size_ += 1;
      return true;
     }

          return false;
}

bool SequentialList::remove_front()
{
     if (!empty()) //Check if list has values to delete
     {
      for (int i=0; i<size_; i++)
      {
          data_[i]=data_[i+1];
      }
      size_ -= 1; 
      return true;
     }  
     
        return false;
}

bool SequentialList::insert_back(DataType val)
{
     if (empty()) //Empty list case 
     {
                   data_[0] = val;
                   size_ += 1;
                   return true;
     }
     else if (!full()) //Check if list has space
     {
                data_[size_] = val;
                size_ += 1;
                return true;
     }
     
      return false;
}

bool SequentialList::remove_back()
{
      if (!empty()) //Check if list has values
     {
         size_ -= 1; 
         return true;
     } 
     
       return false; 
}

bool SequentialList::insert(DataType val, unsigned int pos)
{
     if (!full() && pos <= size_) 
     {
                int count = 0;
                while (size_ - count > pos) //Move everything in front of pos up 1 index
                {
                      data_[size_ - count] = data_[size_ - count - 1];
                      count++;
                }
                data_[pos] = val;
                size_ += 1;
                return true;
     }
     
      return false;
}

bool SequentialList::remove(unsigned int pos)
{
     if (!empty() && pos <= size_) //Check if list has values and pos is valid
     {
                 while (pos < size_)
                 {
                       data_[pos] = data_[pos+1];
                       pos++;
                 }
                 size_ -= 1;
                 return true;
     }
     
      return false;
}

unsigned int SequentialList::search(DataType val) const
{
         if (!empty()) //Check if list has values to search for
         {
          int count = 0;
          while (count <= size_) //Check for val
          {
                if (data_[count] == val)
                       return count;
                
                count++;
          }
         }
         return size_;
}

SequentialList::DataType SequentialList::select(unsigned int pos) const
{
                         if (empty()) //Empty list case
                            return 0;
                         else if (pos >= size_) //Invalid pos
                            return data_[size_-1];
                         else 
                         {
                              return data_[pos];
                         }
}

bool SequentialList::replace(unsigned int pos, DataType val)
{
     if (pos <= size_) //Check if pos is valid
     {
             data_[pos] = val;
             return true;
     }
     
      return false;
}
