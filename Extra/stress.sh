#make a A gen || exit 1
comp_flags a || exit 1
comp_flags A || exit 1
comp_flags gen || exit 1
for ((i = 1; ; i++)) do
	./gen $i > in
	./a < in > out
	./A < in > out2
	if (! cmp -s out out2) then
		echo "--> entrada:"
		cat in
		echo "--> saida1:"
		cat out
		echo "--> saida2:"
		cat out2
		break;
	fi
	echo $i
done
