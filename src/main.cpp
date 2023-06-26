#include <optional>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <io2d.h>
#include "route_model.h"
#include "render.h"
#include "route_planner.h"
#include "./file_ops.h"

using namespace std::experimental;

int main(int argc, const char **argv)
{
    // Read and process osm file
    auto osm_data_file = ParseFilePath(argc, argv);
    auto osm_data = ReadOsmDataFile(osm_data_file);

    // Initialize and get user inputs
    float start_x, start_y, end_x, end_y;
    start_x = GetUserCoord("start_x");
    start_y = GetUserCoord("start_y");
    end_x = GetUserCoord("end_x");
    end_y = GetUserCoord("end_y");

    // Build Model.
    RouteModel model{osm_data};

    // Create RoutePlanner object and perform A* search.
    RoutePlanner route_planner{model, start_x, start_y, end_x, end_y};
    route_planner.AStarSearch();

    std::cout << "Distance: " << route_planner.GetDistance() << " meters. \n";

    // Render results of search.
    Render render{model};

    auto display = io2d::output_surface{
        400,
        400,
        io2d::format::argb32,
        io2d::scaling::none,
        io2d::refresh_style::fixed,
        30};
    display.size_change_callback([](io2d::output_surface& surface){
        surface.dimensions(surface.display_dimensions());
    });
    display.draw_callback([&](io2d::output_surface& surface){
        render.Display(surface);
    });
    display.begin_show();
}
