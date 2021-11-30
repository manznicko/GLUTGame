EX=ex1 ex2 ex3 ex4 
all: $(EX)

#  Unix/Linux
%: %.c;gcc -Wall -O3 -o $@ $< -lglut -lGLU -lGL

#  OSX
#%: %.c;gcc -Wall -O3 -o $@ $< -framework GLUT -framework OpenGL

#  MinGW
# %: %.c;gcc -Wall -O3 -o $@ $< -lglut32cu -lglu32 -lopengl32

clean:
	rm -f $(EX)
