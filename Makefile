ROOTDIR     := $(shell pwd)

all: Makefiles
	$(MAKE) -C build

Makefiles: build
	$(QMAKE) -o $(ROOTDIR)/build/Makefile bbmocks.pro

build:
	mkdir -p $(ROOTDIR)/build
	
clean:
	rm -rf build
	
.PHONY: all Makefiles build clean

.IGNORE: clean