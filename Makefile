tarp:
	gdc -O -o tarp src/main.d src/commands/*.d
clean:
	rm tarp
install:
	mv tarp /usr/local/bin/
	mkdir -p /etc/tarp
	cp config/mirrors.toml /etc/tarp/
