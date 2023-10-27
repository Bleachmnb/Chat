#include "GuiUtils.h"

void PasswordStrengthCheck()
{
	//ColorBox("##SquareA", ImVec2{ 30, 5 }, ImVec2(100 + 200, 240));
	//ColorBox("##SquareB", ImVec2{ 30, 5 }, ImVec2(100 + 250, 240));
	//ColorBox("##SquareC", ImVec2{ 30, 5 }, ImVec2(100 + 300, 240));
	//ColorBox("##SquareD", ImVec2{ 30, 5 }, ImVec2(100 + 350, 240));
}

void GuiUtils::ColorBox(const char* label, ImVec2 Size, ImVec2 Pos)
{
	ImGui::SetCursorPos(Pos);
	ImGui::Selectable(label, true, ImGuiSelectableFlags_Disabled, Size);
}

void GuiUtils::TextWithPos(const char* Text, ImVec2 Pos, bool IsTextDisabilited)
{

	ImGui::SetCursorPos(Pos);
	if (IsTextDisabilited)
		ImGui::TextDisabled(Text);
	else
		ImGui::Text(Text);
}

void GuiUtils::InputTextWithPos(const char* label, char* buf, size_t size, ImVec2 Pos, ImGuiInputTextFlags_ flag)
{
	ImGui::SetCursorPos(Pos);
	ImGui::InputText(label, buf, size, flag);
}

bool GuiUtils::CheckBoxWithPos(const char* label, bool* v, ImVec2 Pos)
{
	ImGui::SetCursorPos(Pos);
	return ImGui::Checkbox(label, v);
}

bool GuiUtils::ButtonWithPos(const char* Label, ImVec2 Size, ImVec2 Pos)
{
	ImGui::SetCursorPos(Pos);
	return ImGui::Button(Label, Size);
}

bool GuiUtils::BeginChildWithPos(const char* Label, ImVec2 Size, bool Border, ImVec2 Pos)
{
	ImGui::SetCursorPos(Pos);
	return ImGui::BeginChild(Label, Size, Border);
}

void GuiUtils::TextWithBox(const char* Text, ImVec2 Pos, bool IsTextDisabilited)
{
	ImGui::Selectable("##test", true, ImGuiSelectableFlags_Disabled);
	GuiUtils::TextWithPos(Text, Pos, IsTextDisabilited);
}