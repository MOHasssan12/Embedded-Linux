#!/bin/bash

username="$1"
groupname="$2"


if id "$username" &>/dev/null; then # &> redirect output of id to null and not appear on the terminal 
    echo "User '$username' already exists."
else

    sudo adduser  "$username"
    echo "User '$username' created."
fi


if grep  "^$groupname:" /etc/group; then
    echo "Group '$groupname' already exists."
else
 
    sudo groupadd "$groupname"
    echo "Group '$groupname' created."
fi


sudo usermod -aG "$groupname" "$username"

echo "User Information:"
id "$username"

echo "Group Information:"
getent group "$groupname"
