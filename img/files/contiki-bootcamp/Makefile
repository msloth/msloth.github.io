
#Makefile for the COOJA/MSPSim demos.
#Also available at http://pastebin.com/vP3EeAJj

ifndef CONTIKI
CONTIKI = ../../
endif
ifndef TARGET
TARGET=sky
endif

TARGET_LIBFILES += -lm

all: broadcaster silent

APPS=serial-shell

include $(CONTIKI)/Makefile.include

%.U:	%.upload
	@
	
