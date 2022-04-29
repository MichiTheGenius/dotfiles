#!/usr/bin/bash

# update repositories and install neovim. curl is needed for getting vimPlug.
sudo pacman -Syu neovim curl

# create directories where init.vim will be stored.
mkdir -p ~/.config
mkdir -p ~/.config/nvim

cp ./init.vim ~/.config/nvim

# install vim plug.

sh -c 'curl -fLo "${XDG_DATA_HOME:-$HOME/.local/share}"/nvim/site/autoload/plug.vim --create-dirs \
       https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim'

echo 'run neovim with the "nvim" command and run ":PlugInstall" to install vimPlug.'
