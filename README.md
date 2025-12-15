# ![image](https://github.com/user-attachments/assets/128c8a61-2dcc-45a5-a972-6335c6c9a7fd) Linux BSP Case Folding Library (libcasefolding)
LIBCaseFolding is a simple Linux library designed to be preloaded with Valve Source 1 engine games, such as Half-Life 2 Deathmatch, Counter-Strike: Source, Team Fortress 2, and many others. It aims to resolve client-side compatibility issues with maps (BSP) that have case folding problems with custom content. The library addresses missing textures, models, and sounds caused by case sensitivity mismatches by extracting and syncing assets to the game folder, enabling them to be parsed correctly by the game.

Library:
- Compile from source (recommended)
  ```
  g++ libcasefolding.cpp -fPIC -shared -o libcasefolding.so
  ```
- Precompiled binary from releases

Installation:
- Copy `libcasefolding.so` to your desired game root folder, eg `~/.local/share/Steam/steamapps/common/Half-Life 2 Deathmatch/`
- Open your game <i>Properties...</i> and add `LD_PRELOAD=libcasefolding.so %command%` to your game <b>Launch Options</b>

Once done, open your game and all custom assets should now properly load without any other modification.<br/>
All credit for this library [here](https://github.com/ValveSoftware/Source-1-Games/issues/6868#issuecomment-3656676213)
