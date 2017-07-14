CC=c++
CFLAGS=-std=c++11
LDFLAGS=-ltorrent-rasterbar -lboost_system -pthread -lssl -lcrypto

build: main.cc
	$(CC) $(CFLAGS) main.cc -o main $(LDFLAGS)

clean: main
	rm ./main

file: $(file)
	$(CC) $(CFLAGS) $(file) -o a.out $(LDFLAGS)
