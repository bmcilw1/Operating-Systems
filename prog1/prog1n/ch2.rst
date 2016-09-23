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

 * You may have seen some sys programs you recongnize in the form of ...

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

OS Designs and Implementation
==========================

Design Goals
-------------

 * Relates back to perspectives on OS: user and system

 * The user goals are concerned with user-end desires: speed, ease-of-use, safety.

 * The sys goals are concerned with the people who write OS. It should be easy to maintain, efficient, etc.

Mechanisms and Policies
--------------------
 * ``policy``: what to do

 * ``mechanism``: how to do it

 * *If the temp rises above threshold, moderate the temp* is a policy; but *slow the clock speed to minimum* and 
   *shutdown the machiene* are  mechanisms separate from the policy.

 * We desire separation policy an mechanism for flexibility in the operations of the sys as standards evolve and hardware changes

Implementation
-------------

 * Early OS were written in assembly.

 * Now written in higher-level languages such as C or C++

 * All kernels of major OS are written in C

 * OS courses are normally taught in C for that reason

OS System Structure
===================

Structures
~~~~~~~~~~

 * monolithic

 * layered

 * microkernel

Monolithic
----------
 * In a monolithic kernel, all functionality is built into a single entity

 * MS-DOS and early UNIX were monolithic because of limited hardware

 * Monolithic kernels are difficult to maintain; they are inflexible because changes in hardware require changes in kernel code.

Layered Approach
----------------

 * In a layered approach, the functionality is built upon layers, The higher layers call lower layers, etc

 * Layered approach can be hard to develop; requires strategy.

 * EX: swap vs. CPU scheduling. Which one should go first?

Microkernels
------------
 * A microkernel supports mainly IPC, and minimal memory and process management. All extensions are developed in user space.

 * Advantages include a smaller, more portable, and more secure kernel, since it is small.

 * The message-passing IPC framework can introduce unwanted overhead. Windows NT had a microkernel that suffered performance-wise due to
   sys-function overhead.

Modules
-------

 * Some kernels are modular. Linux, for example. Modules can be listed with ``lsmod``, inserted and removed with ``modprobe``. These modules are
   primarily for device drivers and filesystems.

 * Modular designs are a fusion of layered/microkernel approaches.

Hybrid Systems
-------------

 * Mac OS X is a layered system with Aqua GUI, Cocoa for Objective-C, and has a Mach microkernel and BSD (Berkeley Software Distribution) Unix kernel.

 * iOS uses a similar structure, but has media services built on top of its core services.

 * Android rests on a Linux kernel. Uses an android runtime environment with core libraries and Dalvik VM; also SQLite, openGL, libc etc. libraries.

OS Debugging
============

 * Kernel supports printing of various messages; in Linux these are accessed via the `dmesg`` command.

 * Kernels also dump info to terminal if nessiscary (core dump)

OS Generation
============
 * Refers to generation of an OS at a particular hardware site. OS generation is part of installation process.

 * An experienced user can modify the kernel sources for an OS (using ``makeconfig``), then compile a kernel for that particular hardware.

 * An automated program can detect devices and select appropriate drivers for the system, however such programs tend to err on the side of caution and may end up producing a OS which is too general for hardware.

 * Or, all the code may be loaded all the time, and tables may be constructed to describe the system

OS Boot
======

 * Power button triggers exe of the bootstrap prog in firmware (which is some form of ROM, EPROM or EEPROM). Note that the bootstrap prob actually exe in firmware, which in general 
   tends to be slower than RAM

 * The bootstrap prog looks in secondary storage ROM for a bootloader, which is a prog to select and load the OS. The bootloader, which is a prog to select the OS. Typically stored in the MBR (Master Book Record); or else on the first partition of the storage device

 * The bootloader may untar/unzip the kernel if compressed and copy it memory. Once copied, the instruction pointer (IP) is set to the first ...


Process Concept
===============

 * A ``process`` is a prog in execution

 * A prog is a passive entity, but processes are active.

 * The term ``job`` usually refers to a task run in batch system.
