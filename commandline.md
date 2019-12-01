## edit, view or execute last modified file with a single key-press

```text
f() { ls -lart;e="ls -tarp|grep -v /|tail -9";j=${e/9/1};g=${e/9/9|nl -nln};h=$(eval $j);eval $g;read -p "e|x|v|1..9 $(eval $j)?" -n 1 -r;case $REPLY in e) joe $h;;v)cat $h;;x) eval $h;;[1-9]) s=$(eval $g|egrep ^$REPLY) && touch "${s:7}" && f;;esac ; } 
```
