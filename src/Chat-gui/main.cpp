






//#define _WIN32_WINNT 0x0601

//
//#pragma comment(lib, "crypt32")
//#pragma comment(lib, "ws2_32.lib")
//#include "Chat.h"

//#include<Windows.h>

//#ifdef _WINDLL
//
//HANDLE hCurrentUIThread = nullptr;
//
//BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
//{
//    if (fdwReason == DLL_PROCESS_ATTACH)
//    {
//        DisableThreadLibraryCalls(hinstDLL);
//        UI::hCurrentModule = hinstDLL;
//        hCurrentUIThread = CreateThread(nullptr, NULL, (LPTHREAD_START_ROUTINE)UI::Render, nullptr, NULL, nullptr);
//    }
//
//    if (fdwReason == DLL_PROCESS_DETACH)
//        TerminateThread(hCurrentUIThread, 0);
//
//    return TRUE;
//}
//

#define _HAS_STD_BYTE 0
//#endif 
#include"Chat.h"


int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nShowCmd)
{
    EngineGui::InitApp();
    EngineGui::Render();
    EngineGui::DestroyAll();
}




