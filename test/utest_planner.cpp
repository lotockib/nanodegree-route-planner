// Some tests for learning purposes

#include <vector>
#include <fstream>
#include "gtest/gtest.h"
#include "../src/route_model.h"
#include "../src/route_planner.h"
#include "../src/file_ops.h"

TEST(PlannerTests, ConstTest) {
    EXPECT_EQ(1, 1) << "1 does not equal 1";
    EXPECT_EQ(1, 1) << "1 does not equal 1";
    EXPECT_EQ(1, 1) << "1 does not equal 1";
}

TEST(PlannerTests, TestConstructor) {
    std::vector<std::byte> osm_data;
    std::string osm_data_file = "../map.osm";
    auto data = ReadFile(osm_data_file);
    osm_data = std::move(*data);
    RouteModel model{osm_data};
    RoutePlanner planner{model, 10.0, 10.0, 90.0, 90.0};

    EXPECT_EQ(planner.GetDistance(), 0.0);

}

// TODO figure out const char ** usage here
// TEST(PlannerTests, ParsePath) {
//     const char *argp = "nullpath";
//     const char **argpp = &argp;
//     std::string path = ParseFilePath(0, argpp);
// }

// TODO cant figure out how to get expected osm data in here
// TEST(PlannerTests, ReadFile) {
//     std::string path = "../map.osm";
//     std::vector<std::byte> osm_data;
//     EXPECT_EQ(ReadOsmDataFile(path), osm_data);
// }