#define CPPHTTPLIB_OPENSSL_SUPPORT


#include <responses.h>
#include <utils.h>

#include <httplib.h>
#include <inja/inja.hpp>
#include <json/json.h>

#include <stdlib.h>

#include <iostream>
#include <fstream>
#include <string>




int main() {

    Json::Value config;
    load_json("./configs/config.jsonc", config);


    std::cout << "Paths to ssl: \n" 
              << config["ssl_cert"].asCString() << "\n"
              << config["ssl_key"].asCString() << std::endl;


    // Create ssl server
    std::cout << "Run server on " << config["server_ip"].asCString() << ":" << config["server_port"].asInt() << std::endl;
    // httplib::SSLServer server(
    //     config["ssl_cert"].asCString(), 
    //     config["ssl_key"].asCString()
    // );
    httplib::Server server;

    ResponseProcessor resp_processor{};


    // add directory with content
    server.set_mount_point("/app", "./app");


    // Process requests
    resp_processor.GetMain(&server);
    resp_processor.GetAbout(&server);
    resp_processor.GetContacts(&server);
    resp_processor.GetProjects(&server);
    // change language
    resp_processor.ChangeLangEN(&server);
    resp_processor.ChangeLangRU(&server);

    server.Get(
        "/hi", 
        [](const httplib::Request &req, httplib::Response &res) {
            res.set_content("Hello World!", "text/plain");
        }
    );
    // Stop the server when the user access /stop
    server.Get(
        "/stop", 
        [&](const httplib::Request &req, httplib::Response &res) {
            server.stop();
            res.set_redirect(Pages::main());
        }
    );


    // listening port
    server.listen(
        config["server_ip"].asCString(), 
        config["server_port"].asInt()
    );

    std::cout << "Stop server" << std::endl;


    return 0;

}


