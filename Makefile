CC=g++
CFLAGS=--std=c++11
LDFLAGS=-pthread

all:\
simple_thread.exe

clean:
	rm -f ./*.o
	rm -f ./*.exe

%.o: %.cpp
	$(CC) -c -o $@ $^ $(CFLAGS)

%.exe: %.o
	$(CC) -o $@ $^ $(LDFLAGS)