

bin/fft: src/main.c obj/r4_fft.o bin
	gcc src/main.c obj/r4_fft.o -o bin/fft -O3 -I include/ -lm -Wall
	
obj/r4_fft.o: src/r4_fft.c obj
	gcc src/r4_fft.c -o obj/r4_fft.o -O3 -c -I include/ -Wall

bin:
	mkdir bin

obj:
	mkdir obj

clean:
	rm -R obj
	rm -R bin
