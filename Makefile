tarp:
	gdc -static-libphobos -O -o tarp src/main.d src/commands/*.d
clean:
	rm tarp
install:
	mv tarp /usr/local/bin/
