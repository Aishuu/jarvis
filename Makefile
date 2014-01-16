all:
	nbc -d -EF -D=DEBUG -D=SCAN_COMPASS main.nxc

.PHONY: calib wait

calib:
	nbc -d -EF -D=CALIB -O=calib main.nxc

wait:
	nbc -d -EF -D=DEBUG -D=WAIT_STATE main.nxc
