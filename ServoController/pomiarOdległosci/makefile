all: program

program: main.o DistanceSensor.o
	arm-linux-gnueabi-g++ main.o DistanceSensor.o -lwiringPi 

main.o: main.cpp
	arm-linux-gnueabi-g++ -c main.cpp -lwiringPi

DistanceSensor.o: DistanceSensor.cpp
	arm-linux-gnueabi-g++ -c DistanceSensor.cpp -lwiringPi

clean:
	rm -rf *.o a.out