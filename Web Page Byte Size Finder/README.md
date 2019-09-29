# Web Page Byte Size Finder

This series of bash scripts allows a user to determine the size of website URLs in bytes as well as parse an exisiting website for clickable URL addresses.

---

In order to find out the byte size of one URL simply run the ```perform-measurement.sh``` script. This script takes a URL as an argument and outputs the size of the corresponding page in bytes.

Execute the script as follows:
```
$ ./perform-measurement.sh http://www.about.com/
```

This script will output the resulting URL byte size to the console like this:

```
47597
```

---

To find the byte size of multiple URLs you will need a text document containing a list of URLs (one on each line). The ```run-experiment.sh``` script will run through each line and calculate the size of each website using the ```perform-measurement.sh``` script.

Execute the script as follows:

```
$ ./run-experiment.sh output.txt URLs.txt
```

The output of the resulting document ```output.txt``` will look something like this:

```
http://www.about.com/ 47597
http://www.bartleby.com/ 254654
http://groups.google.com/ 22469
```

Each line in the output file will contain the URL and byte size.

---

An additional script ```parse.sh``` is included if the user would like to parse a HTML page to find all the clickable links on that page and export them to a text file.

Execute the script as follows:

```
$ ./parse.sh URLs.txt website.html
```

The output of the resulting document ```URLs.txt``` will look something like this:

```
http://www.about.com/
http://www.bartleby.com/
http://groups.google.com/
```
