make re -C ../..
gcc check_return_value.c -L../.. -lhashtable  -iquote../../include
