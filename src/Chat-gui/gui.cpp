#include "gui.h"

void load_styles()
{
	ImVec4* colors = ImGui::GetStyle().Colors;
	{
		colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);

		colors[ImGuiCol_FrameBg] = ImColor(11, 11, 11, 255);
		colors[ImGuiCol_FrameBgHovered] = ImColor(11, 11, 11, 255);
		colors[ImGuiStyleVar_SelectableTextAlign] = ImVec4(0.5f, 0.5f,0,0);

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

void Chatstyles()
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

void gui::LoginForm()
{
	ImGuiInputTextFlags_	flag;

	ImGui::SetCursorPos(ImVec2(engine::WIDTH / 2 - 300,180));
	ImGui::BeginChild("##MainPanel", ImVec2(600, 500), true);
	{
		ImGui::SetCursorPos(ImVec2(engine::WIDTH / 2 - 390, 60));
		ImGui::TextDisabled("Welcome Back");

		ImGui::SetCursorPos(ImVec2(engine::WIDTH / 2 - 423, 110));
		ImGui::Text("Login into your account ");

		ImGui::SetCursorPos(ImVec2(100, 180));
		ImGui::Text("Email");
		ImGui::SetCursorPos(ImVec2(100, 200));
		ImGui::InputText("##Email", UserProfile::Email, IM_ARRAYSIZE(UserProfile::Email));

		ImGui::SetCursorPos(ImVec2(100, 180));
		ImGui::Checkbox("##toggle*", &BlurredPass);
		if (BlurredPass == true)
		{
			flag = ImGuiInputTextFlags_None;
		}
		else
		{
			flag = ImGuiInputTextFlags_Password;
		}

		ImGui::SetCursorPos(ImVec2(100, 230));
		ImGui::Text("Password");
		ImGui::SetCursorPos(ImVec2(100, 250));
		ImGui::InputText("##Password", UserProfile::Password, IM_ARRAYSIZE(UserProfile::Password), flag);

		ImGui::SetCursorPos(ImVec2(210, 320));

		const auto Button = ImGui::Button("Login", ImVec2(170, 50));

		if (Button)
		{
			if (ClientChat::Login(UserProfile::Email, UserProfile::Password))
			{
				ImGui::Text("succesfull Loged");
				
				string TextToFile = string("Logged\n");
				TextToFile.append("Email=");
				TextToFile.append(UserProfile::Email);
				TextToFile.append("\n");
				TextToFile.append("Password=");
				TextToFile.append(UserProfile::Password);

				UserProfile::WriteFile(TextToFile.c_str());

				UserProfile::Logged = true;
			}
		}
		ImGui::SetCursorPos(ImVec2(100, 285));
		ImGui::Selectable("Don't have an account? sign in");


	}
	ImGui::EndChild();
}

void gui::RegiterForm()
{
	ImGuiInputTextFlags_	flag;

	NameState = "Register";
	ImGui::SetCursorPos(ImVec2(engine::LineX + 40, 180));
	ImGui::BeginChild("##MainPanel", ImVec2(700, 500), true);
	{

		ImGui::SetCursorPos(ImVec2(engine::LineX + 70, 60));
		ImGui::TextDisabled("Welcome Back");

		ImGui::SetCursorPos(ImVec2((engine::WIDTH / 2 - 400) + 70, 110));
		ImGui::Text("Create Account");

		ImGui::SetCursorPos(ImVec2(100 + 45, 180));
		ImGui::Text("Email");
		ImGui::SetCursorPos(ImVec2(100 + 45, 200));
		ImGui::InputText("##Email", UserProfile::Email, 40);

		ImGui::SetCursorPos(ImVec2(150, 340));
		ImGui::Checkbox("##toggle*", &BlurredPass);
		if (BlurredPass == true)
		{
			flag = ImGuiInputTextFlags_None;
		}
		else
		{
			flag = ImGuiInputTextFlags_Password;
		}

		ImGui::SetCursorPos(ImVec2(100 + 45, 230));
		ImGui::Text("Create Password");
		ImGui::SetCursorPos(ImVec2(100 + 45, 250));
		ImGui::InputText("##CreatePassword", UserProfile::Password, IM_ARRAYSIZE(UserProfile::Password), flag);


		ImGui::SetCursorPos(ImVec2(100 + 45, 280));
		ImGui::Text("Confirm Password");
		ImGui::SetCursorPos(ImVec2(100 + 45, 300));
		ImGui::InputText("##ConfirmPassword", UserProfile::ConfermationPassword, IM_ARRAYSIZE(UserProfile::ConfermationPassword), flag);

		
		ImGui::SetCursorPos(ImVec2(170 + 70, 340));

		if (ImGui::Button("Register", ImVec2(engine::LineX, 50)))
		{
			if (UserProfile::CheckPassword(UserProfile::Password) && strcmp(UserProfile::Password, UserProfile::ConfermationPassword) == 0)
			{
				if (ClientChat::Register(UserProfile::Email, UserProfile::Password))
				{
					ImGui::Text("succesfull regitration");
					UserProfile::Registed = true;
				}
				else
					ImGui::Text("Email or Passowrd not avabile");
			}
			else if(UserProfile::CheckPassword(UserProfile::Password) == false)
			{
				ImGui::Text("the password does not meet the security criteri");
			}
			else if(strcmp(UserProfile::Password, UserProfile::ConfermationPassword) != 0)
				ImGui::Text("password and confirmation password have differance");
		}
	}
	ImGui::EndChild();
}

void gui::ChatPage()
{
	NameState = "Chat";
	Chatstyles();
	ImGui::SetCursorPos(ImVec2(engine::LineX - 55, 60));
	ImGui::BeginChild("##MainPanel", ImVec2(900, 600), true);
	{
		ImGui::SetCursorPos(ImVec2(engine::WIDTH / 2 - 400, engine::HEIGHT - 100));
		ImGui::PushItemWidth(engine::WIDTH / 2 + 100);
		ImGui::InputText("##ChatMessage", UserProfile::Message, IM_ARRAYSIZE(UserProfile::Message));
	}
	ImGui::EndChild();
}

void gui::MainGui()
{
	ImGui::SetNextWindowPos({ 0, 0 });
	ImGui::SetNextWindowSize({ 1280,800});
	ImGui::Begin(NameState, &engine::exit, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove);
	load_styles();
	
	if(UserProfile::Logged)
	{
		ChatPage();
	}
	else if (!UserProfile::Registed)
	{
		RegiterForm();
	}
	else if (UserProfile::Registed || !UserProfile::Logged)
	{
		LoginForm();
	}
	
	ImGui::End();

}