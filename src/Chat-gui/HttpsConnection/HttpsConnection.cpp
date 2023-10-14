
#include "HttpsConnection.h"
#include "../../ImGui/imgui.h"

bool HttpsConnection::ConnectioServer::CheckServer()
{
    //if (this->GetConnectionState() == 2)
    //    return true;
    //if (this->GetConnectionState() == 1)
    //    return false;
    //
    //uri url = uri::encode_uri(utility::conversions::to_string_t(CheckServerIp));

    //http_client client(url);

    //auto request_result = client.request(web::http::methods::GET);
    //auto resp = client.request(U("GET"));

    //if (!resp.is_done() || request_result.get().status_code() != 200)
    //{
    //    this->SetConnectionState(1);
    //    return false;
    //}

    //this->SetConnectionState(2);
    return true;
}

HttpsConnection::ConnectioServer::ConnectioServer()
{

}

HttpsConnection::ConnectioServer::~ConnectioServer()
{

}

bool CheckError(const wchar_t* str)
{
    //string res = utility::conversions::to_utf8string(str);

    //cout << res;
    //if (res.string::find("\"error\": true") == string::npos)
    //    return true;
    return false;
}

bool HttpsConnection::Register(const char *email, const char *password)
{    
    //string request; 

    //request.append("http://25.53.147.26/register/?email=");

    //request.append(email);
    //request.append("&");
    //request.append("password=");
    //request.append(password);

    //uri url = uri::encode_uri(utility::conversions::to_string_t(request));

    //http_client client(url);

    //auto resp = client.request(U("GET"));
    //cout << resp.is_done();
    //if (resp.is_done() == 0)
    //{
    //    
    //    return false;
    //}
    //auto result = resp.get().extract_json(true).get();


    //json::value& v = result;

    //utility::string_t jsonval = v.serialize();
    //    
    //return CheckError(jsonval.c_str());
    return true;
}

bool HttpsConnection::Login(const char* email, const char* password)
{
 /*   string request;

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
    
    return CheckError(jsonval.c_str());*/
    return true;
}