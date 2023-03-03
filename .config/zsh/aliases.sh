#!/usr/bin/zsh

# uncomment to use doas instead of sudo
#alias sudo="doas "
#alias doas="doas "
alias sudo="sudo "

alias ls="exa -laF --sort name"
alias cat="bat -p"
alias ..="cd .."
alias grep="grep --color=auto"
alias pac="sudo pacman"
alias clean="yay -Scc && sudo pacman -Scc && (pacman -Qtdq | sudo pacman -Rns -)"
alias src="source $HOME/.zshrc"

alias libreddit="libreddit & disown"
alias vim="nvim"
alias comp="sudo rm config.h && sudo make install"
alias pipes="pipes.sh -p 20 -f 60 -r 0 -R"
alias news="newsboat"

alias coding="cd /media/michael/Data/coding/"
alias data="cd /media/michael/Data/"

pfetch | lolcat
