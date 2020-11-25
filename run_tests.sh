for f in tests/*
do
  code=`cat tester.c | sed -e "s@{TEST_FILE}@$f@g"`
  echo "$code" > tester_tmp.c
  gcc tester_tmp.c && ./a.out
done

