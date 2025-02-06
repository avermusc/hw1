#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
  /**
   * Adds a new value to the back of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::push_back(const std::string& val){
  if (tail_ && tail_->last != ARRSIZE){ // if the tail exists and has space
    tail_->val[tail_->last] = val; //add to last value in the tail items' array
    size_++; //incrmement size
    tail_->last++; //increment index
  }
  else{
    Item* addItem = new Item(); // make a new Item
    if (!tail_){ // if list is empty
      head_ = addItem; //the new item should be the head and tail
      tail_ = addItem;
      tail_->val[tail_->last] = val; //add to last value in the tail items' array
      size_++; // incremenrt size
      tail_->last++; //incemenent index
    }
    else{ // list is not empty, but current item is full
      tail_->next = addItem;
      addItem->prev = tail_;
      tail_ = addItem;
      tail_->val[tail_->last] = val;
      size_++;
      tail_->last++;
    }
  }
}

  /**
   * Removes a value from the back of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::pop_back(){
    if (empty()){
      return;
    }
    else{
      tail_->val[(tail_->last) - 1] = "";
      tail_->last--;
      size_--;
      if (tail_->first - tail_->last == 0){ //if we just emptied an Item's array
        Item* temp = tail_;
        tail_ = tail_->prev;
        if (!tail_){
          head_ = nullptr;
        }
        else{
          tail_->next = nullptr;
        }
        delete temp;
      }
    }
  }
  
  /**
   * Adds a new value to the front of the list.
   * If there is room before the 'first' value in
   * the head node add it there, otherwise, 
   * allocate a new head node.
   *   - MUST RUN in O(1)
   */
  void ULListStr::push_front(const std::string& val){
    if (head_ && head_->first != 0){ // if the head exists and has space
      head_->first--; //increment index
      head_->val[head_->first] = val; //add to last value in the tail items' array
      size_++; //incrmement size
    }
    else{
      Item* addItem = new Item(); // make a new Item
      addItem->first = ARRSIZE - 1;
      addItem->last = ARRSIZE;
      if (!head_){ // if list is empty
        addItem->val[addItem->first] = val; //add to last value in the head items' array
        head_ = addItem; //the new item should be the head and tail
        tail_ = addItem;
        size_++; // incremenrt size
        // head_->first--; //decrement index
      }
      else{ // list is not empty, but current item is full
        addItem->val[addItem->first] = val; //add to last value in the head items' array
        addItem->next = head_;
        head_->prev = addItem;
        head_ = addItem;
        // head_->val[head_->first] = val;
        size_++;
        // head_->first--;
      }
    }
  }

  /**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::pop_front(){
    if (empty()){
      return;
    }
    else{
      head_->val[(head_->first)] = "";
      head_->first++;
      size_--;
      if ((head_->last - head_->first) == 0){ //if we just emptied an Item's array
        Item* temp = head_;
        head_ = head_->next;
        if (!head_){
          tail_ = nullptr;
        }
        else{
          head_->prev = nullptr;
        }
        delete temp;
      }
    }
  }
  
  /**
   * Returns a const reference to the back element
   *   - MUST RUN in O(1)
   */
  std::string const & ULListStr::back() const{
    if (empty()){
      throw std::runtime_error("Empty list");
    }
    else{
      return tail_->val[(tail_->last - 1)];
    }
  }

  std::string* ULListStr::getValAtLoc(size_t loc) const{
    if (loc >= size_ || loc < 0){ //if invalid loc provided
      return nullptr;
    }
    else{
      //parse through each item in list, adding up the size of them using last-first
      //parse until the right node is found bc the nodesizes 
      Item* temp = head_;
      size_t numElems = 0;
      while (temp != nullptr){
        // numElems += (temp->last - temp->first);
        if ((numElems + (temp->last - temp->first)) > loc){
          return &temp->val[(temp->first + loc - numElems)];
        }
        else{
          numElems += (temp->last - temp->first);
          temp = temp->next;
        }
      }
      return nullptr;
    }
  }


  /**
   * Returns a const reference to the front element
   *   - MUST RUN in O(1)
   */
  std::string const & ULListStr::front() const{
    if (empty()){
      throw std::runtime_error("Empty list");
    }
    else{
      return head_->val[(head_->first)];
    }
  }

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
