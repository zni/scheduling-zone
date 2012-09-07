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
 *       Compiler:  g++
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
        Process(const int &pid, const int &ptime, const int &priority = 0);
        ~Process();

        int pid() const;
        int priority() const;
        int ptime() const;
        void run(const int &time);
        bool scheduled() const;

        void setPriority(const int &priority);

        friend bool operator> (Process &p, Process &q);
        friend bool operator<= (Process &p, Process &q);

        friend bool operator< (Process &p, Process &q);
        friend bool operator>= (Process &p, Process &q);

    private:
        int m_pid;
        int m_ptime;
        int m_priority;
        bool m_scheduled;
};
#endif

