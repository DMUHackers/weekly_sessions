# Malware Analysis Task

Boot into Windows to complete these tasks. Some tasks can be completed on Linux (Kali, or the DMU Hackers VM). Some additional tools may need to be downloaded.

You can keep track of your answers in a text file. Solutions will be posted after the session.

## Task 1

Download the malware sample `dmuhackersware.exe`. First, we should take an overview of the file. **You should never run a file without first understanding what it does.**

1. What is the file type?
2. What is the file size?
3. When was the file created?
4. What is the MD5 hash of the file?
<br><br>
## Task 2

We need to have a deeper look at the file to understand what it does. Use a tool to extract further information from it.

<details>
<summary>Hint (tools)</summary>
For question 2, you might need to use 'strings' on Kali, Linux, or the DMU Hackers VM or 
<a href="https://learn.microsoft.com/en-us/sysinternals/downloads/strings">strings from sysinternals</a> on Windows.
<br><br>
For question 4 you may need to download a malware analysis tool like <a href="https://www.winitor.com/download2">PEStudio</a>.
<br>
</details>
<br>

1. Check the strings in the file. What do you notice?
2. What DLLs does the file contain?
3. What are your first thoughts on these DLLs?
4. Which of these DLLs does the program actually use?
5. How does this change your views from question 2?
<br><br>
## Task 3

From the strings and DLLs you have found, you should have a very basic understanding of what the malware does. Normally, in malware analysis, you would complete a more in-depth static analysis, but for this task, we'll stop here.

1. From the limited information you have, do you think it's safe to run the file?

Run the file.

2. What happens?
3. What is the flag?
<br><br>
## Task 4

Now its time to complete some further dynamic analysis to understand what the malware does.

<details>
<summary>Hint (tools)</summary>
A common tool to view child processes that executables spawn is <a href="https://processhacker.sourceforge.io/downloads.php">process hacker</a> on Windows.
<br>
</details>
<br>

1. What 2 processes does the executable create?
2. Do you think these processes are normal?
<br><br>
## Challenge

<details>
<summary>Challenge</summary>
<br>
The file is actually a basic Python script, not intended to cause any damage to the system.
<br><br>
By observing what the executable does, and using any reverse engineering techniques, can you recreate the Python script?
<br>
</details>
<br>
