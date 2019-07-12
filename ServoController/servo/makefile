all: program

main.o: main.cpp
	arm-linux-gnueabi-g++ -c main.cpp -lwiringPi

Servo.o: Servo.cpp
	arm-linux-gnueabi-g++ -c Servo.cpp -lwiringPi

program: main.o Servo.o
	arm-linux-gnueabi-g++ main.o Servo.o -lwiringPi

clean:
	rm -rf *.o a.out


send:
	sshpass -p "raspberry" scp -r a.out pi@raspberrypi.local:/home/pi/Desktop
