#!/bin/bash

ARGC=$#

if [ $ARGC -ne 1 ]
then
  echo 'usage: ./diagnose.bash file_to_inspect'
  exit
fi

if [ -x $1 ]
then
  echo "You may execute $1"
  exit
fi

dir=$(dirname $1)
last=$1

while [ ! -x $dir ]
do
  last=$dir
  #if [ ! -x $1 ]
  #then
  #  echo "$1 is not executable"
  #  exit
  #fi
  dir=$(dirname $dir)
done

echo `basename $last` "is not executable"
