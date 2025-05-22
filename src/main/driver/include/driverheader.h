#pragma once

#ifdef __cplusplus
extern "C" {
#endif

void c_doThing();

#ifdef __cplusplus
}  // extern "C"
#endif

#ifdef DESKTOP
#include <string>
#include "imgui.h"
#include "HALSimExt.h"
#include "hal/Extensions.h"
inline void init_sim() {
  HAL_RegisterExtensionListener(nullptr, [](void*, const char* name, void* data) {
      if (std::string_view{name} == HALSIMGUI_EXT_ADDGUILATEEXECUTE) {
        reinterpret_cast<vendor::AddGuiLateExecuteFn>(data)([] {
            ImGui::Begin("My Library");
            ImGui::Text("Hello from My Library!");
            ImGui::End();
        });
      }
  });
}
#endif