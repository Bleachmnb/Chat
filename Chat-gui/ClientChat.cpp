
#include "ClientChat.h"


bool CheckError(const wchar_t* str)
{
    string res = utility::conversions::to_utf8string(str);

    if (res.string::find("\"error\": true") == string::npos)
        return true;
    return false;
}

bool ClientChat::Register(const char *email, const char *password)
{    
    string request; 

    request.append("http://25.53.147.26/register/?username=");

    request.append(email);
    request.append("&");
    request.append("password=");
    request.append(password);

    uri url = uri::encode_uri(utility::conversions::to_string_t(request));

    http_client client(url);

    auto resp = client.request(U("GET")).get();

    auto result = resp.extract_json(true).get();


    json::value& v = result;

    utility::string_t jsonval = v.serialize();
        
    return CheckError(jsonval.c_str());
}
