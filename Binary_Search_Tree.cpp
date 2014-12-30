#include "BinarySearchTree.hpp"
#include <iostream>
#include <cmath>

using namespace std;

typedef BinarySearchTree::DataType DataType;

BinarySearchTree::Node::Node(DataType newval)
{
 val = newval;
 left = NULL;
 right = NULL;   
}

BinarySearchTree::BinarySearchTree()
{
  root_ = NULL;
  size_ = 0;  
}

BinarySearchTree::~BinarySearchTree()
{
   /*while(size_>0)
   {
                  remove(min());
                  std::cout << "LOOP" << std::endl;
   }
 */  
}

bool BinarySearchTree::insert(DataType val) //if >= then go right
{
     //std::cout<<"Inserting "<<val<<std::endl;
     if(exists(val))
     {
     //std::cout << "IT EXISTS" << std::endl;               
     return false;
     }
     
     Node* newNode = new Node(val);
     Node* visitor = root_;
     if(root_ == NULL)
     {
              root_ = newNode;
              size_++;
              return true;
     }
     while(((visitor->left != NULL) && (val < visitor -> val)) || ((visitor -> right !=NULL) && (val > visitor -> val)))
     {
                           if(val > visitor -> val)
                           visitor = visitor -> right;
                           else
                           visitor = visitor -> left;
     }
     if (val < visitor -> val)
         visitor -> left = newNode;
     else
         visitor -> right = newNode;
     size_++;
     return true;
             
    /*
    Node* newNode = new Node(val)
    Node* GGPar = root_;
    Node* Par;
    if(root_ == NULL)
     root_ = newNode;
     else
     {
         if(val < GPar)
         {
                if (Gpar -> left == NULL) // check if left child exists. If not, put the newNode as its left child
                Gpar -> left = newNode;
                else
                Par = GPar -> left; // If left child exists, put it as parent.
         }
         else
         {
             if(GPar -> right == NULL) //check if right child exists. If not, put newNode as its right child
             GPar -> right = newNode;
             else
             Par = Gpar -> right;
         }
         while(Par -> next != NULL) //Traversing the AVL Tree
         {
          GPar = Par;
                   if(val < Par -> val) //If less than Parent, go left
                   {
                          Par = Par -> left;
                   }
                   else //If greater or equal as Parent, go right
                   {
                          Par = Par -> right;
                   }
          }
          if( val < Par -> val && Par -> val < GPar -> val) //insert into left child of left child of alpha
          {
              Par -> left - newNode;
            if(abs(getNodeDepth(GPar -> left) - getNodeDepth(GPar -> right) >= 2)
            {
             Par = GPar;
             Par -> right = GPar;
            }
          }
          else if(val > Par -> val && Par -> val > GPar -> val)//insert into right child of right child of alpha
          {
               Par -> right = newNode;
               if (abs(getNodeDepth(GPar -> left) - getNodeDepth(GPar -> right) >= 2)
               {
                   Par = GPar;
                   Par -> left = GPar;
               }
          }
          else if(val > Par -> val && Par -> val < GPar -> val) //insert into right child of left child of alpha
          {
               Par -> right = newNode;
               if(abs(getNodeDepth(GPar -> left) - getNodeDepth(GPar -> right) >= 2)
               {
                Node* temp = Par;
                newNode = temp;
                newNode -> left = Par;
                
     */       
}

