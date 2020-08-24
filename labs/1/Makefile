TARGET = bin/l1
COMPILE = g++ -c -Iinclude 
LINK = g++
SRC = src/
BUILD = build/

.PHONY: all clean install uninstall

all: $(TARGET)

clean:
	rm -rf $(TARGET) $(BUILD)*.o

$(TARGET): $(BUILD)l1_UserInterface.o $(BUILD)l2_ApplicationLayer.o $(BUILD)l3_DomainLayer.o $(BUILD)l4_InfrastructureLayer.o
	$(LINK) -o $(TARGET) $(BUILD)l1_UserInterface.o $(BUILD)l2_ApplicationLayer.o $(BUILD)l3_DomainLayer.o $(BUILD)l4_InfrastructureLayer.o

$(BUILD)l1_UserInterface.o: src/l1_UserInterface.cpp include/hw/l2_ApplicationLayer.h include/hw/l3_DomainLayer.h include/hw/l4_InfrastructureLayer.h
	$(COMPILE) $(SRC)l1_UserInterface.cpp -o $(BUILD)l1_UserInterface.o

$(BUILD)l2_ApplicationLayer.o: src/l2_ApplicationLayer.cpp include/hw/l2_ApplicationLayer.h include/hw/l3_DomainLayer.h include/hw/l4_InfrastructureLayer.h
	$(COMPILE) $(SRC)l2_ApplicationLayer.cpp -o $(BUILD)l2_ApplicationLayer.o

$(BUILD)l3_DomainLayer.o: src/l3_DomainLayer.cpp include/hw/l3_DomainLayer.h include/hw/l4_InfrastructureLayer.h
	$(COMPILE) $(SRC)l3_DomainLayer.cpp -o $(BUILD)l3_DomainLayer.o

$(BUILD)l4_InfrastructureLayer.o: src/l4_InfrastructureLayer.cpp include/hw/l4_InfrastructureLayer.h
	$(COMPILE) $(SRC)l4_InfrastructureLayer.cpp -o $(BUILD)l4_InfrastructureLayer.o

install:
	install $(TARGET) /usr/local/bin

uninstall:
	rm -rf /usr/local/bin/hw
