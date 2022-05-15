#include "NetworkService.h"
#include <iostream>
#include <cpprest/http_client.h>
#include <cpprest/http_listener.h>              // HTTP server
#include <cpprest/json.h>                       // JSON library
#include <cpprest/uri.h>                        // URI library
#include <cpprest/interopstream.h>              // Bridges for integrating Async streams with STL and WinRT streams

using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams

namespace HanyoungparkClient::NetworkService {
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
