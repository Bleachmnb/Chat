#include "gui.h"
#include <string> 


void gui::Init()
{
	gui::lpWindowName = "Chat";
	gui::vWindowSize = { 1280, 800 };
	gui::WindowFlags = ImGuiWindowFlags_NoCollapse;
	gui::bDraw = true;
}

void gui::Active(bool x)
{
	gui::bDraw = x;
}

bool gui::isActive()
{
	return gui::bDraw == true;
}

void gui::ChatStyle()
{
	ImVec4* colors = ImGui::GetStyle().Colors;
	{
		colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);

		colors[ImGuiCol_FrameBg] = ImColor(11, 11, 11, 255);
		colors[ImGuiCol_FrameBgHovered] = ImColor(11, 11, 11, 255);
		colors[ImGuiStyleVar_SelectableTextAlign] = ImVec4(0.5f, 0.5f, 0, 0);

		colors[ImGuiCol_TextDisabled] = ImVec4(0.37f, 0.37f, 0.37f, 1.00f);
	}

	ImGuiStyle* style = &ImGui::GetStyle();
	{
		style->WindowPadding = ImVec2(4, 4);
		style->WindowBorderSize = 0.f;

		style->FramePadding = ImVec2(8, 6);
		style->FrameRounding = 3.f;
		style->FrameBorderSize = 1.f;
	}
}

void gui::FormStyle()
{
	ImVec4* colors = ImGui::GetStyle().Colors;
	{
		colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);

		colors[ImGuiCol_FrameBg] = ImColor(11, 11, 11, 255);
		colors[ImGuiCol_FrameBgHovered] = ImColor(11, 11, 11, 255);
		colors[ImGuiStyleVar_SelectableTextAlign] = ImVec4(0.5f, 0.5f, 0, 0);

		colors[ImGuiCol_TextDisabled] = ImVec4(0.37f, 0.37f, 0.37f, 1.00f);
	}

	ImGuiStyle* style = &ImGui::GetStyle();
	{
		style->WindowPadding = ImVec2(4, 4);
		style->WindowBorderSize = 0.f;

		style->FramePadding = ImVec2(8, 6);
		style->FrameRounding = 3.f;
		style->FrameBorderSize = 1.f;
	}
}

void gui::TextWithPos(const char* Text, ImVec2 Pos, bool IsTextDisabilited)
{

	ImGui::SetCursorPos(Pos);
	if (IsTextDisabilited)
		ImGui::TextDisabled(Text);
	else
		ImGui::Text(Text);
}

void gui::InputTextWithPos(const char* label, char *buf, size_t size, ImVec2 Pos, ImGuiInputTextFlags_ flag)
{
	ImGui::SetCursorPos(Pos);
	ImGui::InputText(label, buf, size, flag);
}

bool gui::CheckBoxWithPos(const char* label, bool* v, ImVec2 Pos)
{
	ImGui::SetCursorPos(Pos);
	return ImGui::Checkbox(label,v);
}

bool gui::ButtonWithPos(const char* Label, ImVec2 Size, ImVec2 Pos)
{
	ImGui::SetCursorPos(Pos);
	return ImGui::Button(Label, Size);
}

bool gui::BeginChildWithPos(const char *Label, ImVec2 Size, bool Border, ImVec2 Pos)
{
	ImGui::SetCursorPos(Pos);
	return ImGui::BeginChild(Label, Size, Border);
}

void gui::TextWithBox(const char* Text, ImVec2 Pos, bool IsTextDisabilited)
{
	ImGui::Selectable("##test", true, ImGuiSelectableFlags_Disabled);
	gui::TextWithPos(Text, Pos, IsTextDisabilited);
}

void gui::LoginForm()
{
	ImGuiInputTextFlags_	flag;
	NameState = "Login";

	BeginChildWithPos("##MainPanel", ImVec2(600, 500), true, ImVec2(ImGui::GetWindowSize().x / 2 - 300, 180));
	TextWithPos("Welcome Back", ImVec2(ImGui::GetWindowSize().x / 2 - 390, 60), true);
	TextWithPos("Email", ImVec2(100, 180), false);
	InputTextWithPos("##Email", UserProfile::Email, IM_ARRAYSIZE(UserProfile::Email), ImVec2(100, 200));
	CheckBoxWithPos("##toggle*", &HidePassword, ImVec2(100, 280));

	if (HidePassword == true) flag = ImGuiInputTextFlags_None;
	else flag = ImGuiInputTextFlags_Password;

	TextWithPos("Password", ImVec2(100, 230), false);
	InputTextWithPos("##Password", UserProfile::Password, IM_ARRAYSIZE(UserProfile::Password), ImVec2(100, 250), flag);

	ImGui::SetCursorPos(ImVec2(210, 320));
	if (ImGui::Button("Login", ImVec2(170, 50)))
	{
		if (HttpsConnection::Login(UserProfile::Email, UserProfile::Password))
		{
			ImGui::Text("succesfull Loged");
			
			std::string TextToFile = std::string("Logged\nEmail=");
			TextToFile.append(UserProfile::Email);
			TextToFile.append("\nPassword=");
			TextToFile.append(UserProfile::Password);
			UserProfile::WriteFile(TextToFile.c_str());
			UserProfile::Logged = true;
		}
		else
		{
			ImGui::Text("Failed to Loged");

		}
	}
	ImGui::EndChild();
}

