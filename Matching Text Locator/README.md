# Matching Text Locator

This matching text locator is implemented in C a Unix utility program.
The following command should read the listed files (```FILE...```) and copy each line from the input to the output if it contains ```STRING``` anywhere in the input line. The argument ```STRING``` may be any sequence of characters.

```
$ ./gasp [options] STRING FILE...
```

The command and output from a hypothetical pair of files would look like this:

```
 $ ./gasp aardvark file1.txt file2.txt
 file1.txt:and the next day the aardvark ate a
 file1.txt:    The aardvark had a great day after that,
 file2.txt:not the most peaceful, but aardvarks
 ```
 There are two available options for this command, which may appear in any order if both are present:

```-i``` Ignore case when searching for lines that contain STRING. If the -i option is used, the strings "this", "This", "THIS", and "thiS" all match; if -i is not used, they are all considered different.

```-n``` Number lines in output. Each line copied to stdout should include the line number in the file where it was found in addition to the file name. The lines in each file are numbered from 1.
