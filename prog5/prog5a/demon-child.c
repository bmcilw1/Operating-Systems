// Brian McIlwain
// Unstoppable processes.
// Write a program code for a process which spins indefinitely. If any signal intended to 
// stop it is sent to it, it should respond by forking itself, thus creating a daemon 
// child process which uses the same signal handlers. Therefore call this demon-child.c.
// The only signal the process cannot intercept is SIGKILL, which you can use to kill it. 
// Use killall -KILL demon-child to end it once and for all.

#include <signal.h>
#include <unistd.h>

/*
 * This is a handler function which catches the signal and decides
 * what to do with it.
 */
void end_handler(int signal) {
    fork();
}

int main() {
  /**
   * The signal() function ties a certain signal to a handler. This
   * particular call associates an alarm signal with the function
   * defined above.  The alarm() call indicates that a SIGALRM is
   * to be sent to the current executable in 3 seconds.  At that
   * point, the signal will be handled by the handler defined above.
   */
  signal(SIGINT, end_handler);
  signal(SIGQUIT, end_handler);
  signal(SIGABRT, end_handler);
  signal(SIGPIPE, end_handler);
  signal(SIGALRM, end_handler);
  signal(SIGTERM, end_handler);
  signal(SIGSTOP, end_handler);
  signal(SIGTSTP, end_handler);
  signal(SIGTTIN, end_handler);
  signal(SIGTTOU, end_handler);
  signal(SIGVTALRM, end_handler);
  signal(SIGPROF, end_handler);
  signal(SIGHUP, end_handler);
  
  while (1); 

  return 0;
}