void gui::RegiterForm()
{
	ImGuiInputTextFlags_	flag;

	//ImGui::Text("Loading %c", "|/-\\"[(int)(ImGui::GetTime() / 0.05f) & 3]);
	BeginChildWithPos("##MainPanel", ImVec2(700, 500), true, ImVec2(308, 180));
	{
		TextWithPos("Welcome Back", ImVec2((ImGui::GetWindowSize().x / 2 - 100) + 70, 60), true);
		TextWithPos("Create Account", ImVec2((ImGui::GetWindowSize().x / 2 - 106) + 70, 110), false);
		TextWithPos("Email", ImVec2(100 + 45, 180), false);
		InputTextWithPos("##Email", UserProfile::Email, IM_ARRAYSIZE(UserProfile::Email), ImVec2(100 + 45, 200));
		CheckBoxWithPos("##toggle*", &HidePassword, ImVec2(150, 340));

		if (HidePassword == true) flag = ImGuiInputTextFlags_None;
		else flag = ImGuiInputTextFlags_Password;

		TextWithPos("Create Password", ImVec2(100 + 45, 230), false);
		InputTextWithPos("##CreatePassword", UserProfile::Password, IM_ARRAYSIZE(UserProfile::Password), ImVec2(100 + 45, 250), flag);

		TextWithPos("Confirm Password", ImVec2(100 + 45, 280), false);
		InputTextWithPos("##ConfirmPassword", UserProfile::ConfermationPassword, IM_ARRAYSIZE(UserProfile::ConfermationPassword), ImVec2(100 + 45, 300), flag);

		if (ButtonWithPos("Register", ImVec2((ImGui::GetWindowSize().x / 2), 50), ImVec2(170 + 35, 340)))
		{
			if (UserProfile::CheckPassword(UserProfile::Password) && strcmp(UserProfile::Password, UserProfile::ConfermationPassword) == 0)
			{
				if (HttpsConnection::Register(UserProfile::Email, UserProfile::Password))
				{
					ImGui::Text("succesfull regitration");
					UserProfile::Registed = true;
				}
				else
					ImGui::Text("Email or Passowrd not avabile");
			}
			else if (UserProfile::CheckPassword(UserProfile::Password) == false)
			{
				ImGui::Text("the password does not meet the security criteri");
			}
			else if (strcmp(UserProfile::Password, UserProfile::ConfermationPassword) != 0)
				ImGui::Text("password and confirmation password have differance");
		}
	}
	ImGui::EndChild();
}

void gui::ChatPage()
{
	ImGui::SetCursorPos(ImVec2(200, 100));
	ImGui::BeginChild("##MainPanel", ImVec2(900, 600), true);
	{
		if (gui::SendChatMessage)
		{
			gui::TextWithBox(UserProfile::Message, ImVec2(20, 10), false);
		}
	}
	ImGui::EndChild();
	ImGui::SetCursorPos(ImVec2(230 , ImGui::GetWindowSize().y - 60 ));
	ImGui::PushItemWidth((ImGui::GetWindowSize().x / 2 - 220)  * 2);
	if (ImGui::InputText("##ChatMessage", UserProfile::Message, IM_ARRAYSIZE(UserProfile::Message), ImGuiInputTextFlags_EnterReturnsTrue))
	{
		gui::SendChatMessage = true;
	}
}

void gui::ServerDownPage()
{
	ImGui::Text("cazzo");
}

void gui::MainGui(HttpsConnection::ConnectioServer &Server)
{
	if (isActive() && !ServerOff)
	{
		ImGui::SetNextWindowSize(vWindowSize, ImGuiCond_Once);
		ImGui::Begin(lpWindowName, &bDraw, WindowFlags);
		{
			if (Server.GetConnectionState() != 1 && !Server.CheckServer())
			{
				ServerOff = true;
			}

			if (UserProfile::Logged)
			{
				ChatPage();
			}
			else if (!UserProfile::Registed && !UserProfile::Logged)
			{
				RegiterForm();
			}
			else if (UserProfile::Registed || !UserProfile::Logged)
			{
				LoginForm();
			}
	
		}
		ImGui::End();
	}
	else
	{
		ImGui::SetNextWindowSize(vWindowSize, ImGuiCond_Once);
		ImGui::Begin(lpWindowName, &bDraw, WindowFlags);
		{
			ImGui::Text("Server is off");
			gui::ButtonWithPos("##TryConnection", ImVec2(50, 50), ImVec2(100, 100));
		}
	}
#ifdef _WINDLL
	if (GetAsyncKeyState(VK_INSERT) & 1)
		bDraw = !bDraw;
#endif
}