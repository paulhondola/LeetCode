#include <iterator>
#include <vector>

using namespace std;

vector<vector<int>> flipAndInvertImage(vector<vector<int>> &image) {
  vector<vector<int>> result;

  // vector<int>::iterator it;
  // vector<int>::reverse_iterator rit;

  // reverse the image
  for (auto &it : image) {
    vector<int> row;
    for (auto rit = it.rbegin(); rit != it.rend(); ++rit)
      row.push_back(*rit);

    result.push_back(row);
  }

  // flip the image

  for (auto &it : result)
    for (auto &i : it)
      i ^= 1;

  return result;
}
