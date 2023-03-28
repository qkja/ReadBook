dest=test
src=test.cc

$(dest):$(src)
	g++ -o $@ $^ -std=c++11

.PHONY:clean
clean:
	rm -f $(dest)
