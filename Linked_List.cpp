#include "DoublyLinkedList.hpp"
#include <stddef.h>
#include <iostream>

DoublyLinkedList::Node::Node(DataType data)
{
 
 value = data;
 next = NULL;
 prev = NULL;

}

DoublyLinkedList::DoublyLinkedList()
{
 
 head_ = NULL;
 tail_ = NULL;
 size_ = 0;

}

DoublyLinkedList::~DoublyLinkedList()
{
      //
     if (size_ >0)
     { 
     Node* visitor = head_ -> next;
     head_ = NULL;
     while (visitor != NULL)
     {
         Node* visitor2 = visitor -> next;
         delete visitor;
         visitor = visitor2;
     }
     }
     size_ = 0; 
}

bool DoublyLinkedList::empty() const
{
if (size_ > 0)
   return false;
return true;  
}

unsigned int DoublyLinkedList::size() const
{
         return size_;
}

void DoublyLinkedList::print() const
{
     
     std::cout << "[";
     Node* visitor = head_;
     for (int i=0;i<size_-1;i++)
     {
         std::cout << (visitor -> value) << "<->";
         
         visitor = visitor -> next;
     }
     std::cout << visitor -> value << "]";
     
}

bool DoublyLinkedList::insert_front(DataType value)
{
return insert(value,0);
}

bool DoublyLinkedList::remove_front()
{
 return remove(0); 
}

bool DoublyLinkedList::insert_back(DataType value)
{

return insert(value,size_);

}

bool DoublyLinkedList::remove_back()
{
return remove(size_-1);
}

bool DoublyLinkedList::insert(DataType value, unsigned int pos)
{
     if(size_ > CAPACITY) //Check for max capacity
     return false;
     
     if(pos == 0)
     {
          Node* newNode = new Node(value); 
        if (size_!=0)
        {
          Node* visitor = head_;
          visitor -> prev = newNode;
          newNode -> next = visitor;
        }
        else
        tail_ = newNode;
     head_ = newNode;
              size_++;
         return true;
      }
     else if (size_> 0)
     {
         if (pos > size_)
         {
                 std::cout << "Invalid Position";
                 return false;
         }          
         //else if (pos < size_)
         //{
         Node* newNode = new Node(value);
         Node* visitor = head_;
         for (int i=0; i< pos-1; i++)
         {
             visitor = visitor -> next;
         }
         if (pos <= size_-1) //NOT the last one
         {
         Node* visitor_next = visitor -> next;
         newNode -> prev = visitor;
         visitor -> next = newNode;
         newNode -> next = visitor_next;
         visitor_next -> prev = newNode;
         }
         else if (pos == size_)//Last one
         {
          Node* visitor = tail_;
          visitor -> next = newNode;
          newNode -> prev = visitor;
          tail_ = newNode;
         }
         size_++;
         return true;
     }    
    // } 
     
         
}

bool DoublyLinkedList::remove(unsigned int pos)
{
        
    if (empty()|| pos >= size_)
         {
            return false;
         }
     else if (pos == 0)
     {
                 
                 if (size_ > 1)
                 {
                  Node* visitor = head_;
                  Node* visitor_next = head_ -> next;
                  visitor_next -> prev = NULL;
                  head_ = visitor_next;
                  delete visitor;
                 }
                 else
                      head_ = NULL;
                 size_--;
                 return true;
     }
     else
{
         Node* visitor = head_;
         for (int i=0; i< pos; i++)
         {
             visitor = visitor -> next;
         }
         if(pos < size_-1)
         {
                Node* visitor_prev = visitor -> prev;
                Node* visitor_next = visitor -> next;
                visitor_prev -> next = visitor_next;
                visitor_next -> prev = visitor_prev;
                delete visitor;
         }
         else
         {
             Node* visitor_prev = visitor -> prev;
             visitor_prev = NULL;
             tail_ = visitor_prev;
             delete visitor;
         }
         size_--;
         return true;
     }
         
}

unsigned int DoublyLinkedList::search(DataType value) const
{     
         if (empty())
            return size_;
         else
         {
          Node* visitor = head_;
          for (int i=0; i<size_;i++)
              {
                if(value == visitor->value)
                         return i;
                else
                    visitor = visitor -> next;
          }
          return size_;
          }
         
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int pos) const
{
if (size_>0)
{
 Node* visitor = head_;
 for (int i = 0; i< size_ -1; i++)
 {
     if (i == pos)
      return visitor -> value;
     visitor = visitor -> next;
 }
return visitor -> value;
}
 else if (size_==0)
 return 0;

}

bool DoublyLinkedList::replace(unsigned int pos, DataType value)
{

if (empty())
{
            std::cout << "EMPTY";
            return false;
}
else if (pos >= size_)
    return false;
else
{

 Node* visitor = head_;
 for (int i = 0; i< size_ -1; i++)
 {
     if (i == pos)
      visitor -> value = value;
     visitor = visitor -> next;
 }
if(pos == size_-1)
visitor -> value = value;
}


}

DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int pos) const
{
}
bool DoublyLinkedList::full() const
{

       
       if (size_ > 0)
       {
       Node* visitor = head_ -> next;
        for (int i=0;i<size_;i++)
        {
            if (visitor == NULL)
             return false;
            visitor = visitor -> next;
        }
            return true;
        }
        else
        return false;


}

