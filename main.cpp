#define CPPHTTPLIB_OPENSSL_SUPPORT



#include <httplib.h>
#include <inja/inja.hpp>
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

    Json::Value config;
    load_json("./configs/config.jsonc", config);

    std::cout << "Paths to ssl: \n" 
              << config["ssl_cert"].asCString() << "\n"
              << config["ssl_key"].asCString() << std::endl;


    // Create ssl server
    std::cout << "Run server on " << config["server_ip"].asCString() << ":" << config["server_port"].asInt() << std::endl;
    httplib::SSLServer server(
        config["ssl_cert"].asCString(), 
        config["ssl_key"].asCString()
    );
    // httplib::Server server;

    // add directory with content
    server.set_mount_point("/app", "./app");

    // Set test page
    server.Get(
        "/",           // address on site
        [&](const httplib::Request &req, httplib::Response &res) {
            // Load template
            inja::Environment env;
            inja::Template tmpt = env.parse_template("./app/html/index.html");

            // Build data
            inja::json page_data;
            page_data["nothing"] = "nothing";

            // render content   
            res.set_content(env.render(tmpt, page_data).c_str(), "text/html");
        }
    );
    // Set about page
    server.Get(
        "/about/",           // address on site
        [&](const httplib::Request &req, httplib::Response &res) {
            // Load template
            inja::Environment env;
            inja::Template tmpt = env.parse_template("./app/html/about.html");

            // Build data
            inja::json page_data;
            page_data["nothing"] = "nothing";

            // render content   
            res.set_content(env.render(tmpt, page_data).c_str(), "text/html");
        }
    );
    // Set about page
    server.Get(
        "/contacts/",           // address on site
        [&](const httplib::Request &req, httplib::Response &res) {
            // Load template
            inja::Environment env;
            inja::Template tmpt = env.parse_template("./app/html/contacts.html");

            // Build data
            inja::json page_data;
            page_data["nothing"] = "nothing";

            // render content   
            res.set_content(env.render(tmpt, page_data).c_str(), "text/html");
        }
    );
    // Set about page
    server.Get(
        "/projects/",           // address on site
        [&](const httplib::Request &req, httplib::Response &res) {
            // Load template
            inja::Environment env;
            inja::Template tmpt = env.parse_template("./app/html/projects.html");

            // Build data
            inja::json page_data;
            page_data["nothing"] = "nothing";

            // render content   
            res.set_content(env.render(tmpt, page_data).c_str(), "text/html");
        }
    );




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
            res.set_redirect("/");
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


