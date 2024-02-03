#define CPPHTTPLIB_OPENSSL_SUPPORT

#include <httplib.h>
#include <json/json.h>

#include <stdlib.h>

#include <iostream>
#include <string>

#define SSL_ON true



int main() {
    std::cout << "Hello" << std::endl;

#if SSL_ON
    std::cout << "SSL ON" << std::endl;
    httplib::SSLServer server("", "");
#else 
    std::cout << "SSL OFF" << std::endl;
    httplib::Server server();
#endif

}

