// Copyright 2021 Emil Rowland.
// SPDX-License-Identifier: GPL-3.0-only

#include <string>

class Sim {
    public:
        Sim(std::string simName);

        void run();

        void setStopTime(int stopTime) {
            this->stopTime = stopTime;
        };

        std::string getSimName();
    private:
        std::string simName;
        int stopTime;
        int currentTime;
};