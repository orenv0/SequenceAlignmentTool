build:
	mpicc -fopenmp -c main.c -o main.o 
	mpicc -fopenmp -c cFunctions.c -o cFunctions.o 
	mpicc -fopenmp -o final cFunctions.o main.o 
clean:
	rm -f *.o ./final $
run:
	mpiexec -np 5 ./final $
runOn2:
	mpiexec -np 5 -machinefile mf -map-by node ./final 
