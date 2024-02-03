#define CPPHTTPLIB_OPENSSL_SUPPORT

#include <httplib.h>
#include <json/json.h>

#include <stdlib.h>

#include <iostream>
#include <fstream>
#include <string>




void load_json(const char *filename, Json::Value &value) {

    std::ifstream ifs(filename);
    if (!ifs.is_open()) {
        throw std::exception("Failed to open file");
    }

    Json::CharReaderBuilder builder;
    builder["collectComments"] = true;
    std::string errors;

    if (!parseFromStream(builder, ifs, &value, &errors)) {
        throw std::exception("Failed to parse json");
    }
}


int main() {

    std::cout << "Hello" << std::endl;

    Json::Value config;
    load_json("./configs/config.jsonc", config);

    std::cout << config["ssl_cert"].asString() << " " << config.get("ssl_cert", "cert.pem").asString() << "\n";


    // Create ssl server
    httplib::SSLServer server(
        config["ssl_cert"].asCString(), 
        config["ssl_key"].asCString()
    );
    // std::cout << "SSL OFF" << std::endl;
    // httplib::Server server();


    // server setup 


    // listening port
    server.listen(
        config["server_ip"].asCString(), 
        config["server_port"].asInt()
    );

    return 0;

}


