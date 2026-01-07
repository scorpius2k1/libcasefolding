# ![image](https://github.com/user-attachments/assets/128c8a61-2dcc-45a5-a972-6335c6c9a7fd) Linux BSP Case Folding Library (libcasefolding)

**LIBCaseFolding** is a simple Linux library designed to be preloaded with Valve Source 1 engine games, such as *Half-Life 2: Deathmatch*, *Counter-Strike: Source*, *Team Fortress 2*, and many others. It aims to resolve client-side compatibility issues with maps (BSP files) that suffer from case-folding problems with custom content. The library addresses missing textures, models, and sounds caused by case sensitivity mismatches by adjusting how asset paths inside those map files are read in real time, enabling them to be parsed correctly by the game engine.

## 📄 Library

* **Compile from source** (recommended):

  ```bash
  g++ libcasefolding.cpp -fPIC -shared -o libcasefolding.so
  ```
* Precompiled binary available in [releases](https://github.com/scorpius2k1/libcasefolding/releases)

## 🚀 Installation

1. Copy or link `libcasefolding.so` to your desired game root folder, e.g., `~/.local/share/Steam/steamapps/common/Half-Life 2 Deathmatch/`
2. Open your game *Properties...* and add `LD_PRELOAD=libcasefolding.so %command%` to the game’s *Launch Options*.

Once done, open your game, and all custom assets should now load correctly without any further modification.<br/>
All credit for this library can be found [here](https://github.com/ValveSoftware/Source-1-Games/issues/6868#issuecomment-3656676213).

---

### VAC / Anti-Cheat

This project uses `LD_PRELOAD` as a Steam launch option to load the `libcasefolding.so` library, which makes file paths case-insensitive at runtime, addressing the Linux-specific case-folding issue introduced in the 2024 anniversary update. It does not modify gameplay, networking, or any game files, and is more efficient than extraction-based approaches. From a VAC perspective, it should be safe to use, similar to other long-standing Steam Linux tools like MangoHUD or Gamescope. However, as with any workaround, please use it at your own risk.

For a zero-risk alternative, the extraction-based [linux-bsp-casefolding-workaround](https://github.com/scorpius2k1/linux-bsp-casefolding-workaround) is still available.
