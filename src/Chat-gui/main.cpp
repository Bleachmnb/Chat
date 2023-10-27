#define _WIN32_WINNT 0x0601

//
//#pragma comment(lib, "crypt32")
//#pragma comment(lib, "ws2_32.lib")


#define _HAS_STD_BYTE 0

#include "EngineGui/EngineGui.h"
#include <thread>
#include"Chat.h"


void ListenersServer()
{
    //using boost::asio::ip::tcp;
    //try
    //{
    //    boost::asio::io_context io_context;

    //    tcp::resolver resolver{ io_context };

    //    auto endpoint = resolver.resolve("25.53.147.26", "9001");

    //    tcp::socket socket(io_context);

    //    boost::asio::connect(socket, endpoint);
    //    while (true)
    //    {
    //        std::cout << "test\n";
    //        std::array<char, 128> buf{};
    //        boost::system::error_code error;

    //        size_t len = socket.read_some(boost::asio::buffer(buf), error);

    //        if (error == boost::asio::error::eof)
    //        {
    //            break;
    //        }
    //        else if(error)
    //        {
    //            throw boost::system::system_error(error);
    //        }
    //        std::cout.write(buf.data(), len);
    //    }
    //}
    //catch (std::exception& e)
    //{
    //    std::cout << "test\n";

    //    std::cerr << e.what() << std::endl;
    //}

}

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
{
    //std::thread Listeners(ListenersServer);

    EngineGui::InitApp();
    EngineGui::Render();
    EngineGui::DestroyAll();
    
    //Listeners.join();
}

//int main()
//{
//    std::thread Listeners (ListenersServer);
//    Listeners.join();
//    //while (true) {
//
//    //}
//    std::cout << "foo and bar completed.\n";
//
//}