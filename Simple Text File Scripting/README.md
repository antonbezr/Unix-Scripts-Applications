# Simple Text File Scripting

---

```combine``` - This script takes 2 or more arguments, concatenates the contents, and prints them to the console output.

---

```currentlinecount``` - This script takes 2 or more arguements. The first arguement is the output file name and the remaining arguements are input files. This script counts the amount of lines in each of the input files and concatenates this information to the output file along with the current time and date.

For example, this series of commands:

```
./datedlinecount log foo bar
./datedlinecount log foo*
cat log
```

Would give this output:

```
Wed Apr 3 09:22:16 PDT 2019
18 foo
23 bar
41 total
Wed Apr 3 09:22:17 PDT 2019
18 foo
6 foot
24 total
```
