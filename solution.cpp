#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
using namespace sol31;
using namespace std;

/*takeaways
  - looking from the back to detect where
    it doesn't maintain the descending order
    - this is to find out if we can swap a bigger
      a number from the back to create next
      greater permutation
    - look for the smallest among those that
      are larger than the one you want to swap
      to move further back
*/

void Solution::findNext(vector<int> &num)
{
  int n = num.size();

  for (auto i = n - 2; i >= 0; i--)
  {
    /* not in a descending order */
    if (num[i + 1] > num[i])
    {
      /* everything after num[i+1] should
         be in a descending order
         - find the smallest one that
           is bigger than num[i]
      */
      int j;
      for (j = n - 1; j >= i + 1; j--)
        if (num[j] > num[i])
          break;
      /* create a greater permutation */
      swap(num[i], num[j]);
      /* make sure it's the smallest and hence
         the smallest
      */
      reverse(begin(num) + i + 1, end(num));
      return;
    }
  }

  /* everything is in descending order,
     you can only return the smallest
     permutation
  */
  reverse(begin(num), end(num));
}