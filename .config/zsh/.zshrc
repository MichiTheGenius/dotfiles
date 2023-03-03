# Lines configured by zsh-newuser-install

ZDOTDIR=$HOME/.config/zsh/

source $HOME/.config/zsh/pfetch_conf.sh
source $HOME/.config/zsh/aliases.sh

export PATH=$HOME/.local/bin:$PATH

autoload -U colors && colors
PS1="%B%{$fg[red]%}[%{$fg[yellow]%}%n%{$fg[green]%}@%{$fg[blue]%}%M %{$fg[magenta]%}%~%{$fg[red]%}]%{$reset_color%}$%b "

HISTFILE=$HOME/.config/zsh/.zsh_history
HISTSIZE=1000
SAVEHIST=1000

bindkey -e
# Basic auto/tab complete:
autoload -U compinit
zstyle ':completion:*' menu select
zmodload zsh/complist
compinit
_comp_options+=(globdots)		# Include hidden files.

autoload -Uz compinit
compinit


# enable starship.rs prompt
eval "$(starship init zsh)"

# Load zsh plugins; should be last.
source /usr/share/zsh/plugins/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh
source /usr/share/zsh/plugins/zsh-autosuggestions/zsh-autosuggestions.zsh
source /usr/share/zsh/plugins/zsh-fzf-history-search/zsh-fzf-history-search.zsh
