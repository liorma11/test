echo "//// my ls ////\n"
cd tests && ../ft_ls -Rla && cd ..
echo "\n//// system ls ////\n"
cd tests && ls -Rla && cd ..
