#!/bin/bash
file_name=$"list_of_files.lll"
#prepand_path=$"../../files/"
ls *.txt > $file_name
#sed -i.bak "s/^/${try}/" $file_name
amt=$(wc -l < $file_name)
sed  -i "1i ${amt}" $file_name