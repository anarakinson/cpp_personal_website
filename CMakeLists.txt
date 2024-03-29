cmake_minimum_required(VERSION 3.5)


project(website)


if(MSVC)
    set(OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/Debug)
else()
    set(OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/)
endif()


find_package(httplib CONFIG REQUIRED)
find_package(jsoncpp CONFIG REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(inja CONFIG REQUIRED)


add_executable(
    website
    main.cpp
)

file(
    COPY 
    ${CMAKE_CURRENT_SOURCE_DIR}/app 
    ${CMAKE_CURRENT_SOURCE_DIR}/configs 
    DESTINATION 
    ${OUTPUT_DIR}
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
    pantor::inja
)


# set compile options
if (MSVC)
    target_compile_options(website PRIVATE
        /W4
    )
else ()
    target_compile_options(website PRIVATE
        # -Wall 
        -Wextra 
        -pedantic 
        -Werror
    )
endif()

