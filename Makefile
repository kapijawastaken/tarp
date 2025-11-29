tarp:
	gdc -O -o tarp src/main.d src/commands/list.d src/commands/installpkg.d src/commands/removepkg.d
clean:
	rm tarp
