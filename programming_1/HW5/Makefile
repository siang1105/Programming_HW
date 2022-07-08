all:sorting.o determinant.o polynomial.o linear.o minesweeper.o
	gcc hw0501.c sorting.o -o hw0501
	gcc hw0502.c determinant.o -o hw0502
	gcc hw0503.c polynomial.o -o hw0503
	gcc hw0504.c linear.o -o hw0504
	gcc hw0505.c minesweeper.o -o hw0505
sorting:sorting.c
	gcc -c sorting.c -o sorting.o
	gcc -shared sorting.o -o libsorting.so
determinant:determinant.c
	gcc -c determinant.c -o determinant.o
	gcc -shared determinant.o -o libdeterminant.so
polynomial:polynomial.c
	gcc -c polynomial.c -o polynomial.o
	gcc -shared polynomial.o -o libpolynomial.so
linear:linear.c
	gcc -c linear.c -o linear.o
	gcc -shared linear.o -o liblinear.so
minesweeper:minesweeper.c
	gcc -c minesweeper.c -o minesweeper.o
	gcc -shared minesweeper.o -o libminesweeper.so
