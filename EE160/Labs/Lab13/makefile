

swap: swap.o swaptest.o
	cc swap.o swaptest.o -o swap

swapbig: swapbigtest.o swapbig.o
	cc swapbigtest.o swapbig.o -o swapbig

reorder: reordertest.o reorder.o swapbig.o
	cc reordertest.o reorder.o swapbig.o -o reorder

reodertest.o: swap.h

reorder.o: swapbig.o swap.h

swapbigtest.o: swap.h

swapbig.o: swap.h

swap.o: swap.h

swaptest.o: swap.h 

clean: 
	rm *.o

real_clean: clean
	rm roman

