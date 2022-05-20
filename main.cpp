#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol31;

/*
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

tuple<vector<int>, vector<int>>
testFixture1()
{
  auto input = vector<int>{1, 2, 3};
  auto output = vector<int>{1, 3, 2};
  return make_tuple(input, output);
}

tuple<vector<int>, vector<int>>
testFixture2()
{
  auto input = vector<int>{3, 2, 1};
  auto output = vector<int>{1, 2, 3};
  return make_tuple(input, output);
}

tuple<vector<int>, vector<int>>
testFixture3()
{
  auto input = vector<int>{1, 1, 5};
  auto output = vector<int>{1, 5, 1};
  return make_tuple(input, output);
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see: " << Util::toString(get<1>(f)) << endl;
  Solution sol;
  auto input = get<0>(f);
  sol.findNext(input);
  cout << Util::toString(input) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Expect to see: " << Util::toString(get<1>(f)) << endl;
  Solution sol;
  auto input = get<0>(f);
  sol.findNext(input);
  cout << Util::toString(input) << endl;
}

void test3()
{
  auto f = testFixture3();
  cout << "Expect to see: " << Util::toString(get<1>(f)) << endl;
  Solution sol;
  auto input = get<0>(f);
  sol.findNext(input);
  cout << Util::toString(input) << endl;
}

main()
{
  test1();
  test2();
  test3();
  return 0;
}