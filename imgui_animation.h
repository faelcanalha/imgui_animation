#pragma once
#ifndef _IMANIMATION_H_
#define _IMANIMATION_H_

#include <functional> // Include for std::function

#include <ImGui/imgui.h>
#include <ImGui/imgui_internal.h>

namespace ImAnimation
{
	bool Fade(std::function<void()> components, float duration = 4.0f);
	bool FadeInOut(std::function<void()> components, bool isChecked, float duration = 4.0f);
	bool FadeDown(std::function<void()> components, float endY, float duration = 4.0f);
	bool FadeUp(std::function<void()> components, float endY, float duration = 4.0f);
	bool FadeLeft(std::function<void()> components, float endX, float duration = 4.0f);
	bool FadeRight(std::function<void()> components, float endX, float duration = 4.0f);
}

#endif // _IMANIMATION_H_