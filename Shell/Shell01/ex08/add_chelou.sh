echo $FT_NBR1 + $FT_NBR2 | sed 'y?\\\"\?\!/1234/' | tr "'" "0" | sed 'y/mrdoc/01234/' | xargs echo "obase=13;ibase=5;" | bc | sed 'y/0123456789/gtaoi luSnemf/'
