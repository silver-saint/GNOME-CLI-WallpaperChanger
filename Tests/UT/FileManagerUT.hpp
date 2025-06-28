#pragma once
#include <gtest/gtest.h>
#include "FileManager/FileManager.hpp"

TEST(FileManagerUT, CWD)
{
    FileManager fm(std::filesystem::current_path());
    ASSERT_TRUE(fm.CWD());
}

TEST(FileManagerUT, ChDir)
{
    FileManager fm(std::filesystem::current_path());
    ASSERT_TRUE(fm.ChDir(std::filesystem::current_path()));
}

TEST(FileManagerUT, GetCWD)
{
    std::string path = std::filesystem::current_path().string();
    FileManager fm(std::filesystem::current_path());
    EXPECT_EQ(fm.GetCWD(), path);
}

TEST(FileManagerUT, ls)
{
    FileManager fm(std::filesystem::current_path());
    EXPECT_NE(fm.ls(), 0);
}
