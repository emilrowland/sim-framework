// Copyright 2021 Emil Rowland.
// SPDX-License-Identifier: GPL-3.0-only

#include <iostream>
#include <sim/sim.h>
#include <sim/agent.h>

class AgentStore : public Agent {
    public:
        explicit AgentStore(const std::string& agentName) : Agent(agentName) {
            this->money = 100;
            this->registerStateVariable(&this->money, "money", StateVariableTypes::Int);
        };

        void buy(int cost) {
            this->money += cost;
        }
    private:
        int money;
};

class AgentCustomer : public Agent {
    public:
        explicit AgentCustomer(const std::string& agentName, AgentStore* store) : Agent(agentName) {
            this->store = store;
            this->money = 100;
            this->registerStateVariable(&this->money, "money", StateVariableTypes::Int);
        };

        void tick() {
            if(this->money >= 10){
                this->store->buy(10);
                this->money -= 10;
            }
        }
    private:
        int money;
        AgentStore* store;
};

int main() {
    Sim* simInstance = new Sim("Store simulator");
    simInstance->setStopTime(5);

    //Seting up agents
    AgentStore* store = new AgentStore("store");
    simInstance->registerAgent(store);
    AgentCustomer* customer1 = new AgentCustomer("customer1", store);
    simInstance->registerAgent(customer1);
    AgentCustomer* customer2 = new AgentCustomer("customer2", store);
    simInstance->registerAgent(customer2);

    simInstance->run();
}