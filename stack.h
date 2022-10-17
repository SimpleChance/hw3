#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack 
{
public:
    Stack();
    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
};

// vector does most of the grunt work
template <typename T>
Stack<T>::Stack(){
	// create a stack
  typename std::vector<T>::vector(); 
}

template <typename T>
bool Stack<T>::empty() const{
	// return true if the stack is empty
  return std::vector<T>::empty(); 
}

template <typename T>
size_t Stack<T>::size() const{
	// returns the size of the stack
  return std::vector<T>::size(); 
}

template <typename T>
void Stack<T>::push(const T& item){
	// pushes an item onto the stack
  std::vector<T>::push_back(item); 
}

template <typename T>
void Stack<T>::pop(){
	// pops an item off the stack

	// check for an empty stack
  if(Stack<T>::empty()){
    throw std::underflow_error("Error!");
  }
  return std::vector<T>::pop_back();
}

template <typename T>
const T& Stack<T>::top() const{
	// returns last item in the stack
  if(Stack<T>::empty()){
      throw std::underflow_error("Error!");
  }
  return std::vector<T>::back();
}

#endif