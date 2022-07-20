#!/usr/bin/bash

# configure git
cp .gitconfig ~/
# create ssh directory if it does not exist
mkdir -p ~/.ssh

# configure the ssh keys for git

echo 'Name your ssh key file git_ssh'
ssh-keygen -t ed25519 -C "litzinger04@gmail.com"

# start ssh-agent
eval "$(ssh-agent -s)"

ssh-add ~/.ssh/git_ssh

# add the line to the file that it remembers the user
echo 'IdentityFile ~/.ssh/git_ssh' >> ~/.ssh/config