#!/bin/bash

cd usr/home

for i in $( ls )
do
  cd $i
  if [ -e ".bash_login" ]
  then
    echo $i "has bash_login"
    ex .bash_login < ../../../edit.ex
    grep /etc/walker .bash_login
    if [ $? -eq 1 ]
    then
      ex .bash_login < ../../../append.ex
    fi
  elif [ -e ".bash_profile" ]
  then
    echo $i "has bash_profile"
    ex .bash_profile < ../../../edit.ex
    grep /etc/walker .bash_profile
    if [ $? -eq 1 ]
    then
      `ex .bash_profile < ../../../append.ex`
    fi
  fi
  cd ..
done
