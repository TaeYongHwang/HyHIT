�˰��򿡼� ������ STL


#include < algorithm >
 - find ( first, last, val)
   -> last�� �ձ��� ã�´�.
ex)
 vector< int >::iterator FindIter;
 FindIter = find( CharItems.begin(), CharItems.end(), 12 );
 
 - for_each ( first, last, func)
   -> �����͸� �Լ��� �Ķ���ͷ� �Ѱܼ� �Լ��� �����Ŵ.

ex)
  for_each( Users.begin() + 1, Users.end(), updatePlayTime );

next_permutation, prev_permutation
  ->���� �������� ����, ���� ���� ���ϰ� TF��ȯ

ex)
 next_permutation(v.begin(), v.end());

mix(), max()

sort (start, end) : [start,end]
ex)
 sort(v.begin(), v.end());
 


2. #include <vector>
- https://hyeonstorage.tistory.com/324
vector<int> v;
v.push_back();
_ v.pop_back();

3. #include <utility>
https://wootool.tistory.com/55
pair < int, int > p1;
  p1 = make_pair(10,20);
pair < int, int > p2(30,40);
first, second�� ���ٰ���.


4. #include <string>
 - str1.size(); == str1.length();
 - str1.substr(...);

5. #include <limits>
 - std :: numeric_limits< long long > ::min();
 - std :: numeric_limits<int>::max()
