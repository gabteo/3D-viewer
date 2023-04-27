CC = g++
CFLAGS = -Wall
GLLIBS = -lglut -lGLEW -lGL -lGLU 
FILES = /lib/utils.cpp mesh.cpp input.cpp colors.cpp gutils.cpp shadersUtils.cpp logging.cpp
OBJFILES = mesh.o input.o colors.o gutils.o shadersUtils.o window.o logging.o
TARGET = mesh
LIBUTILS = lib/utils.cpp

mesh : $(OBJFILES) 
	@echo "Linking mesh..."
	$(CC) -o mesh $(OBJFILES) $(GLLIBS)
	@echo "Done!\n"

mesh.o: src/mesh.cpp
	@echo "Compiling $@..."
	$(CC) -c src/mesh.cpp $(LIBUTILS)
	@echo "Done!\n"

input.o: src/input.cpp
	@echo "Compiling $@..."
	$(CC) -c src/input.cpp $(LIBUTILS)
	@echo "Done!\n"

colors.o: src/colors.cpp
	@echo "Compiling $@..."
	$(CC) -c src/colors.cpp $(LIBUTILS)
	@echo "Done!\n"

gutils.o: src/gutils.cpp
	@echo "Compiling $@..."
	$(CC) -c src/gutils.cpp $(LIBUTILS)
	@echo "Done!\n"

shadersUtils.o: src/shadersUtils.cpp
	@echo "Compiling $@..."
	$(CC) -c src/shadersUtils.cpp $(LIBUTILS)
	@echo "Done!\n"

window.o: src/window.cpp
	@echo "Compiling $@..."
	$(CC) -c src/window.cpp $(LIBUTILS)
	@echo "Done!\n"

logging.o: src/logging.cpp
	@echo "Compiling $@..."
	$(CC) -c src/logging.cpp $(LIBUTILS)
	@echo "Done!\n"

clean:
	rm -f mesh *.o 
