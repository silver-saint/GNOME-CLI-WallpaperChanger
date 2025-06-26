#include <iostream>
#include "Wallpaper/Wallpaper.hpp"
#include "FileManager/FileManager.hpp"
#include "Settings/Settings.hpp"
#include <cstdlib> 
#include <string>
#include <optional>

std::optional<std::string> GetSystemPath(const std::string& path)
{
       const char* val = std::getenv(path.c_str());
    if (val == nullptr) {
        return std::nullopt;
    }
    return std::string(val);
}
int main()
{
    
    auto path = GetSystemPath("HOME");
    if(path.has_value())
    {
    std::string wpPath;
    std::cout << "Enter your specificed Wallpaper path\n";
    std::cin >> wpPath;
    FileManager manager(path.value());
    manager.ChDir(wpPath);
    Wallpaper wallpaper (manager.GetFile());
    int32_t num;
    std::cout << "Which Gnome Theme would you like to set?\n1. Dark\n2. Standard" << std::endl;
    std::cin >> num;
    if(num == 1)
    {
    wallpaper.SetWallpaper(wallpaper.GetWallpaperName(), manager.GetCWD(), BackgroundTheme::dark);
    }
    else 
    {
        wallpaper.SetWallpaper(wallpaper.GetWallpaperName(), manager.GetCWD(),BackgroundTheme::standard);
    }

    }
    else
    {
        return -1;
    }
    return 0;
}
