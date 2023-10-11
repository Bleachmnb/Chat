
#include "ClientChat.h"


bool CheckError(const wchar_t* str)
{
    string res = utility::conversions::to_utf8string(str);

    cout << res;
    if (res.string::find("\"error\": true") == string::npos)
        return true;
    return false;
}

bool ClientChat::Register(const char *email, const char *password)
{    
    string request; 

    request.append("http://25.53.147.26/register/?email=");

    request.append(email);
    request.append("&");
    request.append("password=");
    request.append(password);

    uri url = uri::encode_uri(utility::conversions::to_string_t(request));

    http_client client(url);

    auto resp = client.request(U("GET"));
    cout << resp.is_done();
    if (resp.is_done() == 0)
    {
        
        return false;
    }
    auto result = resp.get().extract_json(true).get();


    json::value& v = result;

    utility::string_t jsonval = v.serialize();
        
    return CheckError(jsonval.c_str());
}

bool ClientChat::Login(const char* email, const char* password)
{
    string request;

    request.append("http://25.53.147.26/login/?email=");

    request.append(email);
    request.append("&");
    request.append("password=");
    request.append(password);
    uri url = uri::encode_uri(utility::conversions::to_string_t(request));

    http_client client(url);

    auto resp = client.request(U("GET"));
    if (resp.is_done() == 0)
    {

        return false;
    }
    auto result = resp.get().extract_json(true).get();


    json::value& v = result;

    utility::string_t jsonval = v.serialize();
    
    return CheckError(jsonval.c_str());
}