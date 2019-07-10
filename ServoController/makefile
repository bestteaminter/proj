all:program

program: main.o ServoController.o
	arm-linux-gnueabi-g++ main.o ServoController.o servo/Servo.o pomiarOdległosci/DistanceSensor.o -lwiringPi

ServoController.o: ServoController.cpp 
	arm-linux-gnueabi-g++ -c ServoController.cpp -lwiringPi

main.o: main.cpp 
	arm-linux-gnueabi-g++ -c main.cpp  -lwiringPi

clean:
	rm -rf *.o a.out




# all: program

# program: main.o ServoController.o Servo.o DistanceSensor.o
# 	arm-linux-gnueabi-g++ -c main.o ServoController.o Servo.o DistanceSensor.o -lwiringPi

# DistanceSensor.o: DistanceSensor.cpp
# 	arm-linux-gnueabi-g++ -c DistanceSensor.cpp -lwiringPi

# Servo.o: Servo.cpp
# 	arm-linux-gnueabi-g++ -c Servo.cpp -lwiringPi

# ServoController.o: ServoController.cpp 
# 	arm-linux-gnueabi-g++ -c ServoController.cpp -lwiringPi

# main.o: main.cpp 
# 	arm-linux-gnueabi-g++ -c main.cpp  -lwiringPi
