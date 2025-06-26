#pragma once
#include <string>
#include "../Settings/Settings.hpp"

class Wallpaper
{
  public:
  Wallpaper() = default;
  Wallpaper(const Wallpaper& other) = delete;
  Wallpaper(Wallpaper&& other) = delete;
  Wallpaper& operator=(const Wallpaper& other) = delete;
  Wallpaper& operator=(Wallpaper&& other) = delete;
  Wallpaper(const std::string& name);
  public:
  void SetWallpaper(const std::string& wallpaperName, const std::string& path, BackgroundTheme theme);
  std::string GetWallpaperName() const {return m_Name;}
  private:
  std::string m_Name;
};
