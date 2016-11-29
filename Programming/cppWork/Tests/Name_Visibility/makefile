CC =g++
CFLAGS =-std=c++11
WFLAGS =-Wall -g

all: inner_block.o namespaces.o using.o using_entire.o namespace_blocks.o static_automatic.o
	$(CC) $(CFLAGS) $(WFLAGS) -o inner_block inner_block.o
	$(CC) $(CFLAGS) $(WFLAGS) -o namespaces namespaces.o
	$(CC) $(CFLAGS) $(WFLAGS) -o using using.o
	$(CC) $(CFLAGS) $(WFLAGS) -o using_entire using_entire.o
	$(CC) $(CFLAGS) $(WFLAGS) -o namespace_blocks namespace_blocks.o
	$(CC) $(CFLAGS) $(WFLAGS) -o static_automatic static_automatic.o

inner_block: inner_block.o
	$(CC) $(CFLAGS) $(WFLAGS) -o inner_block inner_block.o
inner_block.o: inner_block.cpp
	$(CC) $(CFLAGS) $(WFLAGS) -c -o inner_block.o inner_block.cpp

namespaces: namespaces.o
	$(CC) $(CFLAGS) $(WFLAGS) -o namespaces namespaces.o
namespaces.o: namespaces.cpp
	$(CC) $(CFLAGS) $(WFLAGS) -c -o namespaces.o namespaces.cpp

using: using.o
	$(CC) $(CFLAGS) $(WFLAGS) -o using using.o
using.o: using.cpp
	$(CC) $(CFLAGS) $(WFLAGS) -c -o using.o using.cpp

using_entire: using_entire.o
	$(CC) $(CFLAGS) $(WFLAGS) -o using_entire using_entire.o
using_entire.o: using_entire.cpp
	$(CC) $(CFLAGS) $(WFLAGS) -c -o using_entire.o using_entire.cpp

namespace_blocks: namespace_blocks.o
	$(CC) $(CFLAGS) $(WFLAGS) -o namespace_blocks namespace_blocks.o
namespace_blocks.o: namespace_blocks.cpp
	$(CC) $(CFLAGS) $(WFLAGS) -c -o namespace_blocks.o namespace_blocks.cpp

static_automatic: static_automatic.o
	$(CC) $(CFLAGS) $(WFLAGS) -o static_automatic static_automatic.o
static_automatic.o: static_automatic.cpp
	$(CC) $(CFLAGS) $(WFLAGS) -c -o static_automatic.o static_automatic.cpp

clean:
	rm *.o
