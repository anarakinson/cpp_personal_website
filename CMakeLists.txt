cmake_minimum_required(VERSION 3.5)


project(website)


find_package(httplib CONFIG REQUIRED)
find_package(jsoncpp CONFIG REQUIRED)
find_package(OpenSSL REQUIRED)


add_executable(
    website
    main.cpp
)

set_target_properties(
    website PROPERTIES 
    CXX_STANDARD 20 
    CXX_STANDARD_REQUIRED ON 
)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
)


target_link_libraries(
    website PRIVATE 
    httplib::httplib
    JsonCpp::JsonCpp
    OpenSSL::SSL 
    OpenSSL::Crypto
)


# set compile options
if (MSVC)
    target_compile_options(website PRIVATE
        /W4
    )
else ()
    target_compile_options(website PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

