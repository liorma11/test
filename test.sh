echo "//// my ls ////\n"
cd tests && ../ft_ls -Rraltu && cd ..
./ft_ls -l  /dev/disk0s1
echo "\n//// system ls ////\n"
cd tests && ls -Rraltu && cd ..
ls -l /dev/disk0s1
