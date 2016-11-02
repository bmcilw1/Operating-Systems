// Brian McIlwain
// Killing everything.
// Write a program to loop from the maximum PID (defined in limits.h) down to 1 and send 
// a SIGKILL kill signal to all user processes. It should not kill itself (or its parent 
// process, the terminal) before it completes its task.

#include <limits.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

// http://stackoverflow.com/a/12844426/5187014
static inline pid_t get_max_pid_t()
{
    if (sizeof(pid_t) == sizeof(short)) return SHRT_MAX;
    if (sizeof(pid_t) == sizeof(int)) return INT_MAX;
    if (sizeof(pid_t) == sizeof(long)) return LONG_MAX;
#if defined(LLONG_MAX)  // C99
    if (sizeof(pid_t) == sizeof(long long)) return LLONG_MAX;
#endif
    pid_t probs;
    return probs;
}

int main() {
    pid_t max_pid = get_max_pid_t();
    pid_t pid = getpid();
    pid_t ppid = getppid();

    for( ; max_pid >= 0 ; max_pid--) {
        if (max_pid == pid || max_pid == ppid)
            break;

        //printf("killing pid: %d\n", max_pid);
        kill(max_pid, SIGKILL);
    }

    return 0;
}
