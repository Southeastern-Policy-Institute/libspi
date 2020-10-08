/* STREAM.HPP - String Stream
 * Southeastern Policy Institute, 2020
 */

# if !defined(_SPI_STREAM_HPP_) && defined(__cplusplus)
#   define  _SPI_STREAM_HPP_
#   include "string.hpp"

namespace spi {

  template<typename T>
  class ostream {
  public:
    enum class StreamMode : unsigned char {
      DEC, HEX
    };
    virtual ostream& operator<< (const T&) = 0;
  };

  class osstream : public string, public ostream<string> {
    StreamMode mode_;
    static const tchar_t* format_chars[];
  public:
    osstream (void) : string{}, mode_{StreamMode::DEC} {};
    osstream& operator<< (const string&);
    osstream& operator<< (int);
    osstream& operator<< (StreamMode);
  };

};

# endif /* _SPI_STREAM_HPP_ */
