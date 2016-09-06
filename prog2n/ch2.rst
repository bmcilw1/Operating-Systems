...................
Ch 2: Operating System Structures
..................

What OS Structures is about
~~~~~~~~~~~~~~~~~~~~~~~~~

* *Operating system structures* refers to the anatomy of an operating system.
  What are the core parts and components that make everything work together?

==================
Operating System Services
===================
  
  * OS are understood in terms of their functional components

  * In order to understand how everything fits together, we look at the services provided by an OS

Helpful Functions
~~~~~~~~~~~~~~~

  * **user interface**
  * **program execution**
  * **filesystem manipulation**
  * **communications**
  * **error detection**

Efficiency functions
~~~~~~~~~~~~~~~~
    
  * **resource allocation** 
  * **accounting**
  * **protection and security**

=============
User and OS Interface
============

Interfaces
~~~~

 * An OS MUST have some interface in order to be able to be used

 * Some servers do not have hardware interfaces, however they still support software interfaces,
   however they still support software interfaces in the event that the interfaces are required.

GUI
~~~~

 * Xerox Alto first (1973)

 * MAC desktop first mult-panel windowing interface (1984)

 * *Windows* gets its name from the window-managing GUI for MS-DOS: it was first developed in 1985.

 * The *X* windowing system was developed for Unix in the mid-80s at MIT

 * Now phones have their own GUIs (2009)

 * In Linux terms, there is a *window manager* such as fluxbox, openbox, etc. which simply manages windows, a *desktop env* is a full
   graphical env with its own program suite , and a *windows system* like X.

 * Recently, a window system called *Wayland* was released as an alternative to X (2014)

Choice of Interface
---------

 * People who choose CLI may be sys admins, sys programmers, comp sci, power users. Reasons to choose CLI:

    + more control
    + scriptable
    + faster once learned

 * People who choose GUI tend to be casual users. Reasons to choose GUI:

    + more user-friendly
    + lower learning curve


System Calls
============

    * Provide an interface to services made available to the OS

    * An ex is ``read()``, which reads input from a file or device: or
      ``fork()`` which creates a new process.

    * Syscalls are accessed via an API such as ``libc``, the standard C lib

    * Low-level functions in C ofter have a one-to-one correspondence to a syscall

    * Section 2 of the Linux manual  contains detailed info

Types of syscalls
~~~~~~~

 * process control

 * file management

 * device management

 * info management

 * communication

 * protection

Process Control
~~~~~~

 * Responsible for creating, deleting, loading, and exe processes: or getting / setting proc info; or waiting, allocation / deallocation memory 
   (since memory is linked to processes)

 * ``fork()`` is an ex of a ``libc`` fun that creates a new process.

 * ``exit()`` triggers proc exit, mem deallocation, etc

 * ``wait()`` causes a process to finish executing

 * You may be familiar with ``malloc()`` for mem location; but in spite of being low-level, it is *not* a syscall. The call for inc heap size is 
   ``sbrk()``

 File Management
 --------------

  * For creating, deleting, reading, writing to files/dir; or getting or setting file/dir info.

  * ``open()`` creates a ``file descriptor``, ``write()`` writes bytes to a file descriptor 

  * ``mkdir()`` is a syscall

Device Management
-----

 * For creating, deleting, reading from, or writing to devices; or getting or setting device info.

 * ``ioctl()`` is caused for making req of file descriptors. ``ioctl(fd, CDROMEJECT), 0);`` can, for ex, request an eject of a CD-ROM.

 * On Linux, devices are treated like files. That fives them the adv of interfacing with the syscalls as files. Take ``read()``
   For ex, which can read from ``stdin`` as well as a file

 * Devices are even objects of the filesystem. Examine ``/dev`` for a look at device files.


Info Maintenance
-------------

 * Get/set info, Anything with timers. ``time()``, for ex; also ``alarm()`` and ``sleep()``.

    + Interesting fact: ``proc/timer_list`` has list of all timers on system

 * Others intersect with other services. ``stat()`` gets file stat, ``getpid()`` gets a process ID.


Communication
-----------
 
 * ``pipe()`` creates a pipe, a means of interprocess communication

 * ``socket()`` used for client/server model communication

 * ``shm_open()`` opens shared memory

 * ``map()`` maps files/devices into memory

Protection
-------

 * ``chmod()`` changes file permissions, ``chown()`` file ownership.

 * ``umask()`` sets file mode creation mask; basically causes any files created by the proc to assume certain permissions

System Programs
===========

 * System programs are implemented to handle the most important / freq syscalls, or to perform simple operations that require a few syscalls.

 * You may have seen some sys programs you recongnize in the form of 

Questions
========
 * What is a syscall? What is the purpose of a syscall? Give a couple of examples of ``libc`` syscall. Finally, five an example of a ``libc`` 
   lib function which is itself not a syscall, but invokes a syscall.

    + A syscall is a user-level access to a kernel level function/service. The purpose of a syscall is to provide an interface to systems/functions available to the OS. 

        - EX: printf() which invokes ``write()``

 * Why are memory management syscalls considered to be part of process control? What is the relationship b/n memory management and process control?

    + Memory management syscalls are considered to be part of process control because memory is (de)allocated by processes.
      
 * Why, in some OS architectures, are devices considered to be files? What is the advantage of treating a device as a file?

    + This is to allow many of the same syscalls to function on devices as well as on a file, i.e. you don't need to implement a special read() call for a device,
      since you already have one for a file.
