all:
	gcc hw0401.c roman.o -o hw0401
	gcc hw0402-1.c hanoi-1.o -o hw0402-1
	gcc hw0402-2.c hanoi-2.o -o hw0402-2
	gcc hw0403.c taylor.o -o hw0403
	gcc hw0404.c resistance.o -o hw0404
	gcc hw0405.c bullsAndCows.o -o hw0405
roman:roman.c
		gcc -c roman.c -o roman.o
		gcc -shared roman.o -o libroman.so
hanoi-1:hanoi-1.c
		gcc -c hanoi-1.c -o hanoi-1.o
		gcc -shared hanoi-1.o -o libhanoi-1.so
hanoi-2:hanoi-2.c
		gcc -c hanoi-2.c -o hanoi-2.o
		gcc -shared hanoi-2.o -o libhanoi-2.so
taylor:taylor.c
		gcc -c taylor.c -o taylor.o
		gcc -shared taylor.o -o libtaylor.so
resistance:resistance.c
		gcc -c resistance.c -o resistance.o
		gcc -shared resistance.o -o libresistance.so
bullsAndCows:bullsAndCows.c
		gcc -c bullsAndCows.c -o bullsAndCows.o
		gcc -shared bullsAndCows.o -o libbullsAndCows.so
