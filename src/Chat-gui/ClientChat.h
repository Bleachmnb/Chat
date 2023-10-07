#pragma once


#include <cpprest/http_client.h>
#include <cpprest/filestream.h>

using namespace std;
using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;

namespace ClientChat
{
	bool Register(const char* email, const char* password);
	bool Login(const char* email, const char* password);


}