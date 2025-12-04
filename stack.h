
#ifndef stack_h
#define stack_h
#include "node.h"
class Stack {
	NodePtr top;
	int size;
public:
    void push(int);
    int pop();
    Stack()
    {
        top = NULL;
        size = 0;
    }
    ~Stack();
};


void Stack::push(int x){
  NodePtr new_node=new NODE(x); //make new node
  if(new_node)
  {
        new_node->set_next(top);    // Link the new node to the current top
        top = new_node; // Update the top pointer to the new node
        size++;
   }
 
         // Left missing for exercises…
    
}

int Stack::pop(){
    if (top == NULL)
    {
        cout << "The stack is empty." << endl;
        return -1;
    }
    else{
        NodePtr t=top;
        int value;
        value=t->get_value();
        top = top->get_next();
        size--;
        cout << "pop ";
        delete t; //take it out of the stack
        return value;
	//be careful of the empty stack!!!
    }
    }

Stack::~Stack(){
    //delete all remaning stack (i.e. pop all) 
        while (top != nullptr) {
        NodePtr t = top;
        top = top->get_next();
        delete t;
    }
}


#endif
