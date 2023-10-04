#include "Chat.h"

using namespace Chat;

int __stdcall wWinMain(HINSTANCE instance, HINSTANCE previusInstance, PWSTR arguments, int CommandShow)
{

	gui::CreateHWindow("Chat Login", 1280, 800);
	gui::CreateDevice();
	gui::CreateImGui();


	while (gui::exit)
	{
		gui::BeginRender();
		ImGuiChat::MainGui();
		gui::EndRender();
		std::this_thread::sleep_for(std::chrono::milliseconds(0));
	}

	gui::DestroyImGui();
	gui::DestroyDevice();
	gui::DestroyHWindow();


	return EXIT_SUCCESS;
}

//int main()
//{
//	if (ClientChat::Register("edoardo", "edoardo11") == true)
//	{
//		cout << "anima\n";
//	}
//	else
//		cout << "sole\n";
//	while (1)
//	{
//
//	}
//	return 0;
//}
