// Copyright 2021 Emil Rowland.
// SPDX-License-Identifier: GPL-3.0-only

#include "reporter.h"

#include <filesystem>

Reporter::Reporter(std::string simName) {
    this->simPath = "res/" + simName + "/";

    // Create new empty folder for the simulation
    std::filesystem::remove_all(this->simPath);
    std::filesystem::create_directories(this->simPath);
}