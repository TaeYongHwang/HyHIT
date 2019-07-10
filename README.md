알고리즘에서 유용한 STL


1. #include < algorithm >
- find ( first, last, val)
-> last의 앞까지 찾는다.
ex)
vector< int >::iterator FindIter;
FindIter = find( CharItems.begin(), CharItems.end(), 12 );
- for_each ( first, last, func)
-> 데이터를 함수의 파라미터로 넘겨서 함수를 실행시킴.

ex)
for_each( Users.begin() + 1, Users.end(), updatePlayTime );

* next_permutation, prev_permutation
->현재 수열에서 다음, 이전 순열 구하고 TF반환

* mix(), max()


ex)
next_permutation(v.begin(), v.end());

2. #include < vector >
- https://hyeonstorage.tistory.com/324
* vector<int> v;
* v.push_back();
_ v.pop_back();

3. #include < utility >
* https://wootool.tistory.com/55
* pair < int, int > p1;
p1 = make_pair(10,20);
* pair < int, int > p2(30,40);
* first, second로 접근가능.


4. #include < string >
- str1.size(); == str1.length();
- str1.substr(...);



