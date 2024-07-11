#!/bin/bash

BASHRC="$HOME/.bashrc"

if [ -f "$BASHRC" ]; then
    echo "export HELLO=\$HOSTNAME" >> "$BASHRC"
    echo "LOCAL=\$(whoami)" >> "$BASHRC"
    echo "export LOCAL" >> "$BASHRC"
fi

gnome-terminal &

#What Happens When the Terminal is Opened

#When the new terminal is opened:

#    The new terminal session will source the .bashrc file.
#    The environment variables HELLO and LOCAL will be set according to the values defined:
#        HELLO will have the value of the hostname of the machine.
#        LOCAL will have the value of the current user.
