//
// Created by HANYOUNG PARK on 5/13/22.
//

#include "NetworkService.h"
#include <iostream>
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <cpprest/http_listener.h>              // HTTP server
#include <cpprest/json.h>                       // JSON library
#include <cpprest/uri.h>                        // URI library
#include <cpprest/ws_client.h>                  // WebSocket client
#include <cpprest/containerstream.h>            // Async streams backed by STL containers
#include <cpprest/interopstream.h>              // Bridges for integrating Async streams with STL and WinRT streams
#include <cpprest/rawptrstream.h>               // Async streams backed by raw pointer to memory
#include <cpprest/producerconsumerstream.h>     // Async streams for producer consumer scenarios

//using namespace std;
using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams

namespace HanyoungparkClient::NetworkService {
    NetworkService::NetworkService() {
    }

    NetworkService::~NetworkService() {
    }

    int NetworkService::getStock(const std::string& symbol) const {
        double price = 0.f;
        auto request = http_client(U(BACKEND_URI))
                .request(methods::GET, uri_builder(U("stocks/KRW")).to_string())
                .then([](const http_response& response){
                    return response.extract_json();
                })
                .then([&price](json::value jsonObject){
                    price = jsonObject[U("price")].as_double();
                });
        try {
            request.wait();
        } catch (const std::exception& ex) {
            std::cout << ex.what() << std::endl;
        }
        return price;
    }
} // NetworkService::NetworkService
