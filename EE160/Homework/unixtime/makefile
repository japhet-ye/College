# a makefile for compiling the date difference project and its test drivers


# target for making all executables
all: driver1 driver2 driver3 epochtime

# target for driver1
driver1: driver1.o leap.o
	cc  driver1.o leap.o -o driver1

# target for driver2
driver2: driver2.o leap.o julian.o
	cc  driver2.o leap.o julian.o -o driver2

# target for driver3
driver3: driver3.o leap.o epoch.o julian.o
	cc  driver3.o leap.o epoch.o julian.o -o driver3

# target for epochtime
epochtime: epochtime.o leap.o epoch.o julian.o
	cc  epochtime.o leap.o epoch.o julian.o -o datediff

# header dependency targets
driver1.o: leap.h

driver2.o: leap.h julian.h

driver3.o: leap.h epoch.h julian.h

epochtime.o: leap.h epoch.h julian.h

leap.o: leap.h

epoch.o: epoch.h julian.h 

julian.o: julian.h leap.h


# utility targets

clean:
	rm -f *.o

real_clean: clean
	rm -f driver1 driver2 driver3 epochtime a.out core