bool BinarySearchTree::remove(DataType val)
{
  if(!exists(val))
  {
  //std::cout << "It doesn't exist" << endl;
  return false;   
  }                     
  Node* Gvisitor = root_;
  Node* visitor = root_;
  //std::cout << "Root is: " << root_ -> val << std::endl;
  //std::cin.get();
  if(val > root_ -> val)
  {
  visitor = root_ -> right;
  //std::cout << "Go right" << std::endl;
  }
  else if(val < root_ -> val)
  {
  visitor = root_ -> left;
  //std::cout << "Go left" << std::endl;
  }
  //std::cout << "visitor is " << visitor -> val << std::endl;
  //std::cin.get();
  while(visitor != NULL)
  {
       //std::cout << "visitor val is: " << visitor -> val << endl;
       //std::cout << "compared val is: " << val << endl;
       //std::cin.get();
       if(val == visitor -> val)
       break;
       Gvisitor = visitor;
       if(val > visitor -> val)
       {
       //std::cout << "Go right" << std::endl;
       //std::cin.get();  
       visitor = visitor -> right;  
       }
       else
       {
       //std::cout << "Go left" << std::endl;
       //std::cin.get();  
       visitor = visitor -> left;      
       }   
  }//WORKS UNTIL HERE

Node* deleteptr = visitor;
//std::cout << "Visitor is: " << visitor -> val << std::endl;
//std::cout << "DeletePtr is " << deleteptr -> val << std::endl;
//std::cout << "Gvisitor is " << Gvisitor -> val << std::endl;
//std::cin.get();
if(visitor -> left == NULL && visitor -> right == NULL)
{
           //std::cout << "No children" << std::endl;
           //std::cin.get();
           if(Gvisitor -> val > visitor -> val)
           Gvisitor -> left = NULL;
           else if(Gvisitor -> val < visitor -> val) 
           Gvisitor -> right = NULL;
           else
           root_ = NULL;
           //std::cin.get();//STOP
}
else if(visitor -> left == NULL && visitor -> right != NULL)
{
           //std::cout << "Right children" << std::endl;
           //std::cin.get();
           if(Gvisitor -> val > visitor -> val)
           Gvisitor -> left = visitor -> right;
           else if(Gvisitor -> val < visitor -> val)
           Gvisitor -> right = visitor -> right;
           else
           root_ = root_ -> right;
           //std::cin.get();//STOP
}

else if(visitor -> left != NULL && visitor -> right == NULL)
{
           //std::cout << "Left children" << std::endl;
           //std::cin.get();
           if(Gvisitor -> val > visitor -> val)
           Gvisitor -> left = visitor -> left;
           else if(Gvisitor -> val < visitor -> val)
           Gvisitor -> right = visitor -> left;
           else
           root_ = root_ -> left;
           //std::cin.get();//STOP
}
     
if(visitor -> left != NULL && visitor -> right != NULL)
{
           //std::cout << "Left and Right children" << std::endl;
           //std::cout << "Visitor is: " << visitor -> val << std::endl;
           //std::cin.get();
           visitor = visitor -> right;//move to visprev
           //std::cout << "Visitor is: " << visitor -> val << std::endl;
           //std::cin.get();
           if(visitor -> left == NULL)
           {
                      //std::cout << "Left is NULL" << std::endl;
           }
           //std::cin.get();
           if(visitor -> left == NULL) //If visitor has no left child, then we can simply attach it to Gvisitor and attach deleteptr -> left as its left child
           {
            if((Gvisitor -> val) > (deleteptr -> val))
            Gvisitor -> left = visitor;
            else if((Gvisitor -> val) < (deleteptr -> val))//If visitor has no right child, same as no left child
            Gvisitor -> right = visitor;
            else
            {
            //std::cout << "Visitor is root" << std::endl;
            root_ = visitor;
            }
            visitor -> left = deleteptr -> left;
            //std::cout << "visitor is : " << visitor -> val << std::endl;
            //std::cout << "visitor -> left is : " << (visitor -> left) -> val << std::endl;
            //std::cin.get();
           }
           else
           {
           Node* visprev = visitor; //visprev is the parent node of the new Node to remplace one to be deleted
           while(visitor -> left != NULL)
           {
                         //std::cout << "Left is NOT NULL" << std::endl;
                         //std::cin.get();
                         visprev = visitor;
                         //std::cout << "visprev is : " << visprev -> val << std::endl;
                         visitor = visitor -> left;
                         //std::cin.get();
                         //std::cout << "visitor is now : " << visitor -> val << std::endl;
                         //std::cin.get();
           }
           //std::cout << "second step " << std::endl;
           //std::cout << "After loop, visprev is: " << visprev -> val << std::endl;
           //std::cout << "After loop, visitor is: " << visitor -> val << std::endl;
           //std::cin.get();
           Node* visitor_right = visitor -> right;
           //std::cin.get();
           //std::cout << "Gvisitor is: " << Gvisitor -> val << std::endl;
           //std::cout << "deleteptr is : " << deleteptr -> val << std::endl;
           //std::cin.get();
           if(Gvisitor -> val < deleteptr -> val) //Gvisitor is smaller than deleteptr
           {
           //std::cout << "Gvisitoe is smaller than deleteptr" << std::endl;
           Gvisitor -> right = visitor;
           //std::cin.get();
           //std::cout << "Gvisitor -> right is now : " << (Gvisitor -> right) -> val << std::endl;
           //std::cin.get();
           }
           else if(Gvisitor -> val > deleteptr -> val)//Gvisitor is greater than deleteptr
           {
           //std::cout << "Gvisitor is greater than deleteptr " << std::endl;
           Gvisitor -> left = visitor;
           //std::cin.get();
           //std::cout << "Gvisitor -> left is now : " << (Gvisitor -> left) -> val << std::endl;
           //std::cin.get();
           }
           else //If its the root
           {
               //std::cout << "deleteptr is the root" << std::endl;
               root_ = visitor;
               //std::cout << "root is now: " << root_-> val << std::endl;
               //std::cin.get();
           }
           //std::cout << "visprev is " << visprev -> val << std::endl;
           //std::cin.get();
           if((visprev -> val) != (visitor -> val))
           {
           //std::cout << "Visprev is not visitor" << std::endl;
           //std::cout << "visitor-right is : " << visitor_right -> val << std::endl;
           visprev -> left = visitor_right;
           visitor -> right = deleteptr -> right;//that line doesnt work 
           }
           
           visitor -> left = deleteptr -> left;
           //std::cout << "Just Before deleting" << std::endl;
           //std::cin.get();//STOP
           }
}
//std::cout << "Value of deletePtr is: " << deleteptr -> val << std::endl;
//std::cin.get();
delete deleteptr;
//std::cout << "Deleteptr has been deleted" << std::endl;
//std::cin.get();
size_ --;
//std::cout << "Givisitor is: " << Gvisitor -> val << std::endl;
//std::cout << "Gvisitor -> right is: " << (Gvisitor -> right) -> val << std::endl;
//std::cout << "Gvisitor -> left is: " << (Gvisitor -> left) -> val << std::endl;
//if(((Gvisitor -> left) -> right) != NULL)
//std::cout << "Gvisitor -> left -> right is: " << ((Gvisitor -> left) -> right) -> val << std::endl;
//else
//std::cout << "Gvisitor -> left -> right is NULL" << std::endl;
//std::cin.get();
return true;
}

