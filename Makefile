clang:
	clang -std=gnu23 -o tarp ./main.c ./commands/*.c -lcurl -Wall -Wextra -Wpedantic
gcc:
	gcc -std=gnu23 -o tarp ./main.c ./commands/*.c -lcurl -Wall -Wextra -Wpedantic
clean:
	rm tarp
install:
	mv tarp /usr/local/bin/
	mkdir -p /etc/tarp
	cp config/mirrors /etc/tarp/
