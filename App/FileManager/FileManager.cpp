#include "FileManager.hpp"
#include <iostream>

FileManager::FileManager(const std::filesystem::path& path) : m_Path(path)
{
    if (!std::filesystem::exists(m_Path) || !std::filesystem::is_directory(m_Path))
    {
        throw std::runtime_error("Invalid path: " + m_Path.string());
    }
}

void FileManager::ChDir(const std::filesystem::path& newPath) { m_Path = newPath; }

void FileManager::ls()
{
    for (const auto& entry: std::filesystem::directory_iterator(m_Path))
    {
        std::cout << entry.path().filename() << std::endl;
    }
}

std::string FileManager::GetFile()
{
    if (m_Files.size() <= 0)
    {
        for (const auto& entry: std::filesystem::directory_iterator(m_Path))
        {
            std::string file = entry.path().filename().string();
            m_Files.push_back(file);
        }
    }
    std::cout << "Select a file" << std::endl;
    for (size_t i = 0; i < m_Files.size(); i++) { std::cout << i + 1 << ". " << m_Files[i] << std::endl; }
    int32_t input;
    std::cout << m_Files.size() + 1 << ". Exit" << std::endl;
    std::cin >> input;
    if (input == m_Files.size() + 1) { return ""; }
    std::cout << "Selected file: " << m_Files[input - 1] << std::endl;
    return m_Files[input - 1];
}

void FileManager::CWD() const { std::cout << m_Path.string() << std::endl; }