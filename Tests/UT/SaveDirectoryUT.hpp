#pragma once
#include <gtest/gtest.h>
#include "SaveDirectory/SaveDirectory.hpp"

TEST(SaveDirectoryUT, GetName)
{
    SaveDirectory sd("Name", std::filesystem::current_path());
    EXPECT_EQ(sd.GetName(), "Name");
}

TEST(SaveDirectoryUT, SaveDataPath)
{
    SaveDirectory sd("Name", std::filesystem::current_path());
    std::filesystem::path path = std::filesystem::current_path() / "Name";
    EXPECT_EQ(sd.SaveDataPath(), path);
}

TEST(SaveDirectoryUT, PathExists)
{
    SaveDirectory sd("Name", std::filesystem::current_path());
    EXPECT_EQ(sd.FileExists(std::filesystem::current_path()), true);
}