Dep = add/add_int.o sub/sub_int.o add/add_float.o sub/sub_float.o main.o
calc: $(Dep)
	gcc -o calc $(Dep)

%.o: %.c
	gcc -c $< -o $@ -I./add -I./sub

clean:
	rm -f $(Dep) calc