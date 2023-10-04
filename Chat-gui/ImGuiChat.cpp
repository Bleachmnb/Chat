#include "ImGuiChat.h"

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

void ImGuiChat::LoginForm()
{
	ImGui::SetCursorPos(ImVec2(gui::WIDTH / 2 - 300,180));
	ImGui::BeginChild("##MainPanel", ImVec2(600, 500), true);
	{
		ImGui::SetCursorPos(ImVec2(gui::WIDTH / 2 - 390, 60));
		ImGui::TextDisabled("Welcome Back");

		ImGui::SetCursorPos(ImVec2(gui::WIDTH / 2 - 423, 110));
		ImGui::Text("Login into your account ");

		ImGui::SetCursorPos(ImVec2(100, 180));
		ImGui::Text("Email");
		ImGui::SetCursorPos(ImVec2(100, 200));
		ImGui::InputText("##Email", user::Email, IM_ARRAYSIZE(user::Email));

		ImGui::SetCursorPos(ImVec2(100, 230));
		ImGui::Text("Password");
		ImGui::SetCursorPos(ImVec2(100, 250));
		ImGui::InputText("##Password", user::Password, IM_ARRAYSIZE(user::Password), ImGuiInputTextFlags_Password);

		ImGui::SetCursorPos(ImVec2(210, 320));
		ImGui::Button("Login", ImVec2(170, 50));
		ImGui::SetCursorPos(ImVec2(100, 285));
		ImGui::Selectable("Don't have an account? sign in");
	}
	ImGui::EndChild();
}

void ImGuiChat::RegiterForm()
{
	NameState = "Register";
	ImGui::SetCursorPos(ImVec2(gui::LineX + 40, 180));
	ImGui::BeginChild("##MainPanel", ImVec2(700, 500), true);
	{

		ImGui::SetCursorPos(ImVec2(gui::LineX + 70, 60));
		ImGui::TextDisabled("Welcome Back");

		ImGui::SetCursorPos(ImVec2((gui::WIDTH / 2 - 400) + 70, 110));
		ImGui::Text("Create Account");

		ImGui::SetCursorPos(ImVec2(100 + 45, 180));
		ImGui::Text("Email");
		ImGui::SetCursorPos(ImVec2(100 + 45, 200));
		ImGui::InputText("##Email", user::Email, 40);

		ImGui::SetCursorPos(ImVec2(100 + 45, 230));
		ImGui::Text("Create Password");
		ImGui::SetCursorPos(ImVec2(100 + 45, 250));
		ImGui::InputText("##CreatePassword", user::Password, IM_ARRAYSIZE(user::Password), ImGuiInputTextFlags_Password);


		ImGui::SetCursorPos(ImVec2(100 + 45, 280));
		ImGui::Text("Confirm Password");
		ImGui::SetCursorPos(ImVec2(100 + 45, 300));
		ImGui::InputText("##ConfirmPassword", user::ConfermationPassword, IM_ARRAYSIZE(user::ConfermationPassword), ImGuiInputTextFlags_Password);

		ImGui::SetCursorPos(ImVec2(170 + 70, 340));

		const auto Button = ImGui::Button("Register", ImVec2(gui::LineX, 50));

		user::ButtonPressed = (Button && !user::ButtonPressed) ? true : (user::ButtonPressed && Button) ? false : user::ButtonPressed;

		if (user::ButtonPressed)
		{
			if (user::CheckPassword(user::Password) && strcmp(user::Password, user::ConfermationPassword) == 0)
			{
				if (ClientChat::Register(user::Email, user::Password))
				{
					ImGui::Text("succesfull regitration");
				}
				else
					ImGui::Text("Email or Passowrd not avabile");
			}
			else if(user::CheckPassword(user::Password) == false)
			{
				ImGui::Text("the password does not meet the security criteri");
			}
			else if(strcmp(user::Password, user::ConfermationPassword) != 0)
				ImGui::Text("password and confirmation password have differance");
		}
	}
	ImGui::EndChild();
}



void ImGuiChat::MainGui()
{
	ImGui::SetNextWindowPos({ 0, 0 });
	ImGui::SetNextWindowSize({ gui::WIDTH, gui::HEIGHT });
	ImGui::Begin(NameState, &gui::exit, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove);

	load_styles();
	if (user::Logged)
	{
		RegiterForm();
	}
	else
	{
		RegiterForm();
	}
	ImGui::End();

}