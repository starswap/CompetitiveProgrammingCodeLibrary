# CompetitiveProgrammingCodeLibrary
Competitive Programming Code


- Think about number of states - too much recursion? - Use bottom up.
- Final check if memoised before trying
- Remember to & any arguments for memory especially for recursive.
- Check need for longs
- GDB:
``` 
    bt (backtrace call stack)
    p [varname] (variable)
    run < [filename]
```
- May be able to use deque instead of bst if only want max min and vals come in right order
- Input/output:
    - Use '\n' not endl to prevent buffering
    - ios_base::sync_with_stdio(false); - can't then mix C and C++ input/output
    - cin.tie(NULL); at the beginning - Prevents the "flushing of cout before cin accepts new input" (may not want this for interactive problems) 
