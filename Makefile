CC = g++ 
CFLAGS = -Wall
LDFLAGS = -lm -L./resource -Wl,-rpath,'$$ORIGIN/resource' -lGL -Lresource -lzlibstatic -lassimp
GLLIBS = -lglut -lGLEW -lGL -lGLU 
# -libassimp.so  -libassimp.so.5  -libassimp.so.5.2.5
FILES = mesh.cpp input.cpp colors.cpp gutils.cpp shadersUtils.cpp window.cpp logging.cpp utils.cpp
OBJFILES = mesh.o input.o colors.o gutils.o shadersUtils.o window.o logging.o utils.o
TARGET = mesh
#LIBUTILS = lib/utils.cpp

# Include directories
INC = -Iassimp/include
#LIB = -L./assimp/bin

deps := $(patsubst %.o,%.d,$(OBJFILES))
-include $(deps)
DEPFLAGS = -MMD -MF $(@:.o=.d)


all: mesh

mesh : $(OBJFILES) 
	@echo "Linking mesh..."
	$(CC) -o $@ $^ $(INC) $(LDFLAGS) $(GLLIBS) $(DEPFLAGS)
	@echo "Done!\n"

-include *.dep
$(OBJFILES):%.o:src/%.cpp 
	@g++ -MM -MF $(basename $@).dep $<
	@echo "Compiling $@..."
	$(CC) -c $< $(INC) $(LIB) $(GLLIBS) $(LDFLAGS) $(DEPFLAGS)
	


clean:
	rm -f mesh *.o *.d *.dep
