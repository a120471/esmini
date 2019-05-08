# Windows Build and Run Instructions

## Build configurations
The following platforms are supported:
- VisualStudio 2017 / win64 / Windows SDK v10 / Release and Debug (default/preferred)
- VisualStudio 2017 / win32 / Windows SDK v10 / Release and Debug
- VisualStudio 2017 / win64 / Windows SDK v7.1 / Release and Debug (no FBX support)

[CMake](https://cmake.org/) tool is used to create VisualStudio solutions. A few example "create..." batch scripts are supplied as examples how to generate desired build setup.

## External dependencies
CMake scripts will download a package of external binary dependencies (OSG) and 3D model resource files. If not using CMake, here are links to those external data packages:

- [OSG for WinSDK v10 x64](https://drive.google.com/uc?export=download&id=1a0HxilPJq2bZrat2le2x-Cscs5JeVAXP)
- [OSG for WinSDK v10 win32](https://drive.google.com/uc?export=download&id=14Xqe_bWGuZQAr69mit4melmnMfmNFOO6)
- [OSG for WinSDK 7.1 x64](https://drive.google.com/uc?export=download&id=1aN88B1_7MnT0OwHt_LOc8FtD7rFEP0Jq)  
Unpack into esmini/externals. Please note that these libraries are for Windows only. For other platforms OSG needs to be downloaded and built separately (set CMake flag DYNAMIC_OPENSCENEGRAPH = true).

- [3D models used by the example scenarios](https://drive.google.com/uc?export=download&id=1RSbyFJoVahX1nGWAsdepsPsznAiNspUc)  
Unpack into esmini/resources. These assets works on all platforms.

Environment models (roads, landscape, buildings...) have been created using [VIRES Road Network Editor](https://vires.com/vtd-vires-virtual-test-drive/#creation).

## Build project

1. First generate build configuration (see above)
1. Open generated solution, build/EnvironmentSimulator.sln
1. Select configuration, Debug (default) or Release
1. Build CMakePredefinedTargets/INSTALL (right-click and select build)

This will build all projects and copy the binaries into a dedicated folder found by the demo batch scripts.

## Run demo applications on Windows
- Navigate to the esmini/run folder
- There is a subfolder for each application including a few example batch-files
- Simply doubleclick on any to run
- Usage help, see [EnvironmentSimulator/ViewerBase/readme.txt](EnvironmentSimulator/ViewerBase/readme.txt)