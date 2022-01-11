CFLAGS = -std=c++17 -O2
LDFLAGS = `pkg-config --static --libs glfw3` -lvulkan

a.out: *.cpp *.hpp
	g++ $(CFLAGS) -o a.out *.cpp $(LDFLAGS)

.PHONY: test clean

test: a.out
	./a.out

clean:
	rm -f a.out