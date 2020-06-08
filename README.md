# libspi
Lightweight utility library intended to eventually provide a replacement for the C and C++ standard runtime libraries on Windows.
## Features
Files | Associated Feature
------------ | -------------
`src/mutex.cpp`<br>`inc/spi/mutex.h` | `spi::mutex` - Abstraction of the win32 `mutex` object into a C++ class.
`src/stdlib.cpp` | `new` and `delete` operators.
`src/file.cpp`<br>`inc/spi/file.h` | `spi::file` - Abstraction of the win32 file handle.
`src/log.cpp`<br>`inc/spi/log.h` | `spi::log` - A simple logging framework.
`inc/spi/string.h` | `spi::string` - Platform independent dynamic string class.
`inc/spi/vector.h` | `spi::vector` - Platform independent vector class.  Implemented as a singly-linked list.
`src/main.cpp` | Startup code for Windows DLL.