bool BinarySearchTree::exists(DataType val) const
{
    Node* vis = root_;
    while(vis != NULL)
    {
              if(val == vis->val)
              {
                     /*
                     if(vis -> left != NULL)
                     std::cout <<"Left of " << val << " is " << (vis -> left) -> val << endl;
                     else
                     std::cout << "Left of " << val << " is NULL" << std::endl;
                     if(vis -> right != NULL)
                     std::cout <<"Right of " << val << " is " << (vis -> right) -> val << endl;
                     else
                     std::cout << "Right of " << val << " is NULL " << std::endl;
                     */
                     return true;
              }
              else if(val > vis -> val)
              vis = vis -> right;
              else
              vis = vis -> left;
    }
    return false;
}

DataType BinarySearchTree::min() const
{
    if(size_!=0)
    {
    Node* visitor = root_;
                while(visitor -> left !=NULL)
                {
                  visitor = visitor -> left;
                }
                return visitor->val;
    }
    else
    return -1;   
}

DataType BinarySearchTree::max() const
{
    if(size_!=0)
    {
    Node* visitor = root_;
                while(visitor -> right !=NULL)
                {
                  visitor = visitor -> right;
                }
                return visitor->val;
    }
    else
    return -1;         
}

unsigned int BinarySearchTree::size() const
{
    return size_;
}

unsigned int BinarySearchTree::depth() const
{
    if(size_>0)
    return (getNodeDepth(root_));
    else
    return 0;
}

void BinarySearchTree::print() const
{
   
     if(size_==0)
     std::cout << "EMPTY" << endl;
     else
     {
         int init_cap = 1;
         Node** parent = new Node*[init_cap];
         parent[0] = root_;
         for(int i = 0; i < pow(2,double(depth()))+1 ; i++)
         {
                 std::cout << "   ";
         }
         std::cout << "[" << root_ -> val << "]" << std::endl;
         Node** child;
         for(int i=0; i<depth(); i++)
         {
                 int capArray = int(pow(2,double(i+1)));
                 child = new Node*[capArray];
                 for(int k=pow(2,double(depth()))-i;k > i; k--)
                 {
                         std::cout << "   ";
                 }
                 for(int j = 0; j<pow(2,double(i)); j++)
                 {
                 if(parent[j] == NULL)
                 {
                           child[2*j] = NULL;
                           child[2*j+1] = NULL;
                 
                 }
                 else
                 {
                 child[2*j] = (parent[j]) -> left;
                 child[2*j+1] = (parent[j]) -> right;
                 }
                 if(child[2*j] == NULL)
                 std::cout << " [N] ";
                 else
                 std::cout << "[" << child[2*j]->val << "]" << " ";
                 if(child[2*j+1] == NULL)
                 std::cout << "[N]";
                 else
                 std::cout << "[" << child[2*j+1]->val << "]" << " ";
                 }
                 delete [] parent;
                 parent = child;
           std::cout << endl;
         }          
delete [] child;
}

}

int BinarySearchTree::getNodeDepth(Node* n) const
{
    if(n == NULL)
    return -1;
    else
    {
        if(getNodeDepth(n->left) >= getNodeDepth(n->right))
        return (getNodeDepth(n->left)+1);
        else
        return (getNodeDepth(n->right)+1);
    }
}
