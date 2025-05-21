#include "driverheader.h"
#include "hal/Extensions.h"
#include "HALSimExt.h"
#include <string_view>
#include <wpi/print.h>

extern "C" {

void init_sim() {
  HAL_RegisterExtensionListener(nullptr, [](void*, const char* name, void* data) {
      if (std::string_view{name} == HALSIMGUI_EXT_ADDGUILATEEXECUTE) {
        reinterpret_cast<vendor::AddGuiLateExecuteFn>(data)([] {
            wpi::println("Hey from vendordep");
        });
      }
  });
}

void c_doThing() {

}
}
