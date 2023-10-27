
#include "../../../ImGui/imgui.h"
#include "../../../ImGui/imgui_impl_dx11.h"
#include "../../../ImGui/imgui_impl_win32.h"

namespace GuiUtils
{
	void	ColorBox(const char* label, ImVec2 Size, ImVec2 Pos);
	void	TextWithPos(const char* Text, ImVec2 Pos, bool IsTextDisabilited);
	bool	CheckBoxWithPos(const char* label, bool* v, ImVec2 Pos);
	bool	ButtonWithPos(const char* Label, ImVec2 Size, ImVec2 Pos);
	void	InputTextWithPos(const char* label, char* buf, size_t size, ImVec2 Pos, ImGuiInputTextFlags_ flag = ImGuiInputTextFlags_None);
	bool	BeginChildWithPos(const char* Label, ImVec2 Size, bool Border, ImVec2 Pos);
	void	TextWithBox(const char* Text, ImVec2 Pos, bool IsTextDisabilited);
}