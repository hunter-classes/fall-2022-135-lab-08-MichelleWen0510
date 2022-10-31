main: main.o funcs.o imageio.o
	g++ -o main main.o funcs.o imageio.o

funcs.o: funcs.cpp funcs.h imageio.h

main.o: main.cpp funcs.h

sample: sample.o imageio.o
	g++ -o sample sample.o imageio.o

sample.o: sample.cpp imageio.h

imageio.o: imageio.cpp imageio.h


clean:
	rm -f sample.o imageio.o
	rm -f main.o funcs.o
