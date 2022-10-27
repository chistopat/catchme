#include <iostream>

#include <boost/filesystem/operations.hpp>
#include "boost/filesystem/fstream.hpp"


boost::filesystem::path FindFile(const std::string& entry_point, const std::string& name) {
    boost::filesystem::recursive_directory_iterator begin(entry_point);
    boost::filesystem::recursive_directory_iterator end;

    for (; begin != end; ++begin) {
        if (is_regular_file(begin->status()) && begin->path().filename() == name) {
            return begin->path();
        }
    }

    return {};
}

int main() {
    std::string file_name;
    std::string entry_point;
    std::cin >> entry_point >> file_name;

    boost::filesystem::ifstream in{FindFile(entry_point, file_name)};
    std::string data{std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>()};
    std::cout << data;
}
