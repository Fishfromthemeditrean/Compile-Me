#include <stdio.h>
#include <gdextension_interface.h> // Make sure this path matches your godot-cpp or engine headers

class dowrap {
public:
    void dosmth() {
        printf("i did smth\n");
    }
};

// 1. Mandatory minimum callback functions for Godot
void minimum_initialize(void *userdata, GDExtensionInitializationLevel p_level) {
    // This gets called by Godot at various initialization stages.
    // We only execute our logic once the Scene layer is ready.
    if (p_level == GDEXTENSION_INITIALIZATION_SCENE) {
        dowrap instance;
        instance.dosmth();
    }
}

void minimum_deinitialize(void *userdata, GDExtensionInitializationLevel p_level) {
    // Left blank intentionally, but must be present.
}

extern "C" {
    // 2. Your entry point must match Godot's expected signature and fill r_initialization
    GDExtensionBool dowrap_entry(
        GDExtensionInterfaceGetProcAddress p_get_proc_address,
        GDExtensionClassLibraryPtr p_library,
        GDExtensionInitialization *r_initialization
    ) {
        // Populate the struct fields Godot complained were null
        r_initialization->initialize = minimum_initialize;
        r_initialization->deinitialize = minimum_deinitialize;
        r_initialization->minimum_initialization_level = GDEXTENSION_INITIALIZATION_SCENE;
        r_initialization->userdata = nullptr;

        return 1; // Return 1/true to tell Godot it successfully loaded
    }
}
