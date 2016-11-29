#!/bin/bash

rm output_base
echo -e "1. 23 314156\n" >> output_base
./convert2base 23 314156 >> output_base
echo >> output_base
echo -e "2. 2 2147483647\n" >> output_base
./convert2base 2 2147483647 >> output_base
echo >> output_base
echo -e "3. 31 11806310474565\n" >> output_base
./convert2base 31 11806310474565 >> output_base
echo >> output_base
echo -e "4. 36 8526495043095935640\n" >> output_base
./convert2base 36 8526495043095935640 >> output_base
