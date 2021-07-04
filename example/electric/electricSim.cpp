// Copyright 2021 Emil Rowland.
// SPDX-License-Identifier: GPL-3.0-only

#include "electricSim.h"

#include <cmath>
#include <numbers>

#include <sim/sim.h>
#include <sim/agent.h>

// 1 tick = 1ms

class ElectricSimAgent : public Agent {
    public:
        explicit ElectricSimAgent() : Agent("Electric Sim Agent") {
            this->voltage = 0;
            this->registerStateVariable(&this->voltage, "voltage", StateVariableTypes::Float);
        };

        void tick(int currentTime) {
            //Generate sign wave of amplitud 5 V and frequency 50 Hz
            this->voltage = 5*sin(2*std::numbers::pi*50*currentTime/1000);
        }
    private:
        float voltage;
};

ElectricSimulation::ElectricSimulation() {
    Sim* simInstance = new Sim("Electric Sim");
    simInstance->setStopTime(20);
    simInstance->setSilentMode(false);

    //Seting up agents
    ElectricSimAgent* electricSimAgent = new ElectricSimAgent();
    simInstance->registerAgent(electricSimAgent);

    simInstance->run();
}