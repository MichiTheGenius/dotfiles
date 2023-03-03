#!/usr/bin/zsh

# pfetch config
# Which information to display.
# NOTE: If 'ascii' will be used, it must come first.
# Default: first example below
# Valid: space separated string
#
# OFF by default: shell editor wm de palette
export PF_INFO="ascii os shell kernel wm cpu gpu uptime pkgs memory"

# A file to source before running pfetch.
# Default: unset
# Valid: A shell script
export PF_SOURCE=""

# Separator between info name and info data.
# Default: unset
# Valid: string
export PF_SEP=":"

export PF_ASCII="arch"
