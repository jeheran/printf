echo "usage: sh run.sh [small]"

make -C ../

files="-g3 ../libftprintf.a"

if [ "$1" == "small" ]
then
	cmd="gcc $files main_small.c -w -o a.out"
else
	cmd="gcc $files main.c -w -o a.out"
fi

flag="-D DEBUG=1"
if [[ "$2" != "DEBUG" ]]
then
	flag="-D DEBUG=0"
fi

echo $cmd $flag
$cmd $flag 

./a.out
