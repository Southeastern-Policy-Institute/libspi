/*
 *
 */

# if !defined(_SPI_EXCEPTION_HPP_) && defined(__cplusplus)
#   define  _SPI_EXCEPTION_HPP_
#   include "string.hpp"
#   include "types.h"

namespace spi {

  class exception {
    static const tchar_t default_exception[];
    string buffer_;
  public:
    inline exception () noexcept : buffer_ (default_exception) {};

    exception (const exception& e) noexcept = default;

    inline exception (const string& err) noexcept : buffer_ (err) {};

    exception& operator= (const exception&) noexcept = default;

    virtual ~exception() = default;

    virtual const tchar_t* what() const noexcept { return buffer_; };
  };

};

# endif /* _SPI_EXCEPTION_HPP_ */