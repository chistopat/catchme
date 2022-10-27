cmake_minimum_required(VERSION 3.20)
project(catchme)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic")
find_package(Boost COMPONENTS system filesystem REQUIRED)

add_executable(catchme main.cpp)
target_link_libraries(catchme ${Boost_FILESYSTEM_LIBRARY}  ${Boost_SYSTEM_LIBRARY})

install(TARGETS catchme RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_CONTACT chistopat@yandex.ru)
set(CPACK_PACKAGE_VERSION_MAJOR "0")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "1")
include(CPack)
