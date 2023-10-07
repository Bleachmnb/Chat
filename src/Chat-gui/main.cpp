#include "Chat.h"

int __stdcall wWinMain(HINSTANCE instance, HINSTANCE previusInstance, PWSTR arguments, int CommandShow)
{
	engine::CreateHWindow("Chat Login", 1280, 800);
	engine::CreateDevice();
	engine::CreateImGui();

	//UserProfile::MakeConfigDir();
	//UserProfile::CheckConfigFile();

	while (engine::exit)
	{
		engine::BeginRender();
		gui::MainGui();
		engine::EndRender();
		std::this_thread::sleep_for(std::chrono::milliseconds(0));
	}

	engine::DestroyImGui();
	engine::DestroyDevice();
	engine::DestroyHWindow();


	return EXIT_SUCCESS;
}

//int main()
//{
//
//	UserProfile::MakeConfigDir();
//	UserProfile::CheckConfigFile();
//
//	while (1)
//	{
//
//	}
//	return 0;
//}
