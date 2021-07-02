// Copyright 2021 Emil Rowland.
// SPDX-License-Identifier: GPL-3.0-only

#include <iostream>
#include <sim/sim.h>

int main() {
    Sim* simInstance = new Sim("My Sim");
    simInstance->setStopTime(1);
    simInstance->run();
}