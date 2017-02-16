#!/bin/bash

ARGC=$#

if [ $ARGC -ne 1 ]
then
  echo 'usage: ./extract_assignments.bash tar_file_to_extract'
  exit
fi

dirname=${1//.zip//}

unzip $1 -d $dirname > /dev/null

cd $dirname

find . "*" 2>/dev/null | while read f
do
  userDir=${f//_attempt*//}
  userDir=${userDir//*_/}
  mkdir $userDir 2>/dev/null
  mv "$f" "$userDir" 2>/dev/null
done

for i in $(ls)
do
  hasArchive=true
  cd $i
  find . "*" 2>/dev/null | while read f
  do
    fileType=$(file "$f")
    if [[ $fileType == *"gzip compressed data"* ]]
    then
      # this could do both with tar xzf $f .....
      gunzip "$f"
      hasArchive=false
    elif [[ $fileType == *"Zip archive data"* ]]
    then
      unzip "$f" >/dev/null
      rm "$f"
      hasArchive=false
    fi
    if [[ $fileType == *"text"* ]]
    then
      grep -q "There is no student submission text data for this assignment." "$f"
      sub=$?
      grep -q "There are no student comments for this assignment." "$f"
      com=$?
      if [ $sub -eq 1 ]
      then
      awk '/Submission:/{flag=1;next}/Comments:/{flag=0}flag' "$f" > "readme.txt"
      fi
      if [ $com -eq 1 ]
      then
        awk '/Comments:/{flag=1;next}/Files:/{flag=0}flag' "$f" > "readme.txt"
      fi
      rm "$f"
    fi
  done
  if ( $hasArchive )
  then
    echo "$i does not have any archive files">../../log.err
  fi
  cd ..
done

for i in $(ls)
do
  cd $i
  find . "*" 2>/dev/null | while read f
  do
    fileType=$(file "$f")
    if [[ $fileType == *"POSIX tar archive"* ]]
    then
      tar xf "$f"
      rm "$f"
    fi
  done
  cd ..
done
