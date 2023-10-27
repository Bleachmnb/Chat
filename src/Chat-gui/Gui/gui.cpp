#include "gui.h"
#include <string> 
using namespace GuiUtils;

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

bool FriendIcon(ChatSystem::App& chat, size_t index)
{
	ImU32 color{};

	switch ((int)chat.User.GetFriend(index).GetState())
	{
		case(0):
			color = IM_COL32(255, 0, 0, 255);
			break;
		case(1):
			color = IM_COL32(0, 128, 0, 255);
			break;
		case(2):
			color = IM_COL32(255, 255, 0, 255);
			break;
		case(3):
			color = IM_COL32(192, 192, 192, 255);
			break;
		default:
			break;
	}

	ImGui::Text((chat.User.GetFriend(index).GetName()));
	ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(ImGui::GetWindowPos().x + 150, ImGui::GetWindowPos().y + 16), 5, color, 10);
	ImGui::SetCursorPos(ImVec2(10, 10));
	return ImGui::InvisibleButton("##SelectChat",ImVec2(10,10));
}

void gui::FrientList(ChatSystem::App& chat)
{
	float YPos = 50;
	ImGui::SetNextWindowSize(ImVec2(220, 700));
	ImGui::Begin("FriendList", &bDraw, ImGuiWindowFlags_NoResize);
	{
		for (size_t i = 0; i < chat.User.FriendList.size(); i++)
		{
			ImGui::SetCursorPos(ImVec2(10, YPos));
			YPos += 60;
			ImGui::BeginChild(std::to_string(i).c_str(), ImVec2(180, 40), true);
			FriendIcon(chat, i);
			ImGui::EndChild();
		}
	}
	ImGui::End();
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

		//PasswordStrengthCheck();

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

void gui::ChatPage(ChatSystem::App& chat)
{
	FrientList(chat);
	if (chat.User.FriendList.size() < 1)
		return;
	ImGui::SetCursorPos(ImVec2(200, 100));
	ImGui::BeginChild("##MainPanel", ImVec2(900, 600), true);
	{
		if (gui::SendChatMessage)
		{
	/*		chat.ChatFriend.AddMessage(UserProfile::Message);
			memset(UserProfile::Message, '\0', 25);
			gui::TextWithBox(chat.ChatFriend.ReturnMessage(0), ImVec2(20, 10), false);
			SendChatMessage = false;*/
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

void gui::MainGui(HttpsConnection::ConnectioServer &Server, ChatSystem::App &chat)
{
	if (isActive() && !ServerOff)
	{
		ImGui::SetNextWindowSize(vWindowSize, ImGuiCond_Once);
		ImGui::Begin(lpWindowName, &bDraw, WindowFlags);
		ChatPage(chat);
			//if (UserProfile::Logged)
			//	ChatPage();
			//else if (!UserProfile::Registed && !UserProfile::Logged)
			//	RegiterForm();
			//else if (UserProfile::Registed || !UserProfile::Logged)
			//	LoginForm();
		ImGui::End();
	}
	else
	{
		ImGui::SetNextWindowSize(vWindowSize, ImGuiCond_Once);
		ImGui::Begin(lpWindowName, &bDraw, WindowFlags);
		{
			ImGui::Text("Server is off");
			GuiUtils::ButtonWithPos("##TryConnection", ImVec2(50, 50), ImVec2(100, 100));
		}
	}
#ifdef _WINDLL
	if (GetAsyncKeyState(VK_INSERT) & 1)
		bDraw = !bDraw;
#endif
}