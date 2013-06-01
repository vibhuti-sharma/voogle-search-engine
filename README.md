Voogle - A simple search utility made in C
==========================================

A simple search utility tool made in C language. It uses simple regular expressions to search words in a file or directory.

Screen shots
------------
![voogle](http://s18.postimg.org/qrk3827wp/voogle.png "voogle")
![voogle](http://s21.postimg.org/h9oxa1xvr/voogle2.png "voogle")


How To Compile and Run
----------------------
Open search.c in any C compiler [Preferrable Code Blocks] and build and execute.


How It Works
-------------
 Accepts "FILE" or "FOLDERNAME" and a word to be searched for.
* In case of file, it finds the word in the given file using special regular expression  ( * and ? ) search and displays the line of occurrence.
* In case of folder, it reads "each .txt file" and tries to find the given word using regular expression search.
* Also displays the total number of occurences of the word in each file.


FEATURES
---------

KEYWORD SEARCH
->case insensitivity-keyword search should be case insensitive
->wildcards ( * and ? )

stemming-an aterisk at the end of the keyword 
matches all endings of the word

? in the word matches a single character

a complete word can be searched (example : hello).
multiple words can also be searched for.(example: he wrote)

->displays the total number of occurences of the word in each file.


->the results of the search are displayed in red colour.
rest of the file contents are displayed in blue.



Licence
-------

	Copyright 2013 Vibhuti Sharma

	Permission is hereby granted, free of charge, to any person obtaining
	a copy of this software and associated documentation files (the
	"Software"), to deal in the Software without restriction, including
	without limitation the rights to use, copy, modify, merge, publish,
	distribute, sublicense, and/or sell copies of the Software, and to
	permit persons to whom the Software is furnished to do so, subject to
	the following conditions:

	The above copyright notice and this permission notice shall be
	included in all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
	EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
	MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
	NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
	LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
	OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
	WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.