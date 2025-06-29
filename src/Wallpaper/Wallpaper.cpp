#include "Wallpaper.hpp"
#include <cstdlib>
#include <iostream>

Wallpaper::Wallpaper(const std::string& name) : m_Name(name) {}

bool Wallpaper::SetWallpaper(const std::string& wallpaperName, const std::string& path, BackgroundTheme theme)
{

    std::string key = (theme == BackgroundTheme::dark) ? "org.gnome.desktop.background picture-uri-dark"
                                                       : "org.gnome.desktop.background picture-uri";

    std::string result = "gsettings set " + key + " \"file://" + path + "/" + wallpaperName + "\"";

    int ret = std::system(result.c_str());
    if (ret != 0)
    {
        std::cerr << "Failed to set wallpaper, gsettings returned " << ret << "\n";
        return false;
    }
    return true;
}