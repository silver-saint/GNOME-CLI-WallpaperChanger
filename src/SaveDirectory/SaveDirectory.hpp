#pragma once
#include <fstream>
#include <filesystem>

class SaveDirectory
{
public:
    SaveDirectory() = default;
    SaveDirectory(const std::string& fileName, const std::filesystem::path& path);
    SaveDirectory(const SaveDirectory& other) = delete;
    SaveDirectory(SaveDirectory&& other) = delete;
    SaveDirectory& operator=(const SaveDirectory& other) = delete;
    SaveDirectory& operator=(SaveDirectory&& other) = delete;

public:
    void WriteToFile(const std::string& data);

    std::string GetName() const { return m_FileName; }

    std::filesystem::path SaveDataPath() const { return m_FilePath / m_FileName; }

    bool FileExists(const std::filesystem::path& path) const { return std::filesystem::exists(path); };

private:
    std::string m_FileName;
    std::filesystem::path m_FilePath;
};