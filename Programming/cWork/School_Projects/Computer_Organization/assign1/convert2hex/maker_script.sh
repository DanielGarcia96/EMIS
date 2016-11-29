#!/bin/bash

rm output_hex
echo -e "1. 314156\n" >> output_hex
./convert2hex 314156 >> output_hex
echo >> output_hex
echo -e "2. 2147483647\n" >> output_hex
./convert2hex 2147483647 >> output_hex
echo >> output_hex
echo -e "3. 11806310474565\n" >> output_hex
./convert2hex 11806310474565 >> output_hex
echo >> output_hex
echo -e "4. 8526495043095935640\n" >> output_hex
./convert2hex 8526495043095935640 >> output_hex
