tarp:
	gcc -o tarp ./main.c ./commands/*.c -lcurl -Wall
clean:
	rm tarp
install:
	mv tarp /usr/local/bin/
	mkdir -p /etc/tarp
	cp config/mirrors /etc/tarp/
