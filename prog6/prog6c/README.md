Brian McIlwain
Solution for:

Buffer overflow attacks.
[32] I have included a source for meow, which accepts a string using the dated gets function which is susceptible to buffer overflow attacks because it does not constrain the size of its input. Ultimately, this opens up the opportunity for an attacker to overwrite the return address of the callee function's stack frame, causing control flow to jump wherever the user desires. The ideal location would be somewhere earlier or later in the attack string, so that the attacker's own code may be executed.

Use gdb, objdump, gcc and the program hex2raw to construct an exploit string which spawns a shell (use /bin/sh so you can tell the difference when the shell spawns) using the system function when it is entered to meow. Place the hex code into an exploit file called exploit.txt. If successful, your exploit string will give you a shell. You may find this resource interesting:

http://insecure.org/stf/smashstack.html
