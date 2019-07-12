all: program

program: main.o PwmController.o
	arm-linux-gnueabi-g++ main.o PwmController.o -lwiringPi

main.o: main.cpp
	arm-linux-gnueabi-g++ -c main.cpp -lwiringPi

PwmController.o: PwmController.cpp
	arm-linux-gnueabi-g++ -c PwmController.cpp -lwiringPi

clean:
	rm -rf *.o *.out

send:
	sshpass -p "raspberry" scp -r a.out pi@raspberrypi.local:/home/pi/Desktop
