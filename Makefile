CFLAGS = -std=c++17 -O2
LDFLAGS = `pkg-config --static --libs glfw3` -lvulkan

a.out: main.cpp
	g++ $(CFLAGS) -o a.out main.cpp $(LDFLAGS)

.PHONY: test clean

test: a.out
	./a.out

clean:
	rm -f a.out