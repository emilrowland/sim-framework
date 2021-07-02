// Copyright 2021 Emil Rowland.
// SPDX-License-Identifier: GPL-3.0-only

#include <iostream>
#include <sim/sim.h>
#include <sim/agent.h>

class MyAgent : public Agent {
    public:
        explicit MyAgent(const std::string& agentName) : Agent(agentName) {
            this->money = 100;
            this->registerStateVariable(&this->money, "money", "int");
        };

        void tick() {
            std::cout << "Eating!" << std::endl;
            if(this->getAgentName() == "Adam"){
                this->money -= 10;
            }
        }
    private:
        int money;
};

int main() {
    Sim* simInstance = new Sim("My Sim");
    simInstance->setStopTime(1);

    //Seting up agents
    MyAgent* agentAdam = new MyAgent("Adam");
    simInstance->registerAgent(agentAdam);
    MyAgent* agentBob = new MyAgent("Bob");
    simInstance->registerAgent(agentBob);

    simInstance->run();
}