#include <optional>
#include <vector>
#include <string>

#ifndef FILEOPS_H
#define FILEOPS_H

float get_user_coord(std::string coord_name);
std::vector<std::byte> ReadOsmDataFile(std::string osm_data_file);
std::optional<std::vector<std::byte>> ReadFile(const std::string &path);
std::string ParseFilePath(int argc, const char **argv);
 
#endif