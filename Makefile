
all:
	(cd cmd && make)
	(cd patricia-thompson-hw01 && make)
	(cd plugins/car_control && make)

clean:
	(cd cmd && make clean)
	(cd patricia-thompson-hw01 && make clean)
	(cd plugins/car_control && make clean)

.PHONY: all clean
