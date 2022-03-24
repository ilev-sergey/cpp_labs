#define _CRT_SECURE_NO_WARNINGS

#include <filesystem>
#include <iostream>
#include <iomanip>
#include <chrono>

int main()
{
    const auto path = std::filesystem::current_path();

    if (!std::filesystem::exists(path))
    {
        std::cerr << "Path " << path << " does not exist.\n";
        return EXIT_FAILURE;
    }
    std::cout << "Current path:\n" << std::filesystem::canonical(path).string() << "\n\n";

    for (const auto& entry : std::filesystem::directory_iterator(path))
    {
        auto get_time = [](auto path)
        {
            auto ftime	 = std::filesystem::last_write_time(path);
            auto utctime = std::chrono::file_clock::to_utc(ftime);
            auto stime   = std::chrono::utc_clock::to_sys(utctime);
            auto cftime  = std::chrono::system_clock::to_time_t(stime);
            return std::asctime(std::localtime(&cftime));
        };

        auto file_name		= entry.path().filename().string();
        auto file_extension = entry.path().extension().string();
        auto file_time		= get_time(entry);

        std::cout << std::left << std::setw(25) << file_name << " | " <<
            std::setw(10) << file_extension << " | " << file_time;
    }

    return EXIT_SUCCESS;
}