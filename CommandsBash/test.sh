#!/bin/bash

#ffmpeg -ss 3000 -i REC0004.WAV -t 900 -c copy REC0004Cut.WAV


mkdir ./videoMP4
mkdir ./videoMP4forTV

destiny=./videoMP4forTV

for file in /media/bartosz/9016-4EF8/DCIM/100MEDIA/*.AVI
do
    base_name=$(basename ${file})
    xbase=${file##*/}
    xpref=./videoMP4forTV/${xbase%.*}.mp4
    if [  ! -f ${xpref} ]
    then
        ffmpeg -i $file -vf scale=1920:1080 ${xpref}
    fi

    echo "hello $file ${xpref}";
done


read -p "Press any key to resume ..."
read -t 1 -p "I am going to wait for 5 seconds only ...
"
read -t 1 -p "I am going to wait for 4 seconds only ...
"
read -t 1 -p "I am going to wait for 3 seconds only ...
"
read -t 1 -p "I am going to wait for 2 seconds only ...
"
read -t 1 -p "I am going to wait for 1 seconds only ...
"
