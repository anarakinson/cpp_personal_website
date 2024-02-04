#pragma once 


#include <httplib.h>
#include <inja/inja.hpp>
#include <json/json.h>

#include <stdlib.h>

#include <iostream>
#include <fstream>
#include <string>



void GetMain(httplib::SSLServer &server) {
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
}


void GetAbout(httplib::SSLServer &server) {
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
}


void GetContacts(httplib::SSLServer &server) {
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
}


void GetProjects(httplib::SSLServer &server) {
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
}

