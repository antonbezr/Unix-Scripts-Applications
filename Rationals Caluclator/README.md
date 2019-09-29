# Rationals Calculator

This calculator program is a simple line-oriented calculator for expressions involving rational numbers. This calculator is implemented in C++ and executed in Unix.

In order to use the calculator run ```make``` and then execute the program. You can now use the input on the console to enter in expressions which will then be computed and the result returned to the console output. 

---

How the calculator works:

Rationals can be entered as either a positive integer ```n```, meaning ```n/1```, or as a pair of positive integers separated by a slash: ```n/d```. Numbers can be combined in expressions in the usual way with the operators ```+```,``` -```, ```*```, and ```%``` (for divide - the ```/``` isn't used to indicate division of two rationals since it is used to enter a single rational value). Spaces may separate parts of expressions, and subexpressions can be surrounded by parentheses.

One limitation is that the calculator only implements binary operators; in particular it doesn't support unary minus. To compute ```-r```, you can evaluate ```0-r```.

All expressions must be entered on a single line, and the calculator evaluates the expression on each input line and prints the result. The end of input is indicated by typing the usual end-of-file character.

The calculator makes no effort to detect or report errors such as illegal input, additional characters on the input line following a complete expression, or rationals with a denominator of ```0```. If it is unable to make sense out of something, it usually generates the result ```0/0``` and goes on to process the next input line.
