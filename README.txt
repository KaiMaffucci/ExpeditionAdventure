	--- README---

	
	The game is an open-world ASCII art game. It is currently in its first Alpha stage. 
You are a single player free to roam the world and pick your own destiny. 

There is nothing to do right now besides look around at the "natural" biomes so far, but it will be exciting in the future. 

Look in the TODO file for more info on what will/might be added in the future. 


	Anyone is free to take this and do what they want with it (for the most part; just take a quick peek at the LICENSE file). 

In matter of fact, I encourage and welcome any suggestions, code snippits, modifications, bug/mistake finds, tips and help. 

Modding, experimenting, discovering, and breaking the game should be a big part in the game. 

I am definitley new to github and all of that.
 So some things will probably seem not very professional to say the least.
This is one of my first coding projects on a larger scale, and my first one like this in C.


For some reading on how it works without reading the code, check out the DOCUMENTATION file.

But you will need to read the actual code to understand it all in-depth. 


	--- GETTING STARTED ---

In order to actually run the program there is a tiny bit of setup.
Just open terminal and install the ncurses library:

	sudo apt-get install ncurses

Then navigate to the directory within the "ExpeditionAdventure" folder called "code" and run the following command:

	gcc -o expeditionadventure main.c player.c map.c -lncurses

Now this will build a .o file in this directory. 
You can now run the program with:

	./expeditionadventure

In the code folder. 


	--- HOW TO PLAY ---

Right now all you can really do is use the arrow keys to navigate your "o" character through the standard ASCII world. 
Take a look around!