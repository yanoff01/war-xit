cmake_minimum_required(VERSION 3.20)
project(war_xit LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

set(IMGUI external/imgui)
set(IMGUI_SRC
    ${IMGUI}/imgui.cpp
    ${IMGUI}/imgui_draw.cpp
    ${IMGUI}/imgui_tables.cpp
    ${IMGUI}/imgui_widgets.cpp
    ${IMGUI}/backends/imgui_impl_win32.cpp
    ${IMGUI}/backends/imgui_impl_dx11.cpp
)

add_executable(war_xit WIN32
    src/main.cpp
    src/config.cpp
    src/overlay.cpp
    src/hotkeys.cpp
    src/mem/backend_mock.cpp
    src/mem/backend_dma.cpp
    src/mem/backend_drv.cpp
    src/mem/backend_factory.cpp
    src/game/reader.cpp
    src/game/demo_world.cpp
    src/esp/render.cpp
    src/aim/target.cpp
    src/aim/input.cpp
    src/ui/menu.cpp
    ${IMGUI_SRC}
)
target_include_directories(war_xit PRIVATE src external/imgui external/imgui/backends external/nlohmann)
target_compile_definitions(war_xit PRIVATE WIN32_LEAN_AND_MEAN NOMINMAX UNICODE _UNICODE)
target_link_libraries(war_xit PRIVATE d3d11 dxgi d3dcompiler dwmapi psapi)
if (MSVC)
    target_compile_options(war_xit PRIVATE /W3 /permissive- /EHsc /O2)
endif()

add_executable(find_offsets tools/find_offsets.cpp)
target_compile_definitions(find_offsets PRIVATE UNICODE _UNICODE)
if (MSVC)
    target_compile_options(find_offsets PRIVATE /MT /O2)
    target_link_libraries(find_offsets PRIVATE psapi)
endif()
