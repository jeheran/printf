echo "usage: sh run.sh [small]"

make -C ../

files="-g3 ../libftprintf.a"

if [ "$1" == "small" ]
then
	cmd="gcc $files main_small.c -w -o a.out"
else
	cmd="gcc $files main.c -w -o a.out"
fi

echo $cmd
$cmd

 ./a.out
