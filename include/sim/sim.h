// Copyright 2021 Emil Rowland.
// SPDX-License-Identifier: GPL-3.0-only

#pragma once

#include <string>
#include <vector>
#include "sim/agent.h"

class Sim {
    public:
        Sim(std::string simName);

        void run();

        void setStopTime(int stopTime) {
            this->stopTime = stopTime;
        };

        void registerAgent(Agent* agent) {
            this->agents.push_back(agent);
        };
    private:
        std::string simName;
        int stopTime;
        int currentTime;
        std::vector<Agent*> agents;

        void outputState();
};