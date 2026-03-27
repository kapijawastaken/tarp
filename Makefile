tarp:
	gdc -O -o tarp ./main.d ./commands/*.d
c:
	gcc -o tarp ./main.c
clean:
	rm tarp
install:
	mv tarp /usr/local/bin/
	mkdir -p /etc/tarp
	cp config/mirrors.toml /etc/tarp/
