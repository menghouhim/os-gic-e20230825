# OS lab N — individual report
Name or student ID: Him Menghou (e20230825)
Workspace and environment: Local Windows UCRT64 / Ubuntu Server (KVM)

## Original prediction (written before running)
Expected outcome and reason: I guessed [Write what you typed for the oslab predict lab1 step, or just write "I guessed that the sleep processes would run at the same time"].

## Investigation artifact
Link to script or paste at most ten decisive command lines. State the intended behaviour and one choice you made.
Command lines used:
uname -a
ps
sleep 300 & sleep 300 & sleep 300 &
sudo apt-get purge mc -y
systemd-detect-virt
Intended behaviour: To find the kernel version, observe multiple processes running simultaneously, and check if the server is a virtual machine. My choice was to run sleep in the background using & so I could see them all with ps.

| Case | Claim | Contradicting result | Observation | What remains unproven |
|---|---|---|---|---|
| Normal | `ps` will show three `sleep` processes. | None | 3 `sleep` processes appeared in the list. | Whether they are using CPU power (they are not). |
| Edge/failure | Purging `mc` removes the `/etc/mc` folder. | None | `ls -ld /etc/mc` showed "No such file or directory". | N/A |

## Correction and explanation
Keep the original prediction above. Explain what changed in your understanding and the OS mechanism in 3–5 sentences.
I learned that a program is just a static file on the hard drive (like the sleep file), but a process is an active instance of that program running in memory. When I ran the ps command, I saw the processes, not the file itself. I also learned that removing a package with apt-get remove leaves configuration files behind, but purge deletes everything. Finally, I discovered that the course server is actually a virtual machine running on KVM.

## AI suggestion (optional)
One useful suggestion and how you checked it:
I asked AI how to find my kernel version, and it suggested uname -a. I checked it by running the command, and it printed 7.0.0-38-generic.