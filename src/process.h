/*
 * =====================================================================================
 *
 *       Filename:  process.h
 *
 *    Description:  Process class header
 *
 *        Version:  1.0
 *        Created:  09/05/2012 01:36:38 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  mgodshall
 *
 * =====================================================================================
 */

#ifndef PROCESS_H
#define PROCESS_H
class Process
{
    public:
        Process(const int &pid, const int &ptime);
        ~Process();

        int pid() const;
        char priority() const;
        int ptime() const;
        void run(const int &time);

        void setPriority(const char&);

    private:
        int m_pid;
        int m_ptime;
        char m_priority;
};
#endif

