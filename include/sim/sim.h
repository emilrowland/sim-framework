// Copyright 2021 Emil Rowland.
// SPDX-License-Identifier: GPL-3.0-only

#include <string>

class Sim {
    public:
        Sim(std::string simName);
        std::string getSimName();
    private:
        std::string simName;
};