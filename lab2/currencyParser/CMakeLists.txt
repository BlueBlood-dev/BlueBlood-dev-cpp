cmake_minimum_required(VERSION 3.20)
project(currencyParser)

set(CMAKE_CXX_STANDARD 17)
set(libcurl_INCLUDE_DIR "D:/libraries/curl-7.82.0-win64-mingw/include")
include_directories(${libcurl_INCLUDE_DIR} D:/libraries/json-3.10.5/include)
add_executable(currencyParser main.cpp)
target_link_libraries(currencyParser D:/libraries/curl-7.82.0-win64-mingw/lib/libcurl.dll.a)
