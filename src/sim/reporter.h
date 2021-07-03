// Copyright 2021 Emil Rowland.
// SPDX-License-Identifier: GPL-3.0-only

#pragma once

#include <string>

class Reporter {
    public:
        Reporter(std::string simName);  
    private:
        std::string simPath;
};