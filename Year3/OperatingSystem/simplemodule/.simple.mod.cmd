savedcmd_/home/lam/Code/Year3/OperatingSystem/simplemodule/simple.mod := printf '%s\n'   simple.o | awk '!x[$$0]++ { print("/home/lam/Code/Year3/OperatingSystem/simplemodule/"$$0) }' > /home/lam/Code/Year3/OperatingSystem/simplemodule/simple.mod
