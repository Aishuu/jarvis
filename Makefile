all:
	nbc -d -EF -D=DEBUG main.nxc

.PHONY: calib

calib:
	nbc -d -EF -D=CALIB -O=calib main.nxc
