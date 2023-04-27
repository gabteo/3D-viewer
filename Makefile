CC = g++ 
CFLAGS = -Wall
LDFLAGS = -lm -L./resource -Wl,-rpath,'$$ORIGIN/resource' -lGL -Lresource -lzlibstatic -lassimp
GLLIBS = -lglut -lGLEW -lGL -lGLU 
# -libassimp.so  -libassimp.so.5  -libassimp.so.5.2.5
FILES = /lib/utils.cpp mesh.cpp input.cpp colors.cpp gutils.cpp shadersUtils.cpp window.cpp logging.cpp
OBJFILES = mesh.o input.o colors.o gutils.o shadersUtils.o window.o logging.o utils.o
TARGET = mesh
LIBUTILS = lib/utils.cpp

# Include directories
INC = -Iassimp/include
#LIB = -L./assimp/bin

mesh : $(OBJFILES) 
	@echo "Linking mesh..."
	$(CC) -o mesh  $(OBJFILES) $(INC) $(LDFLAGS) $(GLLIBS)  
	@echo "Done!\n"

mesh.o: src/mesh.cpp
	@echo "Compiling $@..."
	$(CC) -c src/mesh.cpp $(LIBUTILS) $(INC) $(LIB) $(GLLIBS) $(LDFLAGS)
	@echo "Done!\n"

input.o: src/input.cpp
	@echo "Compiling $@..."
	$(CC) -c src/input.cpp $(LIBUTILS) $(LDFLAGS)
	@echo "Done!\n"

colors.o: src/colors.cpp
	@echo "Compiling $@..."
	$(CC) -c src/colors.cpp $(LIBUTILS) $(LDFLAGS)
	@echo "Done!\n"

gutils.o: src/gutils.cpp
	@echo "Compiling $@..."
	$(CC) -c src/gutils.cpp $(LIBUTILS) $(LDFLAGS)
	@echo "Done!\n"

shadersUtils.o: src/shadersUtils.cpp
	@echo "Compiling $@..."
	$(CC) -c src/shadersUtils.cpp $(LIBUTILS) $(LDFLAGS)
	@echo "Done!\n"

window.o: src/window.cpp
	@echo "Compiling $@..."
	$(CC) -c src/window.cpp $(LIBUTILS) $(LDFLAGS)
	@echo "Done!\n"

logging.o: src/logging.cpp
	@echo "Compiling $@..."
	$(CC) -c src/logging.cpp $(LIBUTILS) $(LDFLAGS)
	@echo "Done!\n"

utils.o: 
	@echo "Compiling $@..."
	$(CC) -c /lib/utils.cpp 
	@echo "Done!\n"
	

clean:
	rm -f mesh *.o 
