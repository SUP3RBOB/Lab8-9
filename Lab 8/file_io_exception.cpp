#include "file_io_exception.h"

const char* FileIOException::what() const {
    return "Failed to open file";
}
