#pragma once
#include <filesystem>
#include <vector>

class FileManager
{
public:
    FileManager() = default;
    FileManager(const std::filesystem::path& path);
    FileManager(const FileManager& other) = delete;
    FileManager(FileManager&& other) = delete;
    FileManager& operator=(const FileManager& other) = delete;
    FileManager& operator=(FileManager&& other) = delete;

public:
    bool CWD();

    std::string GetCWD() const { return m_Path.string(); }

public:
    bool ChDir(const std::filesystem::path& newPath);
    bool ls();
    std::string GetFile();

private:
    std::filesystem::path m_Path;
    std::vector<std::string> m_Files;
};
