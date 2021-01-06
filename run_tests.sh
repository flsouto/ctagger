

while getopts ":o" o; do
  case $o in
    o)
      output=1
      ;;
    *)
      echo "invalid options";
      exit 1;
      ;;
  esac
done

shift $((OPTIND-1))

if [ "$1" ]; then
  list=("$1")
else
  list=(tests/*)
fi

for f in "${list[@]}"
do
  code=`cat tester.c | sed -e "s@{TEST_FILE}@$f@g"`
  echo "$code" > tester_tmp.c
  if [ -z $output ]; then
    gcc tester_tmp.c -I. && ./a.out > tester_output
  else
    gcc tester_tmp.c -I. && ./a.out
  fi
done

