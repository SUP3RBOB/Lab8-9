#include "file_io_exception.h"

// Returns the error message(s) that the exception throws
const char* FileIOException::what() const {
    return "Failed to open file";
}
