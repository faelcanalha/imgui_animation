// Created By: https://github.com/faelcanalha | Discord: faelcanalha
#include "imgui_animation.h"

bool ImAnimation::Fade(std::function<void()> widgets, float duration)
{
	static float FadeAlpha;
	FadeAlpha = ImLerp(FadeAlpha, 1.0f, ImGui::GetIO().DeltaTime * duration);

	ImGui::PushStyleVar(ImGuiStyleVar_Alpha, FadeAlpha);
	{
		ImGui::BeginGroup();
		{
			widgets();
		}
		ImGui::EndGroup();
	}
	ImGui::PopStyleVar();

	return std::abs(FadeAlpha - 1.f) < 0.1f;
}

bool ImAnimation::FadeInOut(std::function<void()> widgets, bool isChecked, float duration)
{
	static float FadeAlpha;
	FadeAlpha = ImLerp(FadeAlpha, isChecked ? 1.0f : 0.f, ImGui::GetIO().DeltaTime * duration);

	ImGui::PushStyleVar(ImGuiStyleVar_Alpha, FadeAlpha);
	{
		ImGui::BeginGroup();
		{
			widgets();
		}
		ImGui::EndGroup();
	}
	ImGui::PopStyleVar();

	return std::abs(FadeAlpha - 1.f) < 0.1f;
}

bool ImAnimation::FadeDown(std::function<void()> widgets, float endY, float duration)
{
	static float Fade;
	Fade = ImLerp(Fade, endY, ImGui::GetIO().DeltaTime * duration);

	ImGui::SetCursorPosY(ImGui::GetCursorPosY() + Fade);
	ImGui::BeginGroup();
	{
		widgets();
	}
	ImGui::EndGroup();

	return std::abs(Fade - endY) < 1.0f;
}

bool ImAnimation::FadeUp(std::function<void()> widgets, float endY, float duration)
{
	static float Fade;
	Fade = ImLerp(Fade, endY, ImGui::GetIO().DeltaTime * duration);

	ImGui::SetCursorPosY(ImGui::GetCursorPosY() - Fade);
	ImGui::BeginGroup();
	{
		widgets();
	}
	ImGui::EndGroup();

	return std::abs(Fade - endY) < 1.0f;
}

bool ImAnimation::FadeLeft(std::function<void()> widgets, float endX, float duration)
{
	static float Fade;
	Fade = ImLerp(Fade, endX, ImGui::GetIO().DeltaTime * duration);

	ImGui::SetCursorPosX(ImGui::GetCursorPosX() - Fade);
	ImGui::BeginGroup();
	{
		widgets();
	}
	ImGui::EndGroup();

	return std::abs(Fade - endX) < 1.0f;
}

bool ImAnimation::FadeRight(std::function<void()> widgets, float endX, float duration)
{
	static float Fade;
	Fade = ImLerp(Fade, endX, ImGui::GetIO().DeltaTime * duration);

	ImGui::SetCursorPosX(ImGui::GetCursorPosX() + Fade);
	ImGui::BeginGroup();
	{
		widgets();
	}
	ImGui::EndGroup();

	return std::abs(Fade - endX) < 1.0f;
}