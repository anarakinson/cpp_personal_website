#pragma once 


#include <httplib.h>
#include <inja/inja.hpp>
#include <json/json.h>

#include <stdlib.h>

#include <iostream>
#include <fstream>
#include <string>



// Something like enum class for c-strings
struct Pages {

    static const char *main() { return "/"; }
    static const char *about() { return "/about/"; }
    static const char *contacts() { return "/contacts/"; }
    static const char *projects() {return "/projects/"; }

};


class ResponseProcessor {
public:

    void GetMain(httplib::SSLServer &server) {
        // Set test page
        server.Get(
            Pages::main(),           // address on site
            [&](const httplib::Request &req, httplib::Response &res) {
                // Load template
                inja::Template tmpt = env.parse_template("./app/html/index.html");

                // Build data
                page_data["nothing"] = "nothing";
                // page_data["lang"] = lang;

                // render content   
                res.set_content(env.render(tmpt, page_data).c_str(), "text/html");
            }
        );
    }


    // About page
    void GetAbout(httplib::SSLServer &server) {
        server.Get(
            Pages::about(),           // address on site
            [&](const httplib::Request &req, httplib::Response &res) {
                // Load template
                inja::Template tmpt = env.parse_template("./app/html/about.html");

                // Build data
                page_data["nothing"] = "nothing";
                // page_data["lang"] = lang;

                // render content   
                res.set_content(env.render(tmpt, page_data).c_str(), "text/html");
            }
        );
    }


    // Contacts page
    void GetContacts(httplib::SSLServer &server) {
        server.Get(
            Pages::contacts(),           // address on site
            [&](const httplib::Request &req, httplib::Response &res) {
                // Load template
                inja::Template tmpt = env.parse_template("./app/html/contacts.html");

                // Build data
                page_data["nothing"] = "nothing";
                // page_data["lang"] = lang;

                // render content   
                res.set_content(env.render(tmpt, page_data).c_str(), "text/html");
            }
        );
    }


    void GetProjects(httplib::SSLServer &server) {
        // Set about page
        server.Get(
            Pages::projects(),           // address on site
            [&](const httplib::Request &req, httplib::Response &res) {
                // Load template
                inja::Template tmpt = env.parse_template("./app/html/projects.html");

                // Build data
                page_data["nothing"] = "nothing";
                // page_data["lang"] = lang;

                // render content   
                res.set_content(env.render(tmpt, page_data).c_str(), "text/html");
            }
        );
    }

private:

    inja::Environment env;
    inja::json page_data;

};