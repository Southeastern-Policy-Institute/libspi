/* LIST.HPP - Dynamically allocated and managed array.
 * Southeastern Policy Institute, 2020
 */

# if !defined(_SPI_LIST_HPP_) && defined(__cplusplus)
#   define  _SPI_LIST_HPP_

namespace spi {

  //  Dynamically allocated and managed array.
  //  Takes the form of a singly-linked list with a NULL terminator.
  template <class T> class list {
    //  Pointer to the next list item.
    list* next_;
    //  Stored element.
    T* element_;

    //  Retrieves the last list item.
    list* last (void) {
      list* target = this;
      while (target->next_)
        target = target->next_;
      return target;
    };
  public:
    //  Iterator for range-based loops
    class iterator {
      unsigned int index_;
      list* start_;
    public:
      iterator (list* l, unsigned int i) : index_ (i), start_ (l) {};
      iterator operator++ (void) { index_ += 1; return *this; };
      bool operator!= (const iterator& other) const {
        return index_ != other.index_;
      };
      const T operator* (void) const { return start_->operator[] (index_); };
    };

    iterator begin (void) const {
      return iterator (const_cast<list*> (this), 0);
    };

    iterator end (void) const {
      return iterator (const_cast<list*> (this), size ());
    };

    //  Default constructor simply NULL's the members.
    list (void) : next_ (static_cast<list*> (nullptr)),
      element_ (static_cast<T*> (nullptr))
    {};

    //  Generates a list with an intitial first element.
    list (const T& val) : next_ (static_cast<list*> (nullptr)),
      element_ (new T (val))
    {};

    //  Deconstructor will propagate deletion until it reaches the terminator.
    ~list (void) {
      if (element_)
        delete element_;
      if (next_)
        delete next_;
    };

    //  Prevent Copying
    list& operator= (const list& lst) {
      clear ();

    };
    list (const list&) = delete;

    //  Determines if the list is empty.
    inline bool is_empty (void) const {
      return !next_ && !element_;
    };

    //  Determine the number of elements in the list.
    unsigned int size (void) const {
      unsigned int count = element_ ? 1 : 0;
      for (list* target = const_cast<list*> (this);
        target->next_;
        target = target->next_
        ) count += 1;
      return count;
    };

    //  Deletes all elements and items in the list.
    void clear (void) {
      if (element_) {
        delete element_;
        element_ = static_cast<T*> (nullptr);
      };
      if (next_) {
        delete next_;
        next_ = static_cast<list*> (nullptr);
      };
    };

    //  Add a new element to the list.
    void add (const T& item) {
      //  If no elements have yet been added to the list...
      if (!next_ && !element_)
        //  Generate the new element within the first list item.
        element_ = new T (item);
      //  Otherwise, generate the new element in the current terminator
      else
        last ()->next_ = new list (item);
    };

    //  Insert an item into the list at a given index.
    void add (const T& item, unsigned int index) {
      if (index >= size ()) {
        add (item);
        return;
      };

      list* target = this;
      while (index--)
        target = target->next_;

      list* new_next = new list (*target->element_);
      new_next->next_ = target->next_;
      target->next_ = new_next;
      delete target->element_;
      target->element_ = new T (item);
    };

    // Find element index.
    unsigned int get_index (T* element) {
      list* target = this;
      unsigned int index = 0;
      if (element_ != element)
        while (target->next_ != nullptr) {
          if (target->element_ == element)
            break;
          index += 1;
          target = target->next_;
        }
      if (target == last () && target->element_ != element)
        index = 0;
      return index;
    };

    //  Deletes a list item at a given index.
    void remove (unsigned int index) {
      if (index >= size ())
        return;
      //  Removing the first element involves essentially replacing it
      //  with the second, then deleting the second.
      if (index == 0) {
        list* temp = next_->next_;
        next_->next_ = static_cast<list*> (nullptr);
        delete element_;
        element_ = new T (*next_->element_);
        delete next_;
        next_ = temp;
      }
      //  Removing any other element uses a similar process but does not copy.
      else {
        list* previous = static_cast<list*> (nullptr);
        list* target = this;
        while (index--) {
          previous = target;
          target = target->next_;
        };
        previous->next_ = target->next_;
        target->next_ = static_cast<list*> (nullptr);
        delete target;
      };
    };

    //  Access Operator
    T& operator[] (unsigned int index) {
      //  Bound check.
      if (index >= size ())
        return *element_;
      list* target = this;
      while (index--)
        target = target->next_;
      return *target->element_;
    };

    //  Protected Access Operator
    const T& operator[] (unsigned int index) const {
      return operator[] (index);
    };

    //  Access first member
    const T& first (void) const {
      return operator[] (0);
    };
  };

};

# endif /* _SPI_LIST_HPP_ */
