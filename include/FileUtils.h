//
// Created by aldin on 26/05/2025.
//

#ifndef FILEUTILS_H
#define FILEUTILS_H
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include "Entry.h"
#include "RedBlackTree.h"

namespace FileUtils {
    RedBlackTree read_file(const std::string& file_path, int len);
}

#endif //FILEUTILS_H
