# colors
reset  := '\033[0m'
red    := '\033[1;31m'
green  := '\033[1;32m'
yellow := '\033[1;33m'
blue   := '\033[1;34m'

# alias b := build
# alias f := flash
# alias l := layout
# alias w := watch-layout

list:
    @just --list

# Setup submodule and link directories to submodules
init:
    #!/usr/bin/env bash
    git submodule update --init --recursive --recommend-shallow
    #stow -R -d {{justfile_directory()}}/qmk -t {{justfile_directory()}}/firmware .
    if [ "$(git config submodule.firmware.ignore)" != "all" ]; then
      git config submodule.firmware.ignore all
    fi
    if [ "$(qmk config user.qmk_home | cut -d '=' -f 2)" != "{{justfile_directory()}}/bastardkb-qmk" ]; then
      qmk config user.qmk_home="{{justfile_directory()}}/bastardbk-qmk"
    fi
