all:redoAndUndo.o rotation.o projection.o poker.o
	gcc hw0601.c -o hw0601
	gcc hw0602.c redoAndUndo.o -o hw0602
	gcc hw0603.c rotation.o -o hw0603
	gcc hw0604.c projection.o -o hw0604
	gcc hw0605.c poker.o -o hw0605
redoAndUndo:redoAndUndo.c
	gcc -c redoAndUndo.c -o redoAndUndo.o
	gcc -shared redoAndUndo.o -o libredoAndUndo.so
rotation:rotation.c
	gcc -c rotation.c -o rotation.o
	gcc -shared rotation.o -o librotation.so
projection:projection.c
	gcc -c projection.c -o projection.o
	gcc -shared projection.o -o libprojection.so
poker:poker.c
	gcc -c poker.c -o poker.o
	gcc -shared poker.o -o libpoker.so