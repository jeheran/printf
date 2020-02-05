cat raw | grep "$1\"" > grepped

if [[ "$2" != "" ]]
then
	cat grepped | grep -v "$2" > grepped2
	cat grepped2 > grepped
fi

python3 exp.py
