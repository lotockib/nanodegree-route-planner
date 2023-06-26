#include <optional>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "./file_ops.h"

std::optional<std::vector<std::byte>> ReadFile(const std::string &path)
{
    std::ifstream is{path, std::ios::binary | std::ios::ate};
    if ( !is )
        return std::nullopt;

    auto size = is.tellg();
    std::vector<std::byte> contents(size);

    is.seekg(0);
    is.read((char*)contents.data(), size);

    if ( contents.empty() )
        return std::nullopt;
    return std::move(contents);
}

std::vector<std::byte> ReadOsmDataFile(std::string osm_data_file) {
    std::vector<std::byte> osm_data;
    if ( osm_data.empty() && !osm_data_file.empty() ) {
        std::cout
            << "Reading OpenStreetMap data from the following file: "
            <<  osm_data_file
            << std::endl;
        auto data = ReadFile(osm_data_file);
        if ( !data )
            std::cout << "Failed to read." << std::endl;
        else
            osm_data = std::move(*data);
    }
    return osm_data;
}

std::string ParseFilePath(int argc, const char **argv) {
    std::string osm_data_file = "";
    if ( argc > 1 ) {
        for ( int i = 1; i < argc; ++i )
            if ( std::string_view {argv[i]} == "-f" && ++i < argc )
                osm_data_file = argv[i];
    } else {
        std::cout
            << "To specify a map file use the following format: "
            << std::endl;
        std::cout << "Usage: [executable] [-f filename.osm]" << std::endl;
        osm_data_file = "../map.osm";
    }

    return osm_data_file;
}

float GetUserCoord(std::string coord_name) {
    float input;
    while (true) {
        std::cout << "Enter " << coord_name << ": ";
        std::cin >> input;
        auto check_bounds =
            [&]
            (float coord)
            {
                return (coord >= 0 && coord <= 100);
            };
        if ( check_bounds(input) )
            break;
        std::cout << "Error: coordinate must be between 0-100" << std::endl;
    }
    return input;
}