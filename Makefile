
CC = g++ 
OPT =  -Wall -I/usr/include/glm -I.  -ggdb
LIBOPT = -lglut -lGL -lGLEW

all : viewer

viewer : viewer.o shader.o buffer.o vertexarray.o glutwrapper.o handlerbase.o menucreator.o mesh.o program.o trackball.o trackballhandler.o framebuffer.o texture.o Makefile
	$(CC) $(OPT) -o viewer viewer.o shader.o buffer.o vertexarray.o  glutwrapper.o handlerbase.o menucreator.o mesh.o program.o trackball.o trackballhandler.o framebuffer.o texture.o $(LIBOPT)

%.o: %.cpp *.h Makefile
	$(CC) $(OPT) -c -o $@ $< 

clean : 
	rm *.o viewer

