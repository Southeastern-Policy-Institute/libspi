# libspi
Light weight drop-in library with various utilities.
## Features
Files | Associated Feature
------------ | -------------
`src/stdlib.cpp` | `new` and `delete` operators so you don't need to include libstdc++.  There is currently no need to link against libspi if you intend to use the standard C++ library; the header files are enough.
`inc/spi/algorithm.hpp` | General purpose algorithms including: `memset()`, `memcpy()`, `memclr()`, and `swap()`
`inc/spi/array.hpp` | `spi::array` - Variable-type dynamic array
`inc/spi/list.hpp` | `spi::list` - Singly-linked list
`inc/spi/stream.hpp` | `spi::stream` - String stream
`inc/spi/string.h` | `spi::string` - Platform independent dynamic string class.
