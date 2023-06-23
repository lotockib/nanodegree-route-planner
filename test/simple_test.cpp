#include <vector>
#include <fstream>
#include "gtest/gtest.h"
#include "../src/route_model.h"
#include "../src/route_planner.h"

// copied from main.cpp
static std::optional<std::vector<std::byte>> ReadFile(const std::string &path)
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

TEST(SimpleTests, ConstTest) {
    EXPECT_EQ(1, 1) << "1 does not equal 1";
    EXPECT_EQ(1, 1) << "1 does not equal 1";
    EXPECT_EQ(1, 1) << "1 does not equal 1";
}

TEST(SimpleTests, TestConstructor) {
    std::vector<std::byte> osm_data;
    std::string osm_data_file = "../map.osm";
    auto data = ReadFile(osm_data_file);
    osm_data = std::move(*data);
    RouteModel model{osm_data};
    RoutePlanner planner{model, 10.0, 10.0, 90.0, 90.0};

    EXPECT_EQ(planner.GetDistance(), 0.0);
    // EXPECT_EQ(planner.

}