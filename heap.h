#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  int n;
  PComparator comp;
  int size_ = 0;
  std::vector<T> heap_;
};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : n(m), comp(c) {
  size_ = 0;
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
  //Check for empty
  return size_ == 0;
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
  //Get size
  return size_;
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("heap is empty");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return heap_[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("heap is empty");
  }
  heap_[0] = heap_[size_ - 1];
  size_--;
  int root = 0;
  while (root < size_) {
    int priority = root * n + 1;
    for (int i = 1; i <= n && (root * n + i) < size_; ++i) {
        if (!comp(heap_[priority], heap_[root * n + i])){
          priority = root * n + i;
        }
    }
    if (priority >= size_){
      break;
    }

    if (comp(heap_[root], heap_[priority])) {
      break;
    } 
    else {
      T temp = heap_[root];
      heap_[root] = heap_[priority];
      heap_[priority] = temp;

      root = priority;
    }
  }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T &item) {
  int curr = size_++;

  if (size_ > heap_.size()){
    heap_.push_back(item);
  }
  else {
    heap_[size_];
  }

  while (curr != 0 && comp(item, heap_[(curr - 1 ) / n])) {
    heap_[curr] = heap_[(curr - 1 ) / n];
    curr = (curr - 1 ) / n;
  }

  heap_[curr] = item;
}

#endif

