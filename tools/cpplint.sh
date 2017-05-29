#/bin/sh
python ./tools/cpplint.py --filter=-whitespace/braces,-whitespace/newline,-whitespace/indent --linelength=120 --extensions=hpp,cpp  $1


