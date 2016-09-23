
Schedulers
----------

 * A **long-term** scheduler


Context Switching
-----------------

 * If an interrupt occurs, the **context** of the process must be saved before handling the interrupt.

 * A **state save** is done when the process changes to waiting state, then a **state restore** when transiting from ready to executing.

 * This is called **context-switching**

 * Context switching is pure overhead.

Operations on a Process
=======================

Process Creation
----------------
 
 * Processes are organized in a tree. When a process creates another, the new process is represented as a child node of the process. Hence processes that create others are called 
   **parent processes** and the processes they create are called **child processes**.

 * Every process has a PID (process ID). Also stored in the PCB is the PPID (parent process ID). Sometimes a child may need to have the PPID to communicate with the parent.

 * When a parent creates a child, it might:

  + execute concurrently with the child, or

  + wait until child has finished.

 * When a user enters a command on the command interpreter , the interpreter forks, creating a child process to handle the command while the parent waits. This is why terminals 
   are unresponsive while long commands are executing. 

    + It is possible to fork a process in BaSH by appending the (&) to a command. In this case, the child process will run in the background while the parent accepts commands in
      the foreground

 * Insofar as memory is concerned, when a parent creates a child it must:

   + have a segment in memory which is a duplicate of the parent process, or
   
   + have a new program loaded into it (ex: via ``exit()``)

Process Termination
------------------

 * A parent may have the need to terminate the child:
   + If the child has exceeded allocated usage

   + if task assigned to the child is no longer needed

   + If the parent exists

 * The latter situation may lead to **cascading termination**; in some OS designs, children are not allowed to exist if the parents have terminated, so all process on the parent's
   subtree are terminated.

 * If a child process has exited, but its parent has not called ``wait()``, then the child is know as a **zombie** process, but only until the parent calls ``wait()``

 * If the parent exits and the OS design permits the child to stay alive, then the child process then becomes an **orphan**

 * ``init()`` regularly collects orphan processes by calling ``wait()``.

Interprocess Communication
==========================

 * IPC may be for several reasons:
   + information sharing among users

   + speed increases for parallel jobs

   + modularity of design

   + the convenience of time-sharing

 * Two main IPC mechanisms are **shared memory** and **message passing**.

 * There are also **sockets** and **pipes**

Shared-Memory Systems
--------------------
 * A producer process creates a message or some form of data or info which it writes to a shared memory object

 * A consumer process reads the data from the shared memory object.

 * Both the consumer and producer use a name on the memory segment which they each may use to refer to it.

 * Buffers can be unbounded or bounded (size limit).

 * In POSIX (portable OS interface) systems, shared memory can be opened using the ``shm_open`` syscall

Message-Passing systems
-----------------------
 * Message passing involves sending info to a receiver. Refers to the logical implementation. Physically it may be enabled via shared memory, hardware buss, or network


Naming
~~~~~~
 * Typically ``send`` and ``recv`` primitives are defined for messages. May use direct comm by referring to other processes by names. P may send a message to Q, for ex (symmetric:
   both processes must know each others' names).

 * Message-passing can be asymmetric, so that a process is allowed to receive messages from any other process

 * Indirect comm is possible by sending messages to ``mailboxes`` or ``ports`` which reside in memory. Owners receive messages, users send

 * Suppose P1 sends message to mailbox M, then P2 and P3 call a ``recv`` from M. Which one receives? 
   + Could allow only one link at a time

   + could allow only one ``recv`` call at a time

   + could handle the message using an algorithm, such as **round robin**

 * Mailboxes can be owned by processes or OS. The OS has the responsibility of enabling processes to create/delete mailboxes and send/receive messages through them.

Synchronization
~~~~~~~~~~~~~~
 * Message passing can be **blocking** or **non-blocking**, aka synchronous or asynchronous. Blocking means process waits, nonblocking means process does not wait -- instead it
   resumes immediately following the operation.

 * If both send and recieve are blocking, there exists a **rendevous** between sender and receiver

Buffering
~~~~~~~~
 * Messages exchanged reside in a queue, which can be
   + 0 capacity. Means the sender must block

   + Bounded capacity. Queue has finite length. If the queue is full, sender must block

   + Unbounded capacity. Sender is never full


Client-Server Communication
===========================
 * A **socket** is a communication endpoint. Think of an electric socket as being the endpoint for and electrical connection.

 * Socket is identified by an IP and a port. Ports below 1024 are well-known

 * TCP (transmission control protocol) sockets are connection-oriented. A connection exists b/n client/server and info is sent via a stream. It is more complex and slower but more reliable
   
 * UDP (universal diagram protocol) sockets 


Remote Procedure Calls
---------------------

Pipes
-----
 * A **pipe** is a conduit allowing two processes to communicate
