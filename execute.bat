rm *.o
rm all.exe
cls

gcc -c node.c
gcc -c queue.c
gcc -c tree.c
gcc -c main.c
gcc -o all main.o tree.o queue.o node.o
