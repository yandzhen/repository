# Overlay Starter (Geode)

A starter Geode mod that displays a small progress HUD in the top-right corner during gameplay.

## Compatibility
This project targets Geometry Dash Windows `2.2081`. The `geode` value in `mod.json` must
match the exact Geode SDK version installed on your computer. The included `v4.0.0` value is
a starting point; change it if your installed SDK reports a different version.

This is source code, not a verified compiled `.geode` release. I cannot honestly guarantee
compilation without building against your local Geode SDK and dependencies.

## Build on Windows
1. Install Geode for Geometry Dash 2.2081 from the official Geode site.
2. Install the Geode CLI and SDK using the official setup instructions.
3. Install Visual Studio 2022 with **Desktop development with C++** and CMake tools.
4. Set `GEODE_SDK` to the folder containing the Geode SDK.
5. Open this folder in Visual Studio or configure it with CMake.
6. Select an `x64` `RelWithDebInfo` or `Release` configuration, not Debug.
7. Build the generated package target. The `.geode` file should be in the build output/package directory.
8. Install it through Geode or copy it to the Geode mods folder, then launch Geometry Dash.

If the build fails, share the first compiler error and your `geode --version` output so the
code can be adjusted to your installed SDK.

## Official documentation
- IDE setup: https://docs.geode-sdk.org/getting-started/ide-setup/
- `mod.json` configuration: https://docs.geode-sdk.org/mods/configuring/
- Modding tutorials: https://docs.geode-sdk.org/tutorials/
