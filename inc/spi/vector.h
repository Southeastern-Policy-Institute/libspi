/* VECTOR.H - Simplified vector class.
 * Southeastern Policy Institute, 2020
 */

# ifndef  _SPI_VECTOR_H_
#   define  _SPI_VECTOR_H_
#   include "spidef.h"
#   ifdef   __cplusplus
namespace spi {

  //  Dynamically allocated and managed array.
  //  Takes the form of a singly-linked list with a NULL terminator.
  template <typename T> class vector {
    //  Pointer to the next vector item.
    vector* next_;
    //  Pointer to the stored element.
    T* element_;

    //  Retrieves the last vector item.
    vector* last (void) {
      vector* target = this;
      while (target->next_)
        target = target->next_;
      return target;
    };
  public:
    //  Default constructor simply NULL's the members.
    vector (void) : next_ ((vector*)NULL), element_ ((T*)NULL) {};

    //  Generates a vector with an intitial first element.
    vector (const T& val) : next_ ((vector*)NULL), element_ ((T*)NULL) {
      element_ = new T (val);
    };

    //  Deconstructor will propagate deletion until it reaches the terminator.
    ~vector (void) {
      if (element_)
        delete element_;
      if (next_)
        delete next_;
    };

    //  Prevent Copying
    vector& operator= (const vector&) = delete;
    vector (const vector&) = delete;

    //  Determines if the vector is empty.
    bool is_empty (void) const {
      return !next_ && !element_;
    };

    //  Determine the number of elements in the vector.
    __SIZE_TYPE__ size (void) {
      __SIZE_TYPE__ count = element_ ? 1 : 0;
      for (vector* target = this; target->next_; target = target->next_)
        count += 1;
      return count;
    };

    //  Deletes all elements and items in the vector.
    void clear (void) {
      if (element_) {
        delete element_;
        element_ = (T*)NULL;
      };
      if (next_) {
        delete next_;
        next_ = (vector*)NULL;
      };
    };

    //  Add a new element to the vector.
    void add (const T& item) {
      //  If no elements have yet been added to the vector...
      if (!next_ && !element_)
        //  Generate the new element within the first vector item.
        element_ = new T (item);
      //  Otherwise, generate the new element in the current terminator
      else
        last ()->next_ = new vector (item);
    };

    __SIZE_TYPE__ get_index (T* element) {
      // Find element index.
      vector* target = this;
      __SIZE_TYPE__ index = 0;
      if (element_ != element)
      while (target->next_ != NULL) {
        if (target->element_ == element)
          break;
        index += 1;
        target = target->next_;
      }
      if (target == last () && target->element_ != element)
        index = 0;
      return index;
    };

    //  Deletes a vector item at a given index.
    void remove (T* element) {
      __SIZE_TYPE__ index = get_index (element);
      if (index >= size ())
        return;
      if (index == 0 && element != element_)
        return;
      //  Removing the first element involves essentially replacing it
      //  with the second, then deleting the second.
      if (index == 0) {
        vector* temp = next_->next_;
        next_->next_ = (vector*)NULL;
        delete element_;
        element_ = new T (*next_->element_);
        delete next_;
        next_ = temp;
      }
      //  Removing any other element uses a similar process but does not copy.
      else {
        vector* previous = (vector*)NULL;
        vector* target = this;
        while (index--) {
          previous = target;
          target = target->next_;
        };
        previous->next_ = target->next_;
        target->next_ = (vector*)NULL;
        delete target;
      };
    };

    //  Access Operator
    T& operator[] (__SIZE_TYPE__ index) {
      //  Bound check.
      if (index >= size ())
        return *element_;

      vector* target = this;
      while (index--)
        target = target->next_;
      return *target->element_;
    };
  };
};
#   endif /* __cplusplus */
# endif /* _SPI_VECTOR_H_ */
