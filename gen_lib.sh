for file in $(find . -name *.c); do
	name=$(basename "${file%.c}")
	gcc -c $file -o out/obj/"$name".o -Iinclude
done

ar rcs ./out/libstr.a ./out/obj/*.o
