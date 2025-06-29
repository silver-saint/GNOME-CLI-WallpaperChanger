#pragma once
#include <gtest/gtest.h>
#include "Wallpaper/Wallpaper.hpp"
#include "Settings/Settings.hpp"

TEST(WallpaperUT, GetWPName)
{
    Wallpaper wp("name");
    EXPECT_EQ(wp.GetWallpaperName(), "name");
}

TEST(WallpaperUT, SetWPName)
{
    Wallpaper wp("name");
    EXPECT_EQ(wp.SetWallpaper("name", std::filesystem::current_path(), BackgroundTheme::dark), true);
}