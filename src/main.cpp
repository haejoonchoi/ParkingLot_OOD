#include "ParkingLot.h"
#include "Simulator.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

int main()
{
    auto logger = spdlog::stdout_color_mt("console");
    // Set the logger level to debug
    logger->set_level(spdlog::level::debug);

    logger->info("main() called");
    Simulator* simulator;
    simulator->run();
    return 0;
}