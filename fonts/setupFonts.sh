#!/bin/bash

# the first command line argument is the font we want
FONT=$1
INSTALL_PATH="/usr/share/fonts"

if [ $FONT = "jet" ]
then
	echo "installing JetBrainsMono NerdFont to $INSTALL_PATH"
	sudo cp -r JetBrainsNerd/ $INSTALL_PATH
fi

if [ $FONT = "hack" ]
then
	echo "installing Hack NerdFont to $INSTALL_PATH"
	sudo cp -r HackNerdFont/ $INSTALL_PATH
fi

if [ $FONT = "cascadia" ]
then
	echo "installing CascadiaCode NerdFont to $INSTALL_PATH"
	sudo cp -r CascadiaNF/ $INSTALL_PATH
fi
sudo fc-cache -f

echo "find the font with the 'fc-list | grep FONT_NAME' command"
