all: tests.out

tests.out:
	g++ tests.cpp -o test1
	g++ test_heap.cpp -o test2
	g++ main.cpp -o test3
	
andTest: tests.out
	./test1
	./test2
	./test3

clean:
	rm tests.out
