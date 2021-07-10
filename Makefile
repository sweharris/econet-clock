ifndef PORT
PORT=/dev/ttyUSB0
endif
BOARD=arduino:avr:nano
CPU=:cpu=atmega328old

SRC = $(wildcard *.ino)
PROJECT = $(notdir $(CURDIR))

TARGET = $(PROJECT).ino.bin

$(TARGET): $(SRC)
	@rm -rf tmp
	@mkdir -p tmp
	@TMPDIR=$(PWD)/tmp arduino-cli compile --fqbn=$(BOARD)$(CPU) --output-dir=$(PWD)
	@rm -rf tmp

recompile: $(TARGET)

upload:
	@mkdir -p tmp
	@TMPDIR=$(PWD)/tmp arduino-cli upload --fqbn=$(BOARD)$(CPU) -p $(PORT) --input-dir=$(PWD)
	@rm -rf tmp

serial:
	@kermit -l $(PORT) -b 115200 -c

clean:
	rm -rf *.elf tmp *.bin *.hex
