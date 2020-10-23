/* IOS_BASE.HPP - IO Stream Base Class
 * Southeastern Policy Institute, 2020
 */

# if !defined(_SPI_IOS_BASE_HPP_) && defined(__cplusplus)
#   define  _SPI_IOS_BASE_HPP_
#   include "list.hpp"
#   include "string.hpp"
#   include "exception.hpp"

namespace spi {
  
  class ios_base {
  protected:
    ios_base (void) = default;
  public:
    ios_base (const ios_base&) = delete;

    /* Specifies the event type which is passed to functions registered by
        register_callback() on specific events */
    enum event : unsigned int {
      erase_event, imbue_event, copyfmt_event
    };

    /* Bitmask type to represent stream error state flags. */
    enum class iostate : unsigned char {
      eofbit  = 1,
      failbit = 2,
      badbit  = 4,
      goodbit = 8
    };

    /* Bitmask type to represent stream opening mode flags. */
    enum class openmode : unsigned char {
      app, ate, binary, in, out, trunc
    };

    /* Represents the seeking direction of a stream operation. */
    enum class seekdir : unsigned char {
      beg, cur, end
    };

    /* Bitmask type to represent stream format flags. */
    typedef unsigned short fmtflags;

    /* Type for callback functions registered with member register_callback. */
    typedef void (*event_callback) (event ev, ios_base& obj, int index);

    /* read/write bool elements as alphabetic strings (true and false) */
    static constexpr fmtflags boolalpha = 1;

    /* write integral values preceded by their corresponding base prefix */
    static constexpr fmtflags showbase = 2;

    /* write floating-point values including always the decimal point */
    static constexpr fmtflags showpoint = 4;

    /* write non-negative numerical values preceded by a plus sign (+) */
    static constexpr fmtflags showpos = 8;

    /* skip leading whitespaces on certain input operations */
    static constexpr fmtflags skipws = 16;

    /* flush output after each inserting operation */
    static constexpr fmtflags unitbuf = 32;

    /* replace lowercase letters in insertion operations */
    static constexpr fmtflags uppercase = 64;

    /* read/write integral values using decimal base format */
    static constexpr fmtflags dec = 128;

    /* read/write integral values using hexadecimal base format */
    static constexpr fmtflags hex = 256;

    /* read/write integral values using octal base format */
    static constexpr fmtflags oct = 512;

    /* write floating point values in fixed-point notation */
    static constexpr fmtflags fixed = 1024;

    /* write floating-point values in scientific notation */
    static constexpr fmtflags scientific = 2048;

    /* output is padded to width by inserting characters internally */
    static constexpr fmtflags internal = 4096;

    /* output is padded to width appending characters at the end */
    static constexpr fmtflags left = 8192;

    /* output is padded to width by inserting characters at the beginning */
    static constexpr fmtflags right = 16384;

    /* additional combinational flags */
    static constexpr fmtflags adjustfield = left | right | internal;
    static constexpr fmtflags basefield = dec | oct | hex;
    static constexpr fmtflags floatfield = scientific | fixed;

  private:
    fmtflags flags_;
    size_t field_width_, display_precision_;
    list<event_callback> callback_stack_;
    static list<long> internal_array_;

  public:
    virtual ~ios_base (void) {
      /* Before the object is destroyed, all callback functions
          registered with member register_callback are called with
          erase_event as first argument. */
      while (callback_stack_.size ()) {
        size_t index = callback_stack_.size () - 1;
        callback_stack_[index] (erase_event, *this, index);
        callback_stack_.remove (index);
      };
    };

    inline fmtflags flags (void) const {
      return flags_;
    };

    /* sets new format flags for the stream, returning its former value */
    inline fmtflags flags (fmtflags fmtfl) {
      register fmtflags old = flags_;
      flags_ = fmtfl;
      return old;
    };

    inline fmtflags setf (fmtflags fmtfl) {
      register fmtflags old = flags_;
      flags_ = fmtfl | flags_;
      return old;
    };

    inline fmtflags setf (fmtflags fmtfl, fmtflags mask) {
      register fmtflags old = flags_;
      flags_ = (fmtfl & mask) | (flags_ & ~mask);
      return old;
    };

    inline void unsetf (fmtflags mask) {
      flags_ &= ~mask;
    };

    inline size_t precision (void) const {
      return display_precision_;
    };

    inline size_t precision (size_t prec) {
      register size_t old = display_precision_;
      display_precision_ = prec;
      return old;
    };

    inline size_t width (void) const {
      return field_width_;
    };

    inline size_t width (size_t wide) {
      register size_t old = field_width_;
      field_width_ = wide;
      return old;
    };

    static int xalloc (void) {
      internal_array_.add (0);
      return internal_array_.size () - 1;
    };

    long& iword (int idx) {
      return internal_array_[idx];
    };

    void* pword (int idx) {
      return &internal_array_[idx];
    };

    void register_callback (event_callback fn, int index) {
      /* Registers fn as a callback function to be called automatically
          with index as argument when a stream event occurs. */
      /* If more than one callback function is registered,
          they are all called, in the inverse order of registration. */
      callback_stack_.add (fn);
    };

    bool sync_with_stdio (bool sync = true);

    class failure : public exception {
    public:
      explicit failure (const string& msg) : exception (msg) {};
      virtual ~failure (void) = default;
      virtual const tchar_t* what (void) const throw ();
    };

    class Init {
      /* internal static counter */
      static int init_cnt;
    public:
      Init (void);
      ~Init();
    };

  };

};

# endif /* _SPI_IOS_BASE_HPP_ */
