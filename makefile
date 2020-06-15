all: rfp

rfp.o: rfp.c
	clang rfp.c -c -o rfp.o -O2 -fno-vectorize -fno-unroll-loops -fno-builtin -fpic
rfp: rfp.cpp rfp.o
	clang++ rfp.cpp rfp.o -o rfp -lbenchmark -O2

clean:
	rm -f rfp.o rfp
