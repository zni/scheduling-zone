/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Driver for the scheduling simulator.
 *
 *        Version:  1.0
 *        Created:  09/05/2012 12:20:42 AM
 *       Revision:  none
 *       Compiler:  clang
 *
 *         Author:  mgodshall
 *
 * =====================================================================================
 */

#include <iostream>
#include "processtable.h"

int main(int argc, char **argv)
{
    ProcessTable ptable(500);
    // Scheduler sched;

    // std::cout << "running scheduler..." << std::endl;

    // sched.run(ptable);

    ptable.dump();
    std::cout << "done." << std::endl;

    return 0;
}
