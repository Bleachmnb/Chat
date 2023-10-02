#include "gui.h"

#include <thread>


int __stdcall wWinMain(HINSTANCE instance, HINSTANCE previusInstance, PWSTR arguments, int CommandShow)
{


	gui::CreateHWindow("Chat Login", 500, 500);
	gui::CreateDevice();
	gui::CreateImGui();

	while (gui::exit)
	{
		gui::BeginRender();
		gui::Render();
		gui::EndRender();


		std::this_thread::sleep_for(std::chrono::milliseconds(0));
	}

	gui::DestroyImGui();
	gui::DestroyDevice();
	gui::DestroyHWindow();

	return EXIT_SUCCESS;
}
