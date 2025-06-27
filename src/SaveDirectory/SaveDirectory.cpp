#include "SaveDirectory.hpp"
#include <print>

SaveDirectory::SaveDirectory(const std::string& fileName, const std::filesystem::path& path)
    : m_FileName(fileName), m_FilePath(path)
{

    if (!std::filesystem::exists(m_FilePath)) { std::filesystem::create_directories(m_FilePath); }
}

void SaveDirectory::WriteToFile(const std::string& data)
{
    std::ofstream savePath(m_FilePath / m_FileName, std::ios::app);
    if (!savePath)
    {
        std::println("Failed to open this file for writing");
        return;
    }
    savePath << data << std::endl;
    savePath.close();
}
