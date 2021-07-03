// Copyright 2021 Emil Rowland.
// SPDX-License-Identifier: GPL-3.0-only

#pragma once

#include <string>
#include <vector>

#include "sim/agent.h"

// Forward declaration
class Reporter;

class Sim {
    public:
        Sim(std::string simName);

        void run();

        void setStopTime(int stopTime) {
            this->stopTime = stopTime;
        };

        void registerAgent(Agent* agent) {
            agent->setSimInstance(this);
            this->agents.push_back(agent);
        };

        static const std::string parseStateVariable(StateVariable stateVariable);
    private:
        std::string simName;
        int stopTime;
        int currentTime;
        std::vector<Agent*> agents;
        Reporter* reporter;

        void outputState() const;
};