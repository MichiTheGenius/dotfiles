#!/usr/bin/bash

sudo apt update
sudo apt install git

# configure git

git config --global user.name "MichiTheGenius"
git config --global user.email "litzinger04@gmail.com"

cp .gitconfig ~/

# configure the ssh keys for git

echo 'Name your ssh key file git_ssh'
ssh-keygen -t ed25519 -C "litzinger04@gmail.com"

eval "$(ssh-agent -s)"

ssh-add ~/.ssh/git_ssh

echo 'IdentityFile ~/.ssh/git_ssh' >> ~/.ssh/config

echo 'eval "$(ssh-agent -s)"' >> ~/.bashrc
