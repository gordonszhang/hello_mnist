CC=g++
CFLAGS=-g
ifeq ("$(shell uname)", "Darwin")
  LDFLAGS     = -framework Foundation -framework GLUT -framework OpenGL -lm
else
  ifeq ("$(shell uname)", "Linux")
    LDFLAGS   = -L /usr/lib64/ -lglut -lGL -lGLU -lm
  endif
endif

OBJS=\
	imgview.o\
	mnist_parser.o\
	image.o
EXEC=\
	imgview

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: imgview

imgview: imgview.o image.o mnist_parser.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -rf $(OBJS)
	rm -rf $(EXEC)