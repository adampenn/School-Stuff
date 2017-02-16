last -R | cut -b1-9,23-46 | sort - > /tmp/"$$"
cut -d: -f1,5 --output-delimiter=" " /etc/passwd | sort - | join - /tmp/"$$"
