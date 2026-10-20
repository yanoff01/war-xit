#pragma once
#include <atomic>
#include <string>

struct AppState {
    std::atomic<bool> running{true};
    std::atomic<bool> menu_open{true};
    std::atomic<bool> esp_enabled{true};
    std::atomic<bool> aim_enabled{false};
    std::atomic<bool> panic{false};
    std::atomic<int>  backend_kind{0};
    std::atomic<int>  fov_pixels{120};
    std::atomic<float> smoothing{0.22f};
    std::atomic<int>  aim_key{0x02};
    std::atomic<bool> aim_key_held{false};
    std::string status_line = "idle";
    int frames_rendered = 0;
    int entities_seen = 0;
};

extern AppState g_app;
