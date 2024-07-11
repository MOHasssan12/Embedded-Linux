#!/bin/bash

echo "Hello from the file organizer"

read -p "Enter your directory path: " dirpath


mkdir -p "$dirpath/images"
mkdir -p "$dirpath/documents"
mkdir -p "$dirpath/others"


for file in "$dirpath"/*; do

    if [ -f "$file" ]; then

        ext="${file##*.}"
        
        if [[ "$ext" == "jpg" || "$ext" == "png" || "$ext" == "gif" ]]; then
            mv "$file" "$dirpath/images/"
        elif [[ "$ext" == "txt" || "$ext" == "doc" || "$ext" == "pdf" ]]; then
            mv "$file" "$dirpath/documents/"
        else
            mv "$file" "$dirpath/others/"
        fi
    fi
done

echo "Files have been organized."
