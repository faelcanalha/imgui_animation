# ImAnimation
A Simple Animation Extension for ImGui may soon evolve into something significant.

- Created by faelcanalha

# Fade's Animation
```c++
#include <imgui/imgui_animation.h>

int main(int, char**) {
  ...
  while (!done) {
     ...
      ImAnimation::Fade([]() {
        ImGui::Text("Hello!");
        // Others Widgets
      });

      ImAnimation::FadeDown([]() { /* Same thing for FadeUp, FadeRight and FadeLeft */
        ImGui::Text("Hello!");
        // Others Widgets
      }, 50.f);

      static bool isEnabled = true; // True appears and False disappears
      ImAnimation::FadeInOut([]() {
        ImGui::Text("Hello!");
        // Others Widgets
      }, isEnabled);
  }
}
```

# Chaning Fade In Out
```c++
#include <imgui/imgui_animation.h>

int main(int, char**) {
  ...
  while (!done) {
     ...
      static bool isEnabled = true; // True appears and False disappears
      ImAnimation::FadeInOut([]() {
        ImGui::Text("Hello!");
        // Others Widgets
      }, isEnabled);

      if (ImGui::Button("Show Or Hide")) {
          isEnabled = !isEnabled;
      }
  }
}
```