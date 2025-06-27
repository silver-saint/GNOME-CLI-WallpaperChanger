#include <iostream>
#include "Wallpaper/Wallpaper.hpp"
#include "FileManager/FileManager.hpp"
#include "Settings/Settings.hpp"
#include "SaveDirectory/SaveDirectory.hpp"
#include <cstdlib>
#include <string>
#include <optional>
#include <print>

std::optional<std::string> GetSystemPath(const std::string& path)
{
    const char* val = std::getenv(path.c_str());
    if (val == nullptr) { return std::nullopt; }
    return std::string(val);
}

int main()
{
    auto path = GetSystemPath("HOME");
    std::string SaveFileName = "WallPaperDirectory.txt";
    std::filesystem::path saveData = path.value() + "/GnomeWallpaperChanger";
    std::filesystem::path existingSave = saveData / SaveFileName;
    SaveDirectory savePath(SaveFileName, saveData);
    bool hasExited = false;
    if (path.has_value())
    {
        FileManager manager(path.value());
        while (!hasExited)
        {
            if (savePath.FileExists(existingSave))
            {
                std::ifstream saveDataContents(savePath.SaveDataPath());
                if (!saveDataContents)
                {
                    std::println("File not found: {}", savePath.SaveDataPath());
                    return 1;
                }
                std::string contents;
                std::getline(saveDataContents, contents);
                manager.ChDir(contents);
                Wallpaper wallpaper(manager.GetFile());
                if (wallpaper.GetWallpaperName() == "")
                {
                    std::cout << "Exiting!" << std::endl;
                    hasExited = true;
                    continue;
                }
                int32_t num;
                std::cout << "Which Gnome Theme would you like to set?\n1. Dark\n2. Standard\n3 .Go Back" << std::endl;
                std::cin >> num;
                switch (num)
                {
                    case 1: {
                        wallpaper.SetWallpaper(wallpaper.GetWallpaperName(), manager.GetCWD(), BackgroundTheme::dark);
                    }
                    break;
                    case 2: {
                        wallpaper.SetWallpaper(wallpaper.GetWallpaperName(), manager.GetCWD(),
                                               BackgroundTheme::standard);
                    }
                    break;
                    case 3: {
                        continue;
                    }
                    break;
                }
            }
            else
            {
                std::string wpPath;
                std::cout << "Enter your specificed Wallpaper path\n";
                std::cin >> wpPath;
                savePath.WriteToFile(wpPath);
            }
        }
    }
    else { return -1; }
    return 0;
}